#ifndef THREESPACE_H
#define THREESPACE_H

#include "v_buff.h"
#include <stdlib.h>

#define DEPTH 100

typedef struct {
	int depth;
	Screen **slices;
} Space;

Space *new_Space (int width, int height, int depth);

#endif	// THREESPACE_H
