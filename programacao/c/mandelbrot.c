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
	double i, j, k;

	for(i = -1.0; i < 1.0; i += 0.0125)
	{
		for(j = -1.0; j < 1.0; j += 0.006125)
		{
			c.r = j;
			c.i = i;
			z.r = 0;
			z.i = 0;

			for(k = 0; k < 1000 && !(z.r > 1 || z.r < -1 || z.i > 1 || z.i < -1); k++)
				z = add(c, mult(z, z)); 
			
			putchar(z.r > 1 || z.r < -1 || z.i > 1 || z.i < -1 ? ' ' : '#');
		}
		putchar('\n');
	}
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
