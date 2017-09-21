#include "v_buff.h"

Screen *new_Screen (int width, int height) {
	int i, j;
	Screen *this = malloc(sizeof(Screen));
	
	this->width = width;
	this->height = height;
	this->rows = malloc(this->height * sizeof(struct vbuff_row));
	
	for (i = 0; i < this->height; i++) {
		(this->rows + i)->mixels = malloc(this->width * sizeof(struct vbuff_mixel));
		for (j = 0; j < this->width; j++) {
			this->rows[i].mixels[j].val = " ";
		}
	}
	
	return this;
}

void set_Mixel (Screen *vbuff, int x, int y, char *value) {
	vbuff->rows[y].mixels[x].val = value;
}
