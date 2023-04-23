#ifndef _GAMEOFLIFE_H_
#define _GAMEOFLIFE_H_

#include "defines.h"

void gol_draw(cell board[GOL_HEIGHT][GOL_WIDTH]);
void gol_count_neighbours(cell board[GOL_HEIGHT][GOL_WIDTH], int neighbours[GOL_HEIGHT][GOL_WIDTH]);
void gol_set_board(cell board[GOL_HEIGHT][GOL_WIDTH], int neighbours[GOL_HEIGHT][GOL_WIDTH]);

#endif /* _GAMEOFLIFE_H_ */
