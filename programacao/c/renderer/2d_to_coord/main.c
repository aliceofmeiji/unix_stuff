#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "2d_to_coord.h"

int main(int argc, char *argv[])
{
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	char color[8];
	Line line;
	while(scanf("%d %d %d %d %s", &x1, &y1, &x2, &y2, color) != EOF)
	{
		//printf("%d %d %d %d %s\n", x1, y1, x2, y2, color);
		line = make_line(x1, y1, x2, y2, color);
		print_line(line);
	}
}
