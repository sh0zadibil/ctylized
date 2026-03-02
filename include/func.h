#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifdef _WIN32
	#include <windows.h>
#else
	#define ansi_RESETCOL "\e[0m"

	#include "constants.h"
	
 	extern rgb_t* color(color_code r, color_code g, color_code b);

	extern void sprintfcol(char* text, const rgb_t* fg, const rgb_t* bg, style_t* styles);

	extern bool validcolor(const rgb_t* col);

#endif
#endif