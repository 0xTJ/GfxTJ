#include "render.h"

void erase (Screen *buff) {
	int i, j;
	for (i = buff->height - 1; i >= 0 ; i--) {
		for (j = 0; j < buff->width; j++) {
			buff->rows[i].mixels[j].val = " ";
		}
	}
}

void render_Space (Screen *buff, Space *space) {
	int i, j, k;
	for (i = 0; i < space->rendered_slices[0]->height; i++)
		for (j = 0; j < space->rendered_slices[0]->width; j++)
			for (k = 0; k < space->depth; k++)
				if (space->rendered_slices[k]->rows[i].mixels[j].val[0] != ' ') {
					//printf("Rending %d, %d, and %d to %c", i, j, k, space->rendered_slices[k]->rows[i].mixels[j].val);
					buff->rows[i].mixels[j] = space->rendered_slices[k]->rows[i].mixels[j];
				}
}

char *clr_from_num (char n) {	// TODO: REMOVE THIS
	switch (n % 8) {
		case 0:
			return KNRM"█";
			break;
		case 1:
			return KRED"█";
			break;
		case 2:
			return KGRN"█";
			break;
		case 3:
			return KYEL"█";
			break;
		case 4:
			return KBLU"█";
			break;
		case 5:
			return KMAG"█";
			break;
		case 6:
			return KCYN"█";
			break;
		case 7:
			return KWHT"█";
			break;
	}
}
