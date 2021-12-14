#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	unsigned char size;
	unsigned char c;
	size = fread(&c, 1, 1, stdin);
	while(size != 0)
	{
		printf("%d%d%d%d%d%d%d%d | %02x | %c\n", 
			(c >> 7) & 1, 
			(c >> 6) & 1, 
			(c >> 5) & 1, 
			(c >> 4) & 1, 
			(c >> 3) & 1, 
			(c >> 2) & 1, 
			(c >> 1) & 1, 
			c	 & 1, 
			c,
			c);
		size = fread(&c, 1, 1, stdin);
		//printf("%d", x);
	}
}
