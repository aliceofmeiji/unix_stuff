#include "gfx.h"

void draw_map(char *map, int ncols, int nlines, int xsize, int ysize)
{
	int i, j;

	gfx_color(0,200,100);
	gfx_line(xsize, ysize, xsize, 0);
	gfx_line(xsize, ysize, 0, ysize);

	for(i = 0; i < ncols; i++)
		gfx_line((xsize/ncols) * i, 0, (xsize/ncols) * i, ysize);

	for(i = 0; i < nlines; i++)
		gfx_line(0, (ysize/nlines) * i, xsize, (ysize/nlines) * i);

	gfx_flush();
}

void read_input(char *map, int ncols, int nlines, int xsize, int ysize, char c)
{
	xpos = gfx_xpos();
	ypos = gfx_ypos();
	
	
}
