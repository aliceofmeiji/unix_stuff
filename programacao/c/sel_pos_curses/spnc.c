#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

int main(int argc, char *argv[])
{
	char ch;
	int x = 0, y = 0;
	if(argc > 1)
	{
		sscanf(argv[1], "%d", &y);
		sscanf(argv[2], "%d", &x);
		x--;
		y--;
	}
	initscr();
	noecho();
	FILE *input = fopen("/tmp/spnc_in", "r");
	while(fread(&ch, 1, 1, input))
	{
		addch(ch);
	}
	move(x,y);
	keypad(stdscr, TRUE);
	refresh();
	ch = getch();
	while(ch != 'q')
	{
		switch(ch)
		{
			case 'w':
				x--;
				break;
			case 'a':
				y--;
				break;
			case 's':
				x++;
				break;
			case 'd':
				y++;
				break;
		}
		move(x,y);
		refresh();
		ch = getch();
	}
	endwin();
	FILE *fd = fopen("/tmp/spnc_out", "w");
	char output[50];
	sprintf(output, "%d %d\n", y + 1, x + 1);
	//printf("%s", output);
	fputs(output, fd);
}
