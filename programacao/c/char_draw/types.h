#include <stdio.h>
#include <stdlib.h>

void print_output(char *output, int width, int height)
{
	int i, j;
	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			printf("%c", *(output + j + (i*width)));
		}
		printf("\n");
	}
}

void draw_char(char *output, int width, int x, int y, char corner)
{
	*(output + --x + (--y*width)) = corner;
}

void draw_horizontal_line(char *output, int width, int x_begin, int y_begin, int size, char corner, char horizontal)
{
	int i;
	x_begin--;
	y_begin--;
	for(i = 0; i < size; i++)
	{
		*(output + x_begin + i + (y_begin*width)) = horizontal;
	}
	*(output + x_begin + (y_begin*width)) = corner;
	*(output + x_begin + (y_begin*width) + size) = corner;
}

void draw_vertical_line(char *output, int width, int x_begin, int y_begin, int size, char corner, char vertical)
{
	int i;
	x_begin--;
	y_begin--;
	for(i = 0; i < size; i++)
	{
		*(output + x_begin + ((y_begin + i)*width)) = vertical;
	}
	*(output + x_begin + (y_begin*width)) = corner;
	*(output + x_begin + ((y_begin + size)*width)) = corner;
}

void fill_box(char *output, int width, int x_begin, int y_begin, int x_end, int y_end, char background)
{
	int i, j;
	for(i = 0; i < (y_end - y_begin - 1); i++)
	{
		for(j = 0; j < (x_end - x_begin - 1); j++)
		{
			*(output + x_begin + (y_begin*width) + j + (i*width)) = background;
		}
	}
}

void write_text(char *output, int width, int x_begin, int y_begin, char *argv, int line_break)
{
	int i = 0, j = 0, tmp = 0;
	char *cur_char;
	while( *(argv + i) != 0 )
	{
		cur_char = (output + x_begin + (width * (y_begin + j)) + tmp);
		if(*(cur_char) == '\n')
		{
			j++;
			tmp = 0;
		}
		else if(*(cur_char) == '\t')
		{
			tmp = tmp + 5;
		}
		else
		{
			*(cur_char) = *(argv + i);
		}
		i++;
		tmp++;
		if(((tmp + line_break) % line_break) == 0)
		{
			j++;
			tmp = 0;
		}
	}
}

void write_line(char *output, int width, int x_begin, int y_begin, char *argv)
{
	int i = 0;
	while( *(argv + i) != 0 )
	{
		*(output + x_begin + (width * y_begin) + i) = *(argv + i);
		i++;
	}
}

void draw_box(char *output, int width, int x_begin, int y_begin, int x_end, int y_end, char corner, char horizontal, char vertical, char background)
{
	draw_horizontal_line(output, width, x_begin, y_begin, (x_end - x_begin), corner, horizontal);
	draw_horizontal_line(output, width, x_begin, y_end,   (x_end - x_begin), corner, horizontal);
	draw_vertical_line(output, width, x_begin, y_begin, (y_end - y_begin), corner, vertical);
	draw_vertical_line(output, width, x_end,   y_begin, (y_end - y_begin), corner, vertical);
	if(background != ' ')
	{
		fill_box(output, width, x_begin, y_begin, x_end, y_end, background);
	}
}
