#ifndef RENDER_H
#define RENDER_H

#include "shapes.h"

enum axis { X, Y, Z };

typedef double transfo_matrix[4][4];

void rotate_coord_once (Coord *coord, enum axis axis, double theta);
void rotate_coord (Coord **coord, double yaw, double pitch, double roll);
void rotate_object (Object *object, double roll, double pitch, double yaw);
void mult_matrix_coord (Coord *coord, transfo_matrix matrix);

#endif	// RENDER_H
