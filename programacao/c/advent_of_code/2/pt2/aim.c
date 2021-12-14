#include <stdio.h>

int main()
{
	char direction[8] = "";
	unsigned int amount, horizontal = 0, vertical = 0;
	int aim = 0;

	while(scanf("%s %d", direction, &amount) != EOF)
	{

		switch(direction[0])
		{
			case 'f':
				horizontal += amount;
				vertical += aim * amount;
				break;
			case 'u':
				aim -= amount;
				break;
			case 'd':
				aim += amount;
				break;
		}

	}

	printf("%d\n", horizontal * vertical);
}
