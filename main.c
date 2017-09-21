#include "v_buff.h"
#include "shapes.h"
#include "draw.h"
#include "render.h"
#include "transform.h"
#include <math.h>
#include <unistd.h>

int main (void) {
	int i;
	
	Coord coords[8];
	coords[0] = (Coord){ 1, 1, 1 };
	coords[1] = (Coord){ 1, -1, 1 };
	coords[2] = (Coord){ -1, -1, 1 };
	coords[3] = (Coord){ -1, 1, 1 };
	coords[4] = (Coord){ 1, 1, -1 };
	coords[5] = (Coord){ 1, -1, -1 };
	coords[6] = (Coord){ -1, -1, -1 };
	coords[7] = (Coord){ -1, 1, -1 };
	
	Coord *pcoords[8];
	for (i = 0; i < 8; i++)
		pcoords[i] = &coords[i];
	
	Quadpoly_Frame *qpf = new_quadpoly_frame(pcoords);
	
	Screen *v_buff2 = new_Screen(80, 24);
	double roll = 0.0L;
	double pitch = -0.5L;
	double yaw = 0.0L;
	rotate_object(qpf, roll, pitch, yaw);
	for (i = 0; i < 12; i++) {
		double x1 = qpf->edges[i]->vertices[0]->x;
		double y1 = qpf->edges[i]->vertices[0]->y;
		double x2 = qpf->edges[i]->vertices[1]->x;
		double y2 = qpf->edges[i]->vertices[1]->y;
		render_line(v_buff2, qpf->edges[i], i);
	}
	draw(v_buff2);
	erase(v_buff2);
	
	pitch = 0.0L;
	roll = 0.01L;
	yaw = 0.003L;
	
	while (1) {
		rotate_object(qpf, roll, pitch, yaw);
		for (i = 0; i < 12; i++) {
			double x1 = qpf->edges[i]->vertices[0]->x;
			double y1 = qpf->edges[i]->vertices[0]->y;
			double x2 = qpf->edges[i]->vertices[1]->x;
			double y2 = qpf->edges[i]->vertices[1]->y;
			render_line(v_buff2, qpf->edges[i], i);
		}
		draw(v_buff2);
		erase(v_buff2);
		
		usleep(20000);
	}
	
	while(1);
	return 0;
}
