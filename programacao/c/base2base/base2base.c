#include <stdlib.h>
#include <stdio.h>
#include "base2base.h"

int main(int argc, char *argv[])
{
	int in_base, out_base, quantity;
	char *output = malloc(256);
	sscanf(argv[1], "%d", &in_base);
	sscanf(argv[2], "%d", &out_base);

	quantity = decode(argv[3], in_base);
	if(quantity == 0)
	{
		printf("0\n");
	}
	else
	{
		encode(quantity, out_base, output);
		printf("%s\n", output);
	}
}
