#ifndef _DEFINES_H_
#define _DEFINES_H_

/* exit states */
#define E_SUCCESS 0
#define E_ERROR   1

/* game of life states */
#define GOL_UNDERPOPULATION 1
#define GOL_REPRODUCTION    3
#define GOL_OVERPOPULATION  4

/* game of life dimensions */
#define GOL_WIDTH  20
#define GOL_HEIGHT 10

/* game of life cells */
#include <stdbool.h>
typedef bool cell;
#define alive true
#define dead false

/* game of life symbols */
#define GOL_S_ALIVE '#'
#define GOL_S_DEAD  '.'

/* get index of dimension */
#define INDEX(i, d) (((i)+(d))%(d))

#endif /* _DEFINES_H_ */
