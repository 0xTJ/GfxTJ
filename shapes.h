#ifndef shapes_H
#define shapes_H

#include <stdlib.h>

// TODO: Check all malloc for success
typedef struct {
	double x;
	double y;
	double z;
} Coord;

typedef struct {
	int vert_num;
	Coord **vertices;
} Object;	// Generic object

typedef struct {
	int vert_num;
	Coord *vertices[2];
} Line;

typedef struct quad {
	int vert_num;
	Coord *vertices[4];
} Quad;

typedef struct quadpoly {
	int vert_num;
	Coord *vertices[8];
} Quadpoly;

typedef struct quad_frame {
	int vert_num;
	Coord *vertices[4];
	Line *edges[4];
} Quad_Frame;

typedef struct quadpoly_frame {
	int vert_num;
	Coord *vertices[8];
	Line *edges[12];
} Quadpoly_Frame;

typedef struct quadpoly_box {
	int vert_num;
	Coord *vertices[8];
	Quad *faces[6];
} Quadpoly_Box;

// Basic Shapes
Line *new_line (Coord *vertices[2]);
Quad *new_quad (Coord *vertices[4]);
Quadpoly *new_quadpoly (Coord *vertices[8]);

// Wireframes
Quad_Frame *new_quad_frame (Coord *vertices[4]);
Quadpoly_Frame *new_quadpoly_frame (Coord *vertices[8]);

// Hollow Boxes
Quadpoly_Box *new_quadpoly_box (Coord *vertices[8]);

extern int quad_frame_m[4][2];
extern int quadpoly_frame_m[12][2];
extern int quadpoly_box_m[6][4];

#endif	// shapes_H
