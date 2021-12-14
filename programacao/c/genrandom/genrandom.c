#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		printf("Usage: genrandom #_of_steps max_# one_in_every_#\n");
	}
	else
	{
		srand(time(0));
		int steps =	strtol(argv[1], NULL, 10);
		int max =	strtol(argv[2], NULL, 10);
		int occurence =	strtol(argv[3], NULL, 10);
		int generated;
		int i, j;
		for(i = 0; i < steps; i++)
		{
			generated = rand() % max;
			if(( rand() % occurence ) == 0)
			{
				printf("%d\n", generated + 1);
			}
			else
			{
				printf("0\n");
			}
		}
	}
}
