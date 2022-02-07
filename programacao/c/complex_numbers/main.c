#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	double r;
	double i;
} complex;

complex add(complex a, complex b);
complex mult(complex a, complex b);

int main(int argc, char *argv[])
{
	complex z, c;
	int i;
	c.r = -0.25;
	c.i = 0.25;
	z.r = 1;
	z.i = 1;

	for(i = 0; i < 10; i++)
	{
		z = add(c, mult(z, z)); 
	}
	
	printf("%lf %lf\n", z.r, z.i);
}

complex add(complex a, complex b)
{
	complex c;
	c.r = (a.r + b.r);
	c.i = (a.i + b.i);
	return c;
}

complex mult(complex a, complex b)
{
	complex c;
	c.r = (a.r * b.r) - (a.i * b.i);
	c.i = (a.r * b.i) + (a.i * b.r);
	return c;
}

