#include "draw.h"

void draw (Screen *buff) {
	int i, j;
	for (i = buff->height - 1; i >= 0 ; i--) {
		for (j = 0; j < buff->width; j++) {
			printf("%s", buff->rows[i].mixels[j].val);
		}
		putchar('\n');
	}
}
