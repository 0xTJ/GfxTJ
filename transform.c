#include "transform.h"
#include <math.h>
#include <string.h>

void rotate_coord_once (Coord *coord, enum axis axis, double theta) {
	transfo_matrix rot_matrix;
	if (axis == X)
		memcpy(rot_matrix, (transfo_matrix){
			{ 1, 0, 0, 0 },
			{ 0, cos(theta), -sin(theta), 0 },
			{ 0, sin(theta), cos(theta), 0 },
			{ 0, 0, 0, 1 }
		}, sizeof(transfo_matrix));
	else if (axis == Y)
		memcpy(rot_matrix, (transfo_matrix){
			{ cos(theta), 0, sin(theta), 0 },
			{ 0, 1, 0, 0 },
			{ -sin(theta),  0, cos(theta), 0 },
			{ 0, 0, 0, 1 }
		}, sizeof(transfo_matrix));
	else if (axis == Z)
		memcpy(rot_matrix, (transfo_matrix){
			{ cos(theta), -sin(theta), 0, 0 },
			{ sin(theta), cos(theta), 0, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 1 }
		}, sizeof(transfo_matrix));
	
	mult_matrix_coord(coord, rot_matrix);
}

void rotate_coord (Coord **coord, double roll, double pitch, double yaw) {
	if (roll != 0)
		rotate_coord_once((Coord*)coord, X, roll);
	if (pitch != 0)
		rotate_coord_once((Coord*)coord, Y, pitch);
	if (yaw != 0)
		rotate_coord_once((Coord*)coord, Z, yaw);
}

void rotate_object (Object *object, double roll, double pitch, double yaw) {
	int i, j;
	for (i = 0; i < object->vert_num; i++)
		rotate_coord((&object->vertices)[i], roll, pitch, yaw);
}

void mult_matrix_coord (Coord *coord, transfo_matrix rot_matrix) {
	Coord tmp = { coord->x, coord->y, coord->z };
	coord->x = rot_matrix[0][0] * tmp.x + rot_matrix[0][1] * tmp.y + rot_matrix[0][2] * tmp.z + rot_matrix[0][3] * 1;
	coord->y = rot_matrix[1][0] * tmp.x + rot_matrix[1][1] * tmp.y + rot_matrix[1][2] * tmp.z + rot_matrix[1][3] * 1;
	coord->z = rot_matrix[2][0] * tmp.x + rot_matrix[2][1] * tmp.y + rot_matrix[2][2] * tmp.z + rot_matrix[2][3] * 1;
}
