#include "shapes.h"

Object *new_line (Coord *vertices[2]) {
	Object *this = malloc(sizeof(Object));
	int i;
	
	this->vert_num = 2;
	this->vertices = malloc(this->vert_num * sizeof(Coord *));
	for (i = 0; i < 2; i++)
		this->vertices[i] = vertices[i];
	
	this->comp_type_count = 0;
	
	return this;
}

Object *new_quad (Coord *vertices[4]) {
	
}

Object *new_quadpoly (Coord *vertices[8]) {
	
}

Object *new_quad_frame (Coord *vertices[4]) {
	Object *this = malloc(sizeof(Object));
	int i;
	int map[4][2] = {
		{0, 1},
		{1, 2},
		{2, 3},
		{3, 0}
	};
	
	this->vert_num = 4;
	this->vertices = malloc(this->vert_num * sizeof(Coord *));
	for (i = 0; i < 4; i++)
		this->vertices[i] = vertices[i];
	
	this->comp_type_count = 1;
	this->component_types = malloc(this->comp_type_count * sizeof(struct component));
	this->component_types[0].type = Line_;
	this->component_types[0].count = 4;
	
	for (i = 0; i < this->component_types[0].count; i++)
		this->comps_TMPNAME[i] = new_line((Coord *[]){ this->vertices[map[i][0]], this->vertices[map[i][1]] });

	return this;
}

Object *new_quadpoly_frame (Coord *vertices[8]) {
	Object *this = malloc(sizeof(Object));
	int i;
	int map[12][2] = {
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
	
	this->vert_num = 8;
	this->vertices = malloc(this->vert_num * sizeof(Coord *));
	for (i = 0; i < 8; i++)
		this->vertices[i] = vertices[i];
	
	this->comp_type_count = 1;
	this->component_types = malloc(this->comp_type_count * sizeof(struct component));
	this->component_types[0].type = Line_;
	this->component_types[0].count = 12;
	
	this->comps_TMPNAME = malloc(this->component_types[0].count * sizeof(Object));
	for (i = 0; i < this->component_types[0].count; i++)
		this->comps_TMPNAME[i] = new_line((Coord *[]){ this->vertices[map[i][0]], this->vertices[map[i][1]] });
	
	return this;
}

Object *new_quadpoly_box (Coord *vertices[8]) {
	
}

int count_comps (struct component *component_types) {
	if (component_types->count > 0)
	;
}
