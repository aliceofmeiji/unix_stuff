#include <stdio.h>

int main()
{
	unsigned int first, second, third;

	scanf("%d %d", &first, &second);

	while(scanf("%d", &third) != EOF)
	{
		printf("%d\n", first + second + third);
		first = second;
		second = third;
	}
}
