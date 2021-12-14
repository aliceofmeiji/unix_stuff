#include<stdio.h>
#include<stdlib.h>

int main()
{
	char palavra1[100], palavra2[100];
       	int qtdletra1[58], qtdletra2[58], i, igual = 1;

	
	for(i = 0; i < 100; i++)
	{
		palavra1[i] = 0;
		palavra2[i] = 0;
	}
	for(i = 0; i < 58; i++)
	{
		qtdletra1[i] = 0;
		qtdletra2[i] = 0;
	}
	
	scanf("%s", palavra1);
	scanf("%s", palavra2);

	for(i = 0; i < 100; i++)
	{
		//printf("%d ", palavra1[i]);
		qtdletra1[(palavra1[i]) - 65]++;
		qtdletra2[(palavra2[i]) - 65]++;
	}

	for(i = 0; i < 58; i++)
	{
		if(qtdletra1[i] != qtdletra2[i])
		{
			igual = 0;
		}
	}

	if(igual == 1)
	{
		printf("true\n");
	}
	else 
	{
		printf("false\n");
	}
}
