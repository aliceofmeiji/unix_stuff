#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <X11/Xlib.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>
#include "gfx.h"  

static bool brushmap_0[10][10] = 	{	
					{0,0,1,1,1,1,1,1,0,0},
					{0,1,1,1,1,1,1,1,1,0},
					{1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1},
					{0,1,1,1,1,1,1,1,1,0},
					{0,0,1,1,1,1,1,1,0,0},
				};
static bool brushmap_1[20][20] = 	{	
					{0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
					{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
					{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
					{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
					{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
					{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
					{0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
					{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
					{0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
					{0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
					{0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
				};

typedef struct Pixels
{
	uint16_t red;
	uint16_t green;
	uint16_t blue;
	uint16_t alpha;
} Pixel;

void pixel_to_screen(Pixel *pixel, uint32_t width, uint32_t height, uint32_t min_x, uint32_t min_y, uint32_t max_x, uint32_t max_y)
{
	uint32_t i, j;
	Pixel *p;
	for(i = min_y; i < max_y; i++)
	{
		for(j = min_x; j < max_x; j++)
		{
			p = pixel + (width*i) + j;
			gfx_color( ((p)->red), ((p)->green), ((p)->blue) );
			gfx_point(j, i);
		}
	}
}

#define LEN(x) (sizeof (x) / sizeof *(x))
int main(int argc, char *argv[])
{

	int done = 0;

	uint32_t header[4], width, height, i, j, k, min_x = 0, min_y = 0, max_x, max_y, zero_x, zero_y;

	fread(header, sizeof(*header), LEN(header), stdin);

	width = ntohl(header[2]);
	height = ntohl(header[3]);

	max_x = width;
	max_y = height;

	//uint64_t pixel[width*height];
	//Pixel pixel[width*height];
	Pixel pixel[width*height];

	gfx_open(width, height, "paint");

	fwrite(header, sizeof(*header), LEN(header), stdout);

	while(done != 1)
	{
		for(i = 0; i < height; i++)
		{
			for(j = 0; j < width; j++)
			{
				//fread(pixel, 8, 1, stdin);
				fread(&pixel[(i*width) + j].red, 2, 1, stdin);
				fread(&pixel[(i*width) + j].green, 2, 1, stdin);
				fread(&pixel[(i*width) + j].blue, 2, 1, stdin);
				fread(&pixel[(i*width) + j].alpha, 2, 1, stdin);
	
				//0x0123 4567 89ab cdef -> 0xefcd ab89 6745 2301
				//uint64_t nored = 0x00FFFFFF;
							
				/*
				gfx_color((int)(*pixel),
					  (int)((*pixel) >> 16),
					  (int)((*pixel) >> 32));
				*/

				gfx_color((pixel[(i*width) + j].red >> 8), (pixel[(i*width) + j].green >> 8), (pixel[(i*width) + j].blue >> 8));
				//gfx_color(255, 255, 255);

//				gfx_point(j, i);

				//fwrite(pixel, 8, 1, stdout);

				/*
				fwrite(&pixel[(i*width) + j].red, 2, 1, stdout);
				fwrite(&pixel[(i*width) + j].green, 2, 1, stdout);
				fwrite(&pixel[(i*width) + j].blue, 2, 1, stdout);
				fwrite(&pixel[(i*width) + j].alpha, 2, 1, stdout);
				*/
			}
		}
	pixel_to_screen(pixel, width, height, min_x, min_y, max_x, max_y);
	gfx_flush();
	gfx_wait();	
	
	/*
	for(i = height/2; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			pixel[(i * width) + j].red = 255;	
			pixel[(i * width) + j].green = 255;	
			pixel[(i * width) + j].blue = 255;	
		}
	}
	*/

	int size = 10;
	int size_id = 1;

	Pixel color;
	color.red = 0xFFFF;		
	color.green = 0xFFFF;		
	color.blue = 0xFFFF;		

	uint16_t xpos, ypos;
	char input;
	while(input != 'q')
	{
		
		
		if(input == 'z')
		{
			if(size > 5)
			{
				size = size - 5;
				size_id = size_id - 1;	
			}
		}	
		if(input == 'x')
		{
			if(size < 50)
			{
				size = size + 5;
				size_id = size_id + 1;	
			}
		}
		if(input == '0')
		{
			color.red = 0x5656;
			color.green = 0x3030;
			color.blue = 0x9696;
		}
		if(input == '9')
		{
			color.red = 0xB9B9;
			color.green = 0x3E3E;
			color.blue = 0xC1C1;
		}
		if(input == '8')
		{
			color.red = 0xFFFF;
			color.green = 0x0000;
			color.blue = 0xFFFF;
		}
		if(input == '7')
		{
			color.red = 0x0000;
			color.green = 0xFFFF;
			color.blue = 0xFFFF;
		}
		if(input == '6')
		{
			color.red = 0xFFFF;
			color.green = 0xFFFF;
			color.blue = 0x0000;
		}
		if(input == '5')
		{
			color.red = 0x0000;
			color.green = 0x0000;
			color.blue = 0xFFFF;
		}
		if(input == '4')
		{
			color.red = 0x0000;
			color.green = 0xFFFF;
			color.blue = 0x0000;
		}
		if(input == '3')
		{
			color.red = 0xFFFF;
			color.green = 0x0000;
			color.blue = 0x0000;
		}
		if(input == '2')
		{
			color.red = 0x0000;
			color.green = 0x0000;
			color.blue = 0x0000;
		}
		if(input == '1')
		{
			color.red = 0xFFFF;
			color.green = 0xFFFF;
			color.blue = 0xFFFF;
		}

		xpos = gfx_xpos() - size;
		ypos = gfx_ypos() - size;
	
		min_x = xpos;
		min_y = ypos;
		max_x = xpos + 2*size;
		max_y = ypos + 2*size;
		zero_x = xpos + size;
		zero_y = ypos + size;

		for(i = ypos; i <= (ypos + (2*size)); i++)
		{	
			for(j = xpos; j <= (xpos + (2*size)); j++)
			{
				switch (size_id)
				{
				case 0:
					if(brushmap_0[i - ypos][j - xpos])
					{
						pixel[(width * i) + j].red = color.red >> 8;	
						pixel[(width * i) + j].green = color.green >> 8;	
						pixel[(width * i) + j].blue = color.blue >> 8;	
					}
				case 1:
					if(brushmap_1[i - ypos][j - xpos])
					{
						pixel[(width * i) + j].red = color.red >> 8;	
						pixel[(width * i) + j].green = color.green >> 8;	
						pixel[(width * i) + j].blue = color.blue >> 8;	
					}
				}
			}
		}

		/*
		for(i = (xpos - 100); i < (xpos + 100); i++)
		{
			for(j = (ypos - 100); j < (ypos + 100); j++)
			{
				pixel[(i * width) + j].red = 255;	
				pixel[(i * width) + j].green = 255;	
				pixel[(i * width) + j].blue = 255;	
			}
		}
		*/
		
		pixel_to_screen(pixel, width, height, min_x, min_y, max_x, max_y);
		input = gfx_wait();	
		gfx_flush();
	}
	//pixel to stdout
		for(i = 0; i < height; i++)
		{
			for(j = 0; j < width; j++)
			{
					fwrite(&pixel[(i*width) + j].red, 2, 1, stdout);
					fwrite(&pixel[(i*width) + j].green, 2, 1, stdout);
					fwrite(&pixel[(i*width) + j].blue, 2, 1, stdout);
					fwrite(&pixel[(i*width) + j].alpha, 2, 1, stdout);
			}
		}
		return 0;
	}
}
