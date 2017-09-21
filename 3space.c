#include "3space.h"
#include "render.h"
#include "shapes.h"

Space *new_Space (int width, int height, int depth) {
	Space *this = malloc(sizeof(Space));
	int i;
	this->depth = depth;
	this->rendered_slices = malloc(depth * sizeof(Screen *));
	for (i = 0; i < depth; i++)
		this->rendered_slices[i] = new_Screen(width, height);
	
	this->obj_count = 0;
	this->objects = malloc(1 * sizeof(Object *));
	
	return this;
}

void erase_Space (Space *space) {
	int i;
	for (i = 0; i < space->depth; i++)
		erase(space->rendered_slices[i]);
}

void load_Object (Space *space, Object *object) {
	space->obj_count++;
	space->objects = realloc(space->objects, space->obj_count * sizeof(Object *));
	space->objects[space->obj_count - 1] = object;
}

void execute_Space (Space *space) {
	int i;
	for (i = 0; i < space->obj_count; i++)
		render3_Object(space, space->objects[i]);
}

void render3_Object (Space *space, Object *object) {
	int i, obj_count;
	if (object->comp_type_count) {
		for (i = 0; i < object->comp_type_count; i++)
			obj_count += object->component_types[i].count;
		for (i=0; i < obj_count; i++)
			render3_Object(space, object->comps_TMPNAME[i]);
	}
	else {
		switch (object->type) {
			case Line_:
				render3_Line(space, object, '█');
				break;
		}
	}
}

void render3_Line (Space *space, Object *line, char k) {
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
		set_Mixel3(space, round(x), round(y), round(z) + space->depth / 2, clr_from_num(k));
	}
}

void set_Mixel3(Space *space, int x, int y, int z, char *s) {
	space->rendered_slices[z]->rows[y].mixels[x].val = s;
}




