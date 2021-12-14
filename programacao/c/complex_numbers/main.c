#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	double r;
	double i;
} complex;

complex e_to_i(double theta);
complex mult(complex c, double r);

int main(int argc, char *argv[])
{
	//complex c = { sqrt(2), sqrt(2) };
	//printf("%f %f\n", c.r, c.i);

	complex c;
	double t = 0, r;
	char color[9] = "FF0000FF";

	sscanf(argv[1], "%lf", &r);
	
	for(t = 0; t < 2 * M_PI; t = t += 0.01)
	{
		c = mult(e_to_i(t), r);
		printf("%d %d %s\n", (int)(c.r + r + 1), (int)(c.i + r + 1), color);
	}
}

complex e_to_i(double theta)
{
	complex c;
	c.r = cos(theta);
	c.i = sin(theta);
	return c;
}

complex mult(complex c, double r)
{
	c.r *= r;
	c.i *= r;
	return c;
}

