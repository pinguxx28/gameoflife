#include <time.h>
#include <unistd.h>
#include "defines.h"
#include "cursor.h"
#include "gameoflife.h"

cell board[GOL_HEIGHT][GOL_WIDTH] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,1,0,0,0 },
	{ 0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0 },
	{ 0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};

int neighbours[GOL_HEIGHT][GOL_WIDTH];

int main(void) {
	clear();

	while(true) {
		reset_cursor();
		gol_count_neighbours(board, neighbours);
		gol_set_board(board, neighbours);
		gol_draw(board);
		sleep(1);
	}

	return E_SUCCESS;
}
