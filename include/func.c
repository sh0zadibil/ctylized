#include "func.h"

void sprintfcol(char* text, const rgb_t* fg, const rgb_t* bg, style_t* styles) {
	char s_fg[20] = "";
	char s_bg[20] = "";

	char styles_fixed[20] = "";

	if (styles != NULL) {
		strcat(styles_fixed, "\e[");
		size_t len = 0;

		while (styles[len] != ANSI_RESET) len++;
		
		for (int i = 0; i < len; i++) {
			char temp[3];
			snprintf(temp, sizeof(temp), "%d%c", styles[i], ';');
			strcat(styles_fixed, temp);
		}
	}
	styles_fixed[strlen(styles_fixed) - 1] = '\0';
		
	if (validcolor(fg)) {
		char buffer[20];
		snprintf(buffer, sizeof(buffer), "38;2;%hhu;%hhu;%hhu", fg->r, fg->g, fg->b);
		strcat(s_fg, buffer);
	}
	if (validcolor(bg)) {
		char buffer[20];
		snprintf(buffer, sizeof(buffer), "48;2;%hhu;%hhu;%hhu", bg->r, bg->g, bg->b);
		strcat(s_bg, buffer);
	}

    printf("\e[%s;%sm%sm%s%s", s_fg, s_bg, styles_fixed, text, RESET_CLR);
}

rgb_t* color(color_code r, color_code g, color_code b) {
	rgb_t* result = calloc(1, sizeof(rgb_t));
	result->r = r;
	result->g = g;
	result->b = b;
	return result;
	free(result);
}

bool validcolor(const rgb_t* col) {
	return (col != NULL);
}