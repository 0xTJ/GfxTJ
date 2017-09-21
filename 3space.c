#include "3space.h"

Space *new_Space (int width, int height, int depth) {
	Space *this = malloc(sizeof(Space));
	int i;
	this->depth = depth;
	this->slices = malloc(depth * sizeof(Screen *));
	for (i = 0; i < depth; i++)
		this->slices[i] = new_Screen(width, height);
}
