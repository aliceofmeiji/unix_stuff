#include <stdio.h>

int main()
{
	char direction[8] = "";
	unsigned int amount, horizontal = 0, vertical = 0;

	while(scanf("%s %d", direction, &amount) != EOF)
	{

		switch(direction[0])
		{
			case 'f':
				horizontal += amount;
				break;
			case 'u':
				vertical -= amount;
				break;
			case 'd':
				vertical += amount;
				break;
		}

	}

	printf("%d\n", horizontal * vertical);
}
