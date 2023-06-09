#include "file.h"
#include <stdio.h>
#define _BSD_SOURCE             /* See feature_test_macros(7) */
#include <endian.h>
#include "itch.h"

#define ITCH_MSG_MAX_LEN 50 
int read_bin_file(FILE *fptr, uint32_t n){
	uint32_t i;
	uint16_t len; // payload lenght ( big endian )
	char type; // itch message type
	char buff[ITCH_MSG_MAX_LEN];
	size_t ret;
	tv_itch5_s itch_msg;
	// read
	for( i = 0; i < n; i++){
		ret = fread(&len, sizeof(len), 1, fptr);
		// convert to little endiant
		len = be16toh(len);

		ret = fread(&type, sizeof(type), 1, fptr);
		if ( !ret ) return 1;	

		#ifdef DEBUF	
		printf("len %d,type %c, ret %ld\n", len, type,ret);
		#endif

		// read rest of message
		if ( len-1 > ITCH_MSG_MAX_LEN ) return 1;
		ret = fread(buff, sizeof(buff[0]), len-1, fptr);
		if ( !ret ) return 1; 

		ret = (size_t)fill_tv_itch5( type, buff, len-1, &itch_msg);
		if ( ret ) return 1;

		print_tv_itch5_msg_type(&itch_msg);
		if ( feof( fptr ) )return 0;
	}
	return 0;
}


size_t get_next_bin_msg(FILE *fptr, uint8_t *buff, size_t buff_len){
	size_t ret = 0; // next message size
	uint16_t len;
	fread(&len, sizeof(len),1, fptr);
	len = be16toh(len);// convert from big endian to whatever we are using
	if ( len <= buff_len ){
		ret = fread(buff, sizeof(uint8_t), len, fptr);
	}
	return ret; 
}
