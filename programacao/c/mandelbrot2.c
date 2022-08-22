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

	for(i = -2.0; i < 2.0; i += 0.01)
	{
		for(j = -2.0; j < 2.0; j += 0.01)
		{
			c.r = j;
			c.i = i;
			z.r = 0;
			z.i = 0;

			for(k = 0; k < 1000 && !(((z.r * z.r) + (z.i * z.i)) > 4); k++)
				z = add(c, mult(z, z)); 
			
			putchar(z.r > 1 || z.r < -1 || z.i > 1 || z.i < -1 ? 0x00 : 0xFF);
			putchar(z.r > 1 || z.r < -1 || z.i > 1 || z.i < -1 ? 0x00 : 0xFF);
			putchar(z.r > 1 || z.r < -1 || z.i > 1 || z.i < -1 ? 0x00 : 0xFF);
		}
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
