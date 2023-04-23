#include "gameoflife.h"
#include "defines.h"

#include <stdio.h>

void gol_draw(cell board[GOL_HEIGHT][GOL_WIDTH]) {
	int row;
	int col;
	char curr_cell;

	for (row = 0; row < GOL_HEIGHT; row++) {
		for (col = 0; col < GOL_WIDTH; col++) {
			if (board[row][col] == alive) curr_cell = GOL_S_ALIVE;
			if (board[row][col] ==  dead) curr_cell = GOL_S_DEAD;

			printf("%c ", curr_cell);
		}
		printf("\n");
	}
}

void gol_count_neighbours(cell board[GOL_HEIGHT][GOL_WIDTH], int neighbours[GOL_HEIGHT][GOL_WIDTH]) {
	int row;
	int col;
	int count;

	for (row = 0; row < GOL_HEIGHT; row++) {
		for (col = 0; col < GOL_WIDTH; col++) {
			count = 0;
			count += board[INDEX(row+1, GOL_HEIGHT)][INDEX(col-1, GOL_WIDTH)]; /* bottom left */
			count += board[INDEX(row+1, GOL_HEIGHT)][INDEX(col  , GOL_WIDTH)]; /* bottom mid */
			count += board[INDEX(row+1, GOL_HEIGHT)][INDEX(col+1, GOL_WIDTH)]; /* bottom right */
			count += board[INDEX(row-1, GOL_HEIGHT)][INDEX(col-1, GOL_WIDTH)]; /* top left */
			count += board[INDEX(row-1, GOL_HEIGHT)][INDEX(col  , GOL_WIDTH)]; /* top mid */
			count += board[INDEX(row-1, GOL_HEIGHT)][INDEX(col+1, GOL_WIDTH)]; /* top right */
			count += board[INDEX(row, GOL_HEIGHT)][INDEX(col-1, GOL_WIDTH)]; /* mid left */
			count += board[INDEX(row, GOL_HEIGHT)][INDEX(col+1, GOL_WIDTH)]; /* mid right */

			neighbours[row][col] = count;
		}
	}
}

void gol_set_board(cell board[GOL_HEIGHT][GOL_WIDTH], int neighbours[GOL_HEIGHT][GOL_WIDTH]) {
	int row;
	int col;

	for (row = 0; row < GOL_HEIGHT; row++) {
		for (col = 0; col < GOL_WIDTH; col++) {
			int n = neighbours[row][col];
			if (n <= GOL_UNDERPOPULATION) board[row][col] = dead;
			if (n >= GOL_OVERPOPULATION) board[row][col] = dead;
			if (n == GOL_REPRODUCTION) board[row][col] = alive;
		}
	}
}
