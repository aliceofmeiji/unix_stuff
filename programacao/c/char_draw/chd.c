#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"

int main(int argc, char *argv[])
{
	int width, height, x_begin, y_begin, x_end, y_end, i, j, new, line_break, size, path, last_x, last_y;
	char *output, type, trash, corner, horizontal, vertical, background, direction;

	if(argc == 1)
	{
		printf("Usage: chd [-n] width height type opts\n");
		return 0;
	}

	if(strcmp(argv[1], "-n") == 0)
	{
		new = 1;
		sscanf(argv[2], "%d", &width);
		sscanf(argv[3], "%d", &height);
		output = malloc(width*height);
		for(i = 0; i < width*height; i++)
		{
			*(output + i) = ' ';
		}
	}
	else
	{
		new = 0;
		sscanf(argv[1], "%d", &width);
		sscanf(argv[2], "%d", &height);
		output = malloc(width*height);
		for(i = 0; i < height; i++)
		{
			fread((output + (i * width)), width, 1, stdin);
			fread(&trash, 1, 1, stdin);
		}
	}

	type = *argv[3 + new];

	switch(type)
	{
		case 's': //simple_box
			sscanf(argv[4 + new], "%d", &x_begin);
			sscanf(argv[5 + new], "%d", &y_begin);
			sscanf(argv[6 + new], "%d", &x_end);
			sscanf(argv[7 + new], "%d", &y_end);
			draw_box(output, width, x_begin, y_begin, x_end, y_end, '#', '-', '|', ' ');
			break;
		
		case '/': //cute_box
			sscanf(argv[4 + new], "%d", &x_begin);
			sscanf(argv[5 + new], "%d", &y_begin);
			sscanf(argv[6 + new], "%d", &x_end);
			sscanf(argv[7 + new], "%d", &y_end);
			draw_box(output, width, x_begin, y_begin, x_end, y_end, '/', '-', '|', ' ');
			draw_char(output, width, x_begin, y_end, '\\');
			draw_char(output, width, x_end, y_begin, '\\');
			break;

		case 'c': //draw_char
			sscanf(argv[4 + new], "%d", &x_begin);
			sscanf(argv[5 + new], "%d", &y_begin);
			sscanf(argv[6 + new], "%c", &corner);
			draw_char(output, width, x_begin, y_begin, corner);
			break;

		case 'b': //complete_box
			sscanf(argv[4 + new], "%d", &x_begin);
			sscanf(argv[5 + new], "%d", &y_begin);
			sscanf(argv[6 + new], "%d", &x_end);
			sscanf(argv[7 + new], "%d", &y_end);
			sscanf(argv[8 + new], "%c", &corner);
			sscanf(argv[9 + new], "%c", &horizontal);
			sscanf(argv[10 + new], "%c", &vertical);
			sscanf(argv[11 + new], "%c", &background);
			draw_box(output, width, x_begin, y_begin, x_end, y_end, corner, horizontal, vertical, background);
			break;

		case 'f': //fill_box
			sscanf(argv[4 + new], "%d", &x_begin);
			sscanf(argv[5 + new], "%d", &y_begin);
			sscanf(argv[6 + new], "%d", &x_end);
			sscanf(argv[7 + new], "%d", &y_end);
			sscanf(argv[8 + new], "%c", &background);
			fill_box(output, width, x_begin, y_begin, x_end, y_end, background);
			break;

		case 'h': //draw_horizontal_line
			sscanf(argv[4 + new], "%d", &x_begin);
			sscanf(argv[5 + new], "%d", &y_begin);
			sscanf(argv[6 + new], "%d", &size);
			sscanf(argv[7 + new], "%c", &corner);
			sscanf(argv[8 + new], "%c", &horizontal);
			draw_horizontal_line(output, width, x_begin, y_begin, size, corner, horizontal);
			break;

		case 'v': //draw_vertical_line
			sscanf(argv[4 + new], "%d", &x_begin);
			sscanf(argv[5 + new], "%d", &y_begin);
			sscanf(argv[6 + new], "%d", &size);
			sscanf(argv[7 + new], "%c", &corner);
			sscanf(argv[8 + new], "%c", &horizontal);
			draw_vertical_line(output, width, x_begin, y_begin, size, corner, vertical);
			break;

		case 'w': //write_line
			sscanf(argv[4 + new], "%d", &x_begin);
			sscanf(argv[5 + new], "%d", &y_begin);
			write_line(output, width, x_begin, y_begin, argv[6 + new]);
			break;

		case 't': //write_text
			sscanf(argv[4 + new], "%d", &x_begin);
			sscanf(argv[5 + new], "%d", &y_begin);
			sscanf(argv[7 + new], "%d", &line_break);
			write_text(output, width, x_begin, y_begin, argv[6 + new], line_break);
			break;

		case 'p': //draw_path of lines until it gets back to start
			path = 0;
			sscanf(argv[4 + new], "%c", &corner);
			sscanf(argv[5 + new], "%c", &horizontal);
			sscanf(argv[6+ new], "%c", &vertical);
			sscanf(argv[7 + new], "%d", &x_begin);
			sscanf(argv[8 + new], "%d", &y_begin);
			x_end = x_begin;
			y_end = y_begin;
			
			sscanf(argv[9  + new + (2*path)], "%c", &direction);
			sscanf(argv[10 + new + (2*path)], "%d", &size);
			path++;
			while(direction != 'p')
			{
				switch(direction)
				{
					case 'u':
						y_end = y_end - size;
						draw_vertical_line(output, width, x_end, y_end, size, corner, vertical);
						break;
					case 'd':
						draw_vertical_line(output, width, x_end, y_end, size, corner, vertical);
						y_end = y_end + size;
						break;
					case 'l':
						x_end = x_end - size;
						draw_horizontal_line(output, width, x_end, y_end, size, corner, horizontal);
						break;
					case 'r':
						draw_horizontal_line(output, width, x_end, y_end, size, corner, horizontal);
						x_end = x_end + size;
						break;
				}
				sscanf(argv[9  + new + (2*path)], "%c", &direction);
				sscanf(argv[10 + new + (2*path)], "%d", &size);
				path++;
			}
			
			break;

		case 'n': //do_nothing
			break;


	}

	print_output(output, width, height);
}
