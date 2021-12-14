#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static const char single[][8] = 
{
	"🌵",
	"🪨",
	"🦂",
	"🐍",
};

int main(int argc, char *argv[])
{
	srand(time(0));
	int i;
	for(i = 0; i < 10000; i++)
	{
		if((rand() % 800) == 0)
		{
			printf("%s", single[rand() % 4]);
		}
		else
		{
			printf(" ");
		}
		if((i % 50) == 0){printf("\n");}
	}
	printf("\n");
}
