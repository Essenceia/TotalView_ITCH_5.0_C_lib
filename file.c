#include "file.h"
#include <stdio.h>
#include <byteswap.h>
#include "itch.h"

int read_bin_file(FILE *fptr, uint32_t n){
	uint32_t i;
	uint16_t len; // payload lenght ( big endian )
	char type; // itch message type
	char buff[50];
	size_t ret;
	tv_itch5_s itch_msg;
	// read
	for( i = 0; i < n; i++){
		ret = fread(&len, sizeof(len), 1, fptr);
		// convert to little endiant
		len = bswap_16(len);
		ret = fread(&type, sizeof(type), 1, fptr);
		
		printf("len %d,type %c, ret %ld\n", len, type,ret);
		// read rest of message
		ret = fread(buff, sizeof(buff[0]), len-1, fptr);
		fill_tv_itch5( type, buff, len-1, &itch_msg);
		print_tv_itch5_msg_type(&itch_msg);	
	}
	return 0;
}
