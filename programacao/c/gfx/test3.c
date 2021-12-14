/*
A simple example of using the gfx library.
CSE 20211
9/7/2011
by Prof. Thain
*/

#include <stdio.h>
#include "gfx.h"
#include "mygfx.h"


int main()
{
	int ysize = 600;
	int xsize = 800;
	int i;

	char c;

	// Open a new window for drawing.
	gfx_open(xsize,ysize,"Example Graphics Program");

	// Set the current drawing color to green.
	gfx_color(0,200,100);
	
	for(i = 0; i < 26; i++)
	{
		gfx_char_print((50 + (i*40)), 50, ('a' + i), 5);
	}
	//gfx_char_print(50, 50, 'a', 5);
	
	//gfx_char_print(50, 50, '0', 5);
	//gfx_box(20, 20, 100, 100);

	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();
		if((c == 1) && (((gfx_xpos() <= 100) && (gfx_xpos() >= 20)) && ((gfx_ypos() <= 100) && (gfx_ypos() >= 20))))
		{
			gfx_box(500, 20, 1000, 300);
		}
		// Quit if it is the letter q.
		if(c=='q') break;
	}

	return 0;
}
