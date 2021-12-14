#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw(int i, int j, int state, char size)
{
	if(size == 's')
	{
	if(state == 0)
	{
		if((j != 0) && (j != 18))
		{
			printf("⏺");
		}
		else if(j == 0)
		{
			printf("⏺");
		}
		else if(j == 18)
		{
			printf("⏺");
		}
	}
	else if(state == 1)
	{
		if((j != 0) && (j != 18))
		{
			printf("○");
		}
		else if(j == 0)
		{
			printf("○");
		}
		else if(j == 18)
		{
			printf("○");
		}
	}
	else
	{
		if((j != 0) && (j != 18))
		{
			if(i == 0)
			{
				printf("┬");
			}
			else if(i == 18)
			{
				printf("┴");
			}
			else
			{
				printf("┼");
			}
		}
		else if(j == 0)
		{
			if(i == 0)
			{
				printf("┌");
			}
			else if(i == 18)
			{
				printf("└");
			}
			else
			{
				printf("├");
			}
		}
		else if(j == 18)
		{
			if(i == 0)
			{
				printf("┐");
			}
			else if(i == 18)
			{
				printf("┘");
			}
			else
			{
				printf("┤");
			}
		}
	}

	}
	if(size == 'n')
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
}
int main(int argc, char *argv[])
{
	srand(time(0));
	int i, j, state[19][19];
	char size = 'n';
	if(argc > 1)
	{
		size = argv[1][0];
	}
	for(i = 0; i < 19; i++)
	{
		for(j = 0; j < 19; j++)
		{
			draw(i, j, state[i][j], size);
		}
		if((i != 18) && (size == 'n'))
		{
			printf("\n│  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │  │");
		}
		printf("\n");
	}
}
