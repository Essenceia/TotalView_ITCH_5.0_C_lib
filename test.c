#include <stdio.h>
#include "file.h"
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define LINE_CNT 40000

int main (int argc, char **argv)
{
  	uint32_t n = LINE_CNT;
	char *fpath = NULL;
 	int c;
	FILE *fptr;


	while ((c = getopt (argc, argv, "n:f:")) != -1)
	{
		switch (c)
 		{
 		case 'n':
			n = (uint32_t)atoi(optarg);
			break;
 		case 'f':
			fpath = optarg;
 			break;
 		case '?':
			if (isprint (optopt))fprintf (stderr, "Unknown option `-%c'.\n", optopt);
			else fprintf (stderr,"Unknown option character `\\x%x'.\n",optopt);
				return 1;
		default: abort ();
 		}
	}

	if ( fpath == NULL ){
		fprintf(stderr, "Missing file path, option -f\n");
		return 1;
	}

	// open file
	fptr = fopen(fpath,"rb");
	if ( fptr != NULL ){
		read_bin_file(fptr, n);
		fclose(fptr);
	}else {
		fprintf(stderr,"File open failed\n");
		return 1;
	}
	return 0;
}

