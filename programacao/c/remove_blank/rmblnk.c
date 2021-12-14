#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char input_line[512];
	char no_trail[512];
	int i, j;
	char readchar;
	while(fgets(input_line, 512, stdin))
	{
		i = 0;
		do
		{
			readchar = input_line(i);
			i++;
			if(readchar != ' '
		}
		while(readchar == ' ');
		printf("%s", input_line);
	}
}
