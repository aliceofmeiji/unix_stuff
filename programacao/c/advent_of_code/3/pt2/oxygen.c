#include <stdio.h>
#include <stdlib.h>
#define LENGTH 12
#define SIZE 1000

void most_common(char number[]);

int main()
{

	int i, j;
	char list[SIZE][LENGTH], number[LENGTH];

	for(i = 0; i < SIZE; i++)
	{
		scanf("%s", list[i]);
			
	}

	most_common(number);
	
	printf("%.*s\n", 12, number);
}

void most_common(char number[], char list[][])
{
	int i, j;

	for(i = 0; i < LENGTH; i++)
	{
		for(j = 0; j < LENGTH; j++)
		{
			if(list[j] == '0')
				number[j]--;
			else
				number[j]++;
		}
	}

        for(i = 0; i < LENGTH; i++)
        {
                number[i] += (number[i] > 0) + '0';
        }
}
