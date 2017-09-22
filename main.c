#include "render.h"
#include "v_buff.h"
#include "shapes.h"
#include "draw.h"
#include "3space.h"
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
	
	Object *qpf = new_quadpoly_frame(pcoords);
	Screen *v_buff = new_Screen(80, 24);
	Space *three_buff = new_Space(80, 24, 10);
	
	load_Object(three_buff, qpf);
	
	double roll = 0.0L;
	double pitch = -0.5L;
	double yaw = 0.0L;
	rotate_Object(qpf, roll, pitch, yaw);
	
	pitch = 0.0L;
	roll = 0.1L;
	yaw = 0.03L;
	
	while (1) {
		rotate_Object(qpf, roll, pitch, yaw);
		erase_Space(three_buff);
		execute_Space(three_buff);
		render_Space(v_buff, three_buff);
		draw(v_buff);
		erase(v_buff);
		
		usleep(20000);
	}
	
	while(1);
	return 0;
}
