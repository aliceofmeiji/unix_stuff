#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, i, j, menor = 1;
	
	scanf("%d", &n);
	int array[n];

	for(i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}

	for(i = 0; i < n; i++)
	{	

		if(menor == array[i])
		{
			menor = array[i] + 1;
		}

	}
	printf("%d\n", menor);
}
