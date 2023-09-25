#ifndef ITCH_S_H
#define ITCH_S_H

/* Copyright (c) 2023, Julia Desmazes. All rights reserved.
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial
 * 4.0 International License.
 *
 * This code is provided "as is" without any express or implied warranties. */

#include "type.h"

typedef struct __attribute__((__packed__)){
#include "gen/itch_msg_struct_head.h"
#include "gen/itch_msg_struct_inner.h"
}tv_itch5_s;

#endif // ITCH_S_H

