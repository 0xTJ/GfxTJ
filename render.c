#include "render.h"

void erase (Screen buff) {
	int i, j;
	for (i = buff.height - 1; i >= 0 ; i--) {
		for (j = 0; j < buff.width; j++) {
			buff.rows[i].mixels[j].val = " ";
		}
	}
}

void render_line (Screen buff, Line *line, char k) {
	int i;
	double t, x, y, z, delta_x, delta_y, delta_z;
	double *px1 = &line->vertices[0]->x;
	double *py1 = &line->vertices[0]->y;
	double *pz1 = &line->vertices[0]->z;
	double *px2 = &line->vertices[1]->x;
	double *py2 = &line->vertices[1]->y;
	double *pz2 = &line->vertices[1]->z;
	
	delta_x = (*px2 - *px1) / DOTSINLINE;
	delta_y = (*py2 - *py1) / DOTSINLINE;
	delta_z = (*pz2 - *pz1) / DOTSINLINE;
	for (i = 0; i <= DOTSINLINE; i++) {
		double x = *px1 + i * delta_x;	// TODO: unbreak fake 3d
		double y = *py1 + i * delta_y;
		double z = *pz1 + i * delta_z;
		x = 5 * x * ASPECT_FACTOR + 40;
		y = 5 * y + 12;
		set_Mixel(buff, round(x), round(y), clr_from_num(k));
	}
}

char *clr_from_num (char n) {
	switch (n % 8) {
		case 0:
			return KNRM"0";
			break;
		case 1:
			return KRED"0";
			break;
		case 2:
			return KGRN"0";
			break;
		case 3:
			return KYEL"0";
			break;
		case 4:
			return KBLU"0";
			break;
		case 5:
			return KMAG"0";
			break;
		case 6:
			return KCYN"0";
			break;
		case 7:
			return KWHT"0";
			break;
	}
}
