#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "3d_to_2d.h"

int main(int argc, char *argv[])
{
	if(argc != 10)
		return 1;

	int x1, y1, z1, x2, y2, z2;
	char color[] = "00000000";
	Line3 iline;
	Line2 oline;
	Point3 	scr_start = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3])}, 
		scr_end   = {atoi(argv[4]), atoi(argv[5]), atoi(argv[6])}, 
		focus     = {atoi(argv[7]), atoi(argv[8]), atoi(argv[9])}; 
	
	while(scanf("%d %d %d %d %d %d %s", &x1, &y1, &z1, &x2, &y2, &z2, color) != EOF)
	{
		//printf("%d %d %d %d %d %d %s\n", x1, y1, z1, x2, y2, z2, color);
		iline = (Line3){x1, y1, z1, x2, y2, z2, color};
		oline = to_2d_line(iline, scr_start, scr_end, focus);
		printf("%d %d %d %d %s\n", oline.start.x, oline.start.y, oline.end.x, oline.end.y, oline.color);
	}
	
}

