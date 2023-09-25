/* Copyright (c) 2023, Julia Desmazes. All rights reserved.
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial
 * 4.0 International License.
 *
 * This code is provided "as is" without any express or implied warranties. */

#include "itch.h"
#include <stddef.h>
#include <assert.h>
#include <string.h>

int fill_tv_itch5(char msg_type, uint8_t* data, size_t data_len, tv_itch5_s *itch_s){
	// write all valid signals to 0		
	// valid signals are at the top of the struct, this is a packed struct
	// calculate the offset to the first data anonymous struct and use it to
	// get the last address of the valid signals
	size_t offset_first_anon; 
	size_t exp_len;
	offset_first_anon = offsetof( tv_itch5_s, itch_system_event_data );
	memset(itch_s,0,offset_first_anon); 


	#ifdef DEBUG
	printf("buffer data to fill itch struct  :\n");
	for(int p = (int)data_len-1; p >-1; p--){
		printf("byte %02d %02hhx (%c)\n",p, data[p], (isalpha(data[p])? data[p] : ' ')) ;
	}
	#endif	 
	
	switch( msg_type ){
		#include "gen/itch_msg_fill_case.h"
		default :
			fprintf(stderr,"Error : Unknown itch message type %c\n", msg_type);
			assert(0); 
			return 1;
			break;
	}
 
	if ( data_len != exp_len ){
		assert(0);
		return 1;
	}
	return 0;
}

void print_tv_itch5_msg_type(const tv_itch5_s * itch_msg){
	#include "gen/itch_msg_print_type.h"
}

void print_tv_itch5(const tv_itch5_s* itch_msg){
	printf("\n");
	#include "gen/itch_msg_print.h"
}

