#ifndef RENDER_H
#define RENDER_H

#include "shapes.h"
#include "v_buff.h"
#include "math.h"
#include <stdlib.h>

#define DOTSINLINE 100L
#define ASPECT_FACTOR (2.0L)

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

void erase (Screen *buff);
void render_line (Screen *buff, Line *line, char k);
char *clr_from_num (char n);

#endif	// RENDER_H
