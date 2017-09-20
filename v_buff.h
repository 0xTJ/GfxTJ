#ifndef V_BUFF_H
#define V_BUFF_H

#include <stdlib.h>

struct vbuff_mixel {
	char *val;
};

struct vbuff_row {
	struct vbuff_mixel *mixels;
};

struct vbuff_screen {
	int width;
	int height;
	struct vbuff_row *rows;
};

typedef struct vbuff_mixel Mixel;
typedef struct vbuff_screen Screen;

Screen new_Screen (int width, int height);
void set_Mixel (Screen vbuff, int x, int y, char *value);

#endif	// V_BUFF_H
