/* Copyright (c) 2023, Julia Desmazes. All rights reserved.
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial
 * 4.0 International License.
 *
 * This code is provided "as is" without any express or implied warranties. */

#include "file.h"
#include <stdio.h>
#define _BSD_SOURCE             /* See feature_test_macros(7) */
#include <endian.h>
#include "itch.h"

int read_bin_file(FILE *fptr, uint32_t n){
	uint32_t i;
	uint16_t len; // payload lenght ( big endian )
	char type; // itch message type
	char buff[ITCH_MSG_MAX_LEN];
	size_t ret;
	tv_itch5_s itch_msg;
	#ifdef DEBUG
	FILE *db_fptr;
	fpos_t db_save_pos;
	#endif// read
	for( i = 0; i < n; i++){
		
		ret = fread(&len, sizeof(len), 1, fptr);
		// convert to little endiant
		len = be16toh(len);
		
		#ifdef DEBUG
		db_fptr = fptr;
		fgetpos(db_fptr, &db_save_pos);
		fread(&buff, sizeof(char), len, db_fptr);
		printf("raw data :\n");
		for(int p=(int)len-1; p >-1; p--){
			printf("byte %02d %02hhx (%c)\n",p, buff[p], (isalpha(buff[p])? buff[p] : ' ')) ;
		}
		fsetpos(fptr, &db_save_pos); 
		#endif
		
		ret = fread(&type, sizeof(type), 1, fptr);
		if ( !ret ) return 1;	

		#ifdef DEBUG	
		printf("len %d,type %c, ret %ld\n", len, type,ret);
		#endif

		// read rest of message
		if ( len-1 > ITCH_MSG_MAX_LEN ) return 1;
		ret = fread(&buff, sizeof(char), len-1, fptr);
		if ( !ret ) return 1; 
		
		ret = (size_t)fill_tv_itch5( type, buff, len-1, &itch_msg);
		if ( ret ) return 1;
		
		#ifdef DEBUG
		print_tv_itch5(&itch_msg);
		#endif
		if ( feof( fptr ) )return 0;
	}
	return 0;
}


size_t get_next_bin_msg(FILE *fptr, uint8_t *buff, size_t buff_len){
	size_t ret = 0; // next message size
	uint16_t len;

	#ifdef FPOS
	long int pos = ftell(fptr);
	printf("fpos : %ld\n", pos);
	#endif

	fread(&len, sizeof(len),1, fptr);
	len = be16toh(len);// convert from big endian to whatever we are using
	if ( len <= buff_len ){
		ret = fread(buff, sizeof(uint8_t), len, fptr);
	}else{
	fprintf(stderr, "unexpected buffer length, got %d, max accepted %ld\n", len, buff_len);
	}
	#ifdef DEBUG
	printf("get_next_bin_msg len %ld, buff_len %ld\n", len, buff_len);
	assert(len <= buff_len);
	printf("raw data :\n");
	for(int i=(int)len-1; i >-1; i--){
		printf("byte %d %#x\n",i, ((char*)buff)[i]);
	}
	printf("\n");
	#endif // DEBUG

	return ret; 
}
