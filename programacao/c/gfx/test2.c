/*
A simple example of using the gfx library.
CSE 20211
9/7/2011
by Prof. Thain
*/

#include <stdio.h>
#include "gfx.h"
#include <unistd.h>

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

	int loopx = 50;
	int loopy = 50;
	int speedx = 1;
	int speedy = 1;

	int apos = 0;

	char c;

	// Open a new window for drawing.
	gfx_open(xsize,ysize,"Example Graphics Program");

	// Set the current drawing color to green.
	gfx_color(0,200,100);

	// Draw a triangle on the screen.
	//gfx_line(100,100,200,100);
	//gfx_line(200,100,150,150);
	//gfx_line(150,150,100,100);
	//draw_a(50, 50);
	//draw_a(50, 250);

	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		if(c == 1)
		{
			gfx_color(255, 0, 0);
		}

		usleep(100000);

		draw_a(loopx, loopy);

		loopx = loopx + (17 * speedx);
		loopy = loopy + (9 * speedy);

		if((loopx > 550) || (loopx < 50))
		{
			speedx = speedx * -1;
		}

		if((loopy > 550) || (loopy < 50))
		{
			speedy = speedy * -1;
		}

		if(c == 'a')
		{
			gfx_clear();
			draw_a(apos, apos);
			apos = apos + 17;
		}
		// Quit if it is the letter q.
		gfx_flush();

		if(c=='q') break;

	}

	return 0;
}
