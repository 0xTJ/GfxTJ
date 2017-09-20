#include "v_buff.h"

Screen new_Screen (int width, int height) {
	int i, j;
	Screen this;
	
	this.width = width;
	this.height = height;
	this.rows = malloc(sizeof(struct vbuff_row) * this.height);
	
	for (i = 0; i < this.height; i++) {
		this.rows[i].mixels = calloc(this.width, sizeof(struct vbuff_mixel));
		for (j = 0; j < this.width; j++) {
			this.rows[i].mixels[j].val = " ";
		}
	}
	
	return this;
}

void set_Mixel (Screen vbuff, int x, int y, char *value) {
	vbuff.rows[y].mixels[x].val = value;
}
