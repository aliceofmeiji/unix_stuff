#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <arpa/inet.h>

typedef struct
{
	uint32_t start_x;
	uint32_t start_y;
	uint32_t end_x;
	uint32_t end_y;
	char name[16];
} Line;

void draw_line(Line line, uint16_t *rgba, uint32_t width, uint32_t height)
{
	int32_t next_color = 2;
	int32_t next_pixel = 8;
	int32_t next_line = width;
	int32_t x_width, y_height, step = 1;

	if(line.end_x >= line.start_x)
	{
		int32_t x_width = line.end_x - line.start_x;
	}
	else
	{
		int32_t x_width = line.start_x - line.end_x;
	}
	
	if(line.end_y >= line.start_y)
	{
		int32_t y_height = line.end_y - line.start_y;
	}
	else
	{
		int32_t y_height = line.start_y - line.end_y;
	}

	if(x_width > y_height)
	{
		int32_t step = x_width/y_height;
	}
	else if(y_height > x_width)
	{
		int32_t step = y_height/x_width;
	}

	
	/*
	*(rgba + (line.start_x * 4) + ((line.start_y * 4) * width)) = 0xFFFF;
	*(rgba + (line.end_x * 4) + ((line.end_y * 4) * width)) = 0xFFFF;
	*/

	int32_t i, j, current_step = 0;
	
	//eigth handling
	printf("%d\n", step);

	if((x_width > 0) && (y_height > 0) && (x_width >= y_height))
	{
		for(i = line.start_x; i < line.end_x; i++)
		{
			if((i % step) == 0)
			{ current_step++; }
			*(rgba + (line.start_x * 4) + (i * 4) + ((current_step + line.start_y) * width * 4)) = 0xFFFF;
		}
	} 

	//if((x_width > 0) && (y_height > 0) && (x_width < y_height))
	//{
	//}



	/*for(i = 0; i < y_height / x_width; i++)
	{
		for(j = 0; j < x_width / y_height; j++)
		{
			*(rgba + ((line.start_x * 4) + (j * 4)) + ((line.start_y * 4 * width) + (i * 4 * width))) = 0xFFFF;
		}
	}*/

	/*
	for(i = line.start_x; i < line.end_x; i++)
	{
		if((i % step) == 0)
		{ current_step++; }
		//*(rgba + (line.start_x * 4) + (i * 4) + (current_step * width * 4)) = 0xFFFF;
		//*(rgba + (line.start_x * 4) + (output_x * 4) + (output_y * width * 4)) = 0xFFFF;
	}
	*/

	//*(rgba + 1) = 0xFFFF;
	//*(rgba + 2) = 0xFFFF;
}

int main()
{
	char farbfeld[8] = "farbfeld";

	uint32_t width, height, i, j;

	width = 500;
	height = 500;

	uint32_t width_header = ntohl(width);
	uint32_t height_header = ntohl(height);

	//fwrite(farbfeld, 8, 1, stdout);
	//fwrite(&width_header, 4, 1, stdout);
	//fwrite(&height_header, 4, 1, stdout);

	uint16_t rgba[width][height][4];
	//uintptr_t *rgba_ptr = &rgba;

	srand(time(0));
	
	int temp = 0;

	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			//temp++;
			//printf("%d\n", temp);
			/*rgba[i][j][0] = rand();
			rgba[i][j][1] = rand();
			rgba[i][j][2] = rand();
			rgba[i][j][3] = rand();*/
			rgba[i][j][0] = 0x1111;
			rgba[i][j][1] = 0x1111;
			rgba[i][j][2] = 0x1111;
			rgba[i][j][3] = 0xFFFF;
		}
	}

	Line line;
	line.start_x = 0;
	line.end_x = 100;
	line.start_y = 0;
	line.end_y = 50;

	Line line2;
	line2.start_x = 0;
	line2.end_x = 50;
	line2.start_y = 0;
	line2.end_y = 100;

	Line line3;
	line3.start_x = 0;
	line3.end_x = 100;
	line3.start_y = 0;
	line3.end_y = 100;

	draw_line(line, rgba, width, height);
	draw_line(line2, rgba, width, height);
	draw_line(line3, rgba, width, height);

	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			//fwrite(&rgba[i][j][0], 2, 1, stdout);
			//fwrite(&rgba[i][j][1], 2, 1, stdout);
			//fwrite(&rgba[i][j][2], 2, 1, stdout);
			//fwrite(&rgba[i][j][3], 2, 1, stdout);
		}
	}
}
