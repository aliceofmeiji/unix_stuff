#include <stdlib.h>
#include <stdio.h>

char xtoi(char c);

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage: coord_to_ff width height\n");
		return 1;
	}

	int x, y, i, width = atoi(argv[1]), height = atoi(argv[2]), w, h;
	char * image = malloc(height * width * 8);
	char s[8], c;

	while(scanf("%d %d %s", &x, &y, s) != EOF)
	{
		for(i = 0; i < 8; i++)
		{
			c = (xtoi(s[i]) << 4) + xtoi(s[i + 1]);
			image[8 * (x + (y * width)) + i] = c;
		}
	}
	
	printf("farbfeld");
	for(i = 0; i < 4; i++)
		putchar(width >> (8 * (3 - i)));
	for(i = 0; i < 4; i++)
		putchar(height >> (8 * (3 - i)));

	for(i = 0; i < (height * width * 8 + 1); i++)
		putchar(image[i]);
}

char xtoi(char c)
{
	if(c >= 'a' && c <= 'f')
		return (c - 'a' + 0x0a);
	else if(c >= 'A' && c <= 'F')
		return (c - 'A' + 0x0a);
	else
		return (c - '0');
}
