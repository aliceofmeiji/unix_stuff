#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

int main(int argc, char *argv[])
{
	if(argc > 1)
	{
		initscr();
		char *str = argv[2];
		printw("%s", str);
		refresh();
		char c = getch();
		endwin();
		printf("%c", c);
	}
	else
	{
		char *str;
		str = (char *) malloc(256);
		scanf("%s", str);
		printf("%s", str);
	}
}
