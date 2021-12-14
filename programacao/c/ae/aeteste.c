#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <locale.h>
#include <math.h>
void printb(char c, int curses, int utf8)
{
	int i;
	int lista[8];
	for(i = 0; i < 8; i++)
	{
		lista[i] = (c & 0X01);
		c >>= 1;
	}
	if((utf8 == 1) && (lista[6]))
	{
		printf("\n");
	}
	for(i = 7; i >= 0; i--)
	{
		if(curses == 1)
		{
			printw("%d", lista[i]);
		}
		else
		{
			printf("%d", lista[i]);
		}
	}
}
int main(int argc, char *argv)
{

	int i;
	setlocale(LC_ALL, "pt_BR.UTF-8");
	initscr();
	char input[20];
	for(i = 0; i < 20; i++)
	{
		input[i] = getch();
		//printf("%c\n", input);
		//printb(input);
	}
	//printf("%c%c", input1, input2);
	endwin();
	printf("%s\n", input);
	for(i = 0; i < 20; i++)
	{
		printb(input[i], 0, 1);
		printf("\n");
	}
	return 0;
}
