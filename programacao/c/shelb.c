#include <math.h>
#include <stdio.h>

int main()
{
	char cr, cg, cb;
	double i, z, theta;
	for(i = -1; i < 1; i += 0.01)
	{
		for(z = -1; z < 1; z += 0.01)
		{
			theta = (z + M_PI) % (2.0 * M_PI);
			r = cos(theta);
			b = sin(theta);
			g = (r + b) / 2.0;

			cr = ((r + 1) / 2.0) * 256;
			cg = ((g + 1) / 2.0) * 256;
			cb = ((b + 1) / 2.0) * 256;

			putchar(cr);
			putchar(cg);
			putchar(cb);
		}
	}
}
