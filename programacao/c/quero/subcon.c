#include<stdio.h>
#include<stdlib.h>

int main()
{
	int menorsoma = 0, i, j, n, numteste = 0, menor, posini, posfin;
	
	scanf("%d", &n);
	int array[n];

	for(i = 0; i < n; i++)
	{
		scanf("%d", &array[n]);
	}

	menor = array[0];

	for(i = 0; i < n; i++)
	{
		numteste = 0;
		for(j = n; j > 0; j--)
		{
			numteste = numteste + array[j];
			if(numteste < menor)
			{
				menor = numteste;
				posini = i;
				posfin = j;
			}
		}
	}
	if(menor >= 0)
	{
		printf("0\n");
	}
	else
	{
		for(; posini <= posfin; posini++)
		{
			printf("%d\n", array[posini]);
		}
	}
}
