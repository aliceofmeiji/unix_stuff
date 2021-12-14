#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct
{
	int x1;
	int y1;
	int x2;
	int y2;
	char * color;
} Line;

Line make_line(int x1, int y1, int x2, int y2, char * color);
void print_line(Line line);
void print_q1(Line line);
void print_q2(Line line);
void print_q3(Line line);
void print_q4(Line line);

int main(int argc, char *argv[])
{
	int x1, y1, x2, y2;
	char color[8];
	Line line;
	while(scanf("%d %d %d %d %s", &x1, &y1, &x2, &y2, color) != EOF)
	{
		//printf("%d %d %d %d %s\n", x1, y1, x2, y2, color);
		line = make_line(x1, y1, x2, y2, color);
		print_line(line);
	}
}

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
			printf("x1 %d y1 %d x2 %d y2 %d dx %d dy %d\n", line.x1, line.y1, line.x2, line.y2, dx, dy);
			print_q1(line);
		}
		else
		{
			printf("x1 %d y1 %d x2 %d y2 %d dx %d dy %d\n", line.x1, line.y1, line.x2, line.y2, dx, dy);
			print_q2(line);
		}
	}
	else
	{
		if(abs(dx) >= abs(dy))
		{
			printf("x1 %d y1 %d x2 %d y2 %d dx %d dy %d\n", line.x1, line.y1, line.x2, line.y2, dx, dy);
			print_q4(line);
		}
		else
		{
			printf("x1 %d y1 %d x2 %d y2 %d dx %d dy %d\n", line.x1, line.y1, line.x2, line.y2, dx, dy);
			print_q3(line);
		}
	}
}

void print_q1(Line line)
{
	printf("q1\n");
}

void print_q2(Line line)
{
	printf("q2\n");
}

void print_q3(Line line)
{
	printf("q3\n");
}

void print_q4(Line line)
{
	printf("q4\n");
}
