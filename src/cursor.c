#include "cursor.h"

#include <stdio.h>

void reset_cursor(void) {
	printf("\033[H");
}

void clear(void) {
	printf("\033[2J\033[H");
}
