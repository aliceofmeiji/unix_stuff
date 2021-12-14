#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include "render.h"

int main(int argc, int *argv[])
{
	uint32_t x1, y1, x2, y2, width, height;
	sscanf(argv[1], "%u", &width);
	sscanf(argv[2], "%u", &height);
	uint16_t *image = malloc(width * height * 8);
	
	while(fscanf(stdin, "%u %u %u %u", &x1, &y1, &x2, &y2) != EOF)
	{
		draw_line(image, width, x1, y1, x2, y2);
	}
	
	print_image(image, width, height);
	//fwrite(&d, 2, 1, stdout);
	
}
