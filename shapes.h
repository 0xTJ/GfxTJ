#ifndef shapes_H
#define shapes_H

#include <stdlib.h>

enum shape { Line_, Quad_, Box_ };

struct component {
	enum shape type;
	int count;
};

// TODO: Check all malloc for success
typedef struct {
	double x;
	double y;
	double z;
} Coord;

struct object;
struct object {
	enum shape type;
	int vert_num;
	Coord **vertices;
	int comp_type_count;
	struct component *component_types;
	struct object **comps_TMPNAME;
};
typedef struct object Object;

// Basic Shapes
Object *new_line (Coord *vertices[2]);
Object *new_quad (Coord *vertices[4]);
Object *new_quadpoly (Coord *vertices[8]);

// Wireframes
Object *new_quad_frame (Coord *vertices[4]);
Object *new_quadpoly_frame (Coord *vertices[8]);

// Hollow Boxes
Object *new_quadpoly_box (Coord *vertices[8]);

#endif	// shapes_H
