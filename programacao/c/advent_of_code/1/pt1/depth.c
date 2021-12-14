#include <stdio.h>

int main()
{
	/* count starts as max int value so the first one doesnt count */
	unsigned int value = 0, prev = -1, count = 0;

	while(scanf("%d", &value) != EOF)
	{
		count += (value > prev);
		prev = value;
	}

	printf("%d\n", count);
}
