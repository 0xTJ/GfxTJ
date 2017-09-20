#include "shapes.h"

int quad_frame_m[4][2] = {
	{0, 1},
	{1, 2},
	{2, 3},
	{3, 0}
};

int quadpoly_frame_m[12][2] = {
	{0, 1},
	{1, 2},
	{2, 3},
	{3, 0},
	{0, 4},
	{1, 5},
	{2, 6},
	{3, 7},
	{4, 5},
	{5, 6},
	{6, 7},
	{7, 4}
};

Line *new_line (Coord *vertices[2]) {
	Line *this = malloc(sizeof(Line));
	int i;
	
	this->vert_num = 2;
	
	for (i = 0; i < 2; i++)
		this->vertices[i] = vertices[i];
	
	return this;
}

Quad *new_quad (Coord *vertices[4]) {
	
}

Quadpoly *new_quadpoly (Coord *vertices[8]) {
	
}

Quad_Frame *new_quad_frame (Coord *vertices[4]) {
	Quad_Frame *this = malloc(sizeof(Quad_Frame));
	int i;
	
	this->vert_num = 4;
	
	for (i = 0; i < 4; i++)
		this->vertices[i] = vertices[i];
	
	for (i = 0; i < 4; i++)
		this->edges[i] = new_line((Coord *[]){ this->vertices[quad_frame_m[i][0]], this->vertices[quad_frame_m[i][1]] });
	
	return this;
}

Quadpoly_Frame *new_quadpoly_frame (Coord *vertices[8	]) {
	Quadpoly_Frame *this = malloc(sizeof(Quadpoly_Frame));
	int i;
	
	this->vert_num = 8;
	
	for (i = 0; i < 8; i++)
		this->vertices[i] = vertices[i];
	
	for (i = 0; i < 12; i++)
		this->edges[i] = new_line((Coord *[]){ this->vertices[quadpoly_frame_m[i][0]], this->vertices[quadpoly_frame_m[i][1]] });
	
	return this;
}

Quadpoly_Box *new_quadpoly_box (Coord *vertices[8]) {
	
}
