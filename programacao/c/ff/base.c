#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>

#define LEN(x) (sizeof (x) / sizeof *(x))
int main(int argc, char *argv[])
{

	uint32_t header[4], width, height, i, j, k;

	fread(header, sizeof(*header), LEN(header), stdin);

	width = ntohl(header[2]);
	height = ntohl(header[3]);

	uint64_t pixel[width*height];

	fwrite(header, sizeof(*header), LEN(header), stdout);

	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			fread(pixel, 8, 1, stdin);
			fwrite(pixel, 8, 1, stdout);
		}
	}
}
