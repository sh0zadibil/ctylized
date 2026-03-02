#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "func.h"

typedef unsigned char color_code; // 0 - 255

typedef struct {
    color_code r;
    color_code g;
    color_code b;
} rgb_t;

typedef enum {
    ANSI_RESET     = 0,
    ANSI_BOLD      = 1,
    ANSI_DIM       = 2,
    ANSI_ITALIC    = 3,
    ANSI_UNDERLINE = 4,
    ANSI_REVERSE   = 5,
    ANSI_BLINK     = 7,
    ANSI_STRIKE    = 9
} style_t;

#define RESET_CLR "\e[0m" // in the end to not continue the color

#endif