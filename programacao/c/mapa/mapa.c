#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char mapa[256][256];
	char test[4];
	char buff;
	fgets(test, 5, stdin);
	fgets(test, 5, stdin);
	for(int i = 0; i < 256; i++)
	{
		for(int j = 0; j < 256; j++)
		{
			buff = fgetc(stdin);
			if(buff != '\xff')
			{
				mapa[i][j] = buff;
			}
		}
	}
	printf("%s", mapa);

	int cursorx = 0, cursory = 0;

	for(;;)
	{
		getchar();
	}
}
