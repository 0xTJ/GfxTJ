#ifndef THREESPACE_H
#define THREESPACE_H

#include "v_buff.h"
#include "shapes.h"
#include <stdlib.h>

#define DEPTH 100

typedef struct {
	int obj_count;
	Object **objects;
	int depth;
	Screen **rendered_slices;
} Space;

Space *new_Space (int width, int height, int depth);
void erase_Space (Space *space);
void load_Object (Space *space, Object *object);
void execute_Space (Space *space);
void render3_Object (Space *space, Object *object);
void render3_Line (Space *space, Object *line, char k);
void set_Mixel3(Space *space, int x, int y, int z, char *s);

#endif	// THREESPACE_H
