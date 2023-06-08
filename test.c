#include <stdio.h>
#include "file.h"

#define ITCH_FILE "/home/pitchu/rtl/hft/tv/12302019.NASDAQ_ITCH50"
#define LINE_CNT 40000
int main() {
	FILE* fptr;
	// open file
	fptr = fopen(ITCH_FILE,"rb");
	if ( fptr != NULL ){
		read_bin_file(fptr, LINE_CNT);
		fclose(fptr);
	}else printf("File open failed\n");

	return 0;
}
