#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "2d_to_coord.h"

Line make_line(int x1, int y1, int x2, int y2, char * color)
{
	Line line;
	if(y1 > y2)
	{
		line.x1 = x2;
		line.x2 = x1;
		line.y1 = y2;
		line.y2 = y1;
	}
	else
	{
		line.x1 = x1;
		line.x2 = x2;
		line.y1 = y1;
		line.y2 = y2;
	}
	line.color = color;
	return line;
}

void print_line(Line line)
{
	int dx = line.x2 - line.x1, dy = line.y2 - line.y1;
	if(dx >= 0)
	{
		if(dx >= dy)
		{
			print_q1(line);
		}
		else
		{
			print_q2(line);
		}
	}
	else
	{
		if(abs(dx) >= abs(dy))
		{
			print_q4(line);
		}
		else
		{
			print_q3(line);
		}
	}
}

void print_q1(Line line)
{
	int x, y, dx = line.x2 - line.x1, dy = line.y2 - line.y1;

	for(x = line.x1; x <= line.x2; x++)
	{
		y = line.y1 + ((dy * (x - line.x1)) / dx);
		printf("%d %d %s\n", x, y, line.color);
	}
}

void print_q2(Line line)
{
	int x, y, dx = line.x2 - line.x1, dy = line.y2 - line.y1;

	for(y = line.y1; y <= line.y2; y++)
	{
		x = line.x1 + ((dx * (y - line.y1)) / dy);
		printf("%d %d %s\n", x, y, line.color);
	}
}

void print_q3(Line line)
{
	int x, y, dx = abs(line.x2 - line.x1), dy = abs(line.y2 - line.y1);

	for(y = line.y1; y <= line.y2; y++)
	{
		x = line.x1 - ((dx * (y - line.y1)) / dy);
		printf("%d %d %s\n", x, y, line.color);
	}
}

void print_q4(Line line)
{
	int x, y, dx = abs(line.x2 - line.x1), dy = abs(line.y2 - line.y1);

	for(x = line.x2; x <= line.x1; x++)
	{
		y = line.y1 - ((dy * (x - line.x1)) / dx);
		printf("%d %d %s\n", x, y, line.color);
	}
}
