/*
A simple example of using the gfx library.
CSE 20211
9/7/2011
by Prof. Thain
*/

#include <stdio.h>
#include "gfx.h"

void draw_a(int x, int y)
{
	gfx_line(x, (y + 50), (x + 25), y);
	gfx_line((x + 25), y, (x + 50), (y + 50));
	gfx_line((x + 12), (y + 25), (x + 38), (y + 25));

}

int main()
{
	int ysize = 600;
	int xsize = 600;

	char c;

	// Open a new window for drawing.
	gfx_open(xsize,ysize,"Example Graphics Program");

	// Set the current drawing color to green.
	gfx_color(0,200,100);

	// Draw a triangle on the screen.
	//gfx_line(100,100,200,100);
	//gfx_line(200,100,150,150);
	//gfx_line(150,150,100,100);
	draw_a(50, 50);
	draw_a(50, 250);

	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}

	return 0;
}
