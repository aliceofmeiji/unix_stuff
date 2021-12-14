#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <arpa/inet.h>

int main()
{
	char farbfeld[8] = "farbfeld";

	uint32_t width, height, i, j;

	width = 200;
	height = 200;

	uint32_t width_header = ntohl(width);
	uint32_t height_header = ntohl(height);

	fwrite(farbfeld, 8, 1, stdout);
	fwrite(&width_header, 4, 1, stdout);
	fwrite(&height_header, 4, 1, stdout);

	uint16_t rgba[width][height][4];

	srand(time(0));
	
	int temp = 0;

	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			//temp++;
			//printf("%d\n", temp);
			rgba[i][j][0] = rand();
			rgba[i][j][1] = rand();
			rgba[i][j][2] = rand();
			rgba[i][j][3] = rand();
		}
	}

	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			fwrite(&rgba[i][j][0], 2, 1, stdout);
			fwrite(&rgba[i][j][1], 2, 1, stdout);
			fwrite(&rgba[i][j][2], 2, 1, stdout);
			fwrite(&rgba[i][j][3], 2, 1, stdout);
		}
	}
}
