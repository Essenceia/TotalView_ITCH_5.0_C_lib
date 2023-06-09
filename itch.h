#ifndef ITCH_H
#define ITCH_H
#include "itch_s.h"
#include <stddef.h>

// fill the field of the itch structure corresponding to the
// message type
int  fill_tv_itch5(char msg_type, void* data, size_t data_len, tv_itch5_s *itch_s);

// print the currently valid itch message type
void print_tv_itch5_msg_type(const tv_itch5_s * itch_msg);

#endif // ITCH_H
