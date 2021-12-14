#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <locale.h>

int main(int argc, char *argv)
{

	setlocale(LC_ALL, "");

	initscr();
	printw("shangai alice of meiji ççç");
	refresh();
	int input = getch();
	printw("%c", input);
	input = getch();
	printw("%c", input);
	input = getch();
	printw("%c", input);
	input = getch();
	printw("%c", input);

	endwin();

	return 0;
}
