#ifndef FILE_H
#define FILE_H

/* Copyright (c) 2023, Julia Desmazes. All rights reserved.
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial
 * 4.0 International License.
 *
 * This code is provided "as is" without any express or implied warranties. */

#include <stdint.h>
#include <stdio.h>

#define ITCH_MSG_MAX_LEN 50 

// Read n itch messages from binary file 
// Used for testing
int read_bin_file(FILE* fptr, uint32_t n);

// Read the next binary message in the file into a buffer.
size_t get_next_bin_msg(FILE *fptr, uint8_t *buff, size_t buff_len);
#endif // FILE_H
