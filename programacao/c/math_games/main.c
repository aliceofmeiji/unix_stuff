#include <stdlib.h>
#include <stdio.h>
#include "math_games.h"

int main()
{
	int ysize = 600, xsize = 600, i, j, ncols = 12, nlines = 5;
	char c, *map = malloc(ncols * nlines);

	gfx_open(xsize, ysize, "math_games");

	while(1) {

		draw_map(map, ncols, nlines, xsize, ysize);

		c = gfx_wait();
		read_input(map, ncols, nlines, xsize, ysize, c);

		if(c=='q') break;
	}

	return 0;
}
