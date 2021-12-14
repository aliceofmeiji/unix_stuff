#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw(int i, int j, int state)
{
	if(state == 0)
	{
		if((j != 0) && (j != 18))
		{
			printf("─⏺─");
		}
		else if(j == 0)
		{
			printf("⏺─");
		}
		else if(j == 18)
		{
			printf("─⏺");
		}
	}
	else if(state == 1)
	{
		if((j != 0) && (j != 18))
		{
			printf("─○─");
		}
		else if(j == 0)
		{
			printf("○─");
		}
		else if(j == 18)
		{
			printf("─○");
		}
	}
	else
	{
		if((j != 0) && (j != 18))
		{
			if(i == 0)
			{
				printf("─┬─");
			}
			else if(i == 18)
			{
				printf("─┴─");
			}
			else
			{
				printf("─┼─");
			}
		}
		else if(j == 0)
		{
			if(i == 0)
			{
				printf("┌─");
			}
			else if(i == 18)
			{
				printf("└─");
			}
			else
			{
				printf("├─");
			}
		}
		else if(j == 18)
		{
			if(i == 0)
			{
				printf("─┐");
			}
			else if(i == 18)
			{
				printf("─┘");
			}
			else
			{
				printf("─┤");
			}
		}
	}
}
int main()
{
	srand(time(0));
	int i, j, state[19][19];
	for(i = 0; i < 19; i++)
	{
		for(j = 0; j < 19; j++)
		{
			draw(i, j, state[i][j]);
		}
		if(i != 18)
		{
			printf("\n│  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │");
		}
		printf("\n");
	}
}
