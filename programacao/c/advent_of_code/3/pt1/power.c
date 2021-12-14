#include <stdio.h>
#include <stdlib.h>
#define SIZE 12

int main()
{

	char * list = malloc(SIZE);	
	int * number = malloc(SIZE * sizeof(int));
	int i, gamma = 0, epsilon = 0;

	while(scanf("%s", list) != EOF)
	{

		for(i = 0; i < SIZE; i++)
		{
			if(list[i] == '0')
				number[i]--;
			else
				number[i]++;
		}
	}

	for(i = 0; i < SIZE; i++)
	{
		gamma += (number[i] > 0) << SIZE - i - 1;
		epsilon += (number[i] < 0) << SIZE - i - 1;
	}

	printf("%d\n", gamma * epsilon);
}
