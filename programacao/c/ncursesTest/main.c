#include <ncurses.h>
#include <unistd.h>
#include "kbhit.h"
int main()
{

	int max_y = 0;
	int max_x = 0;

	int bola_y = 0;
	int bola_x = 0;

	int vel_y = 2;
	int vel_x = 2;

	int input = 0;

	initscr();
	cbreak();
	curs_set(FALSE);

	getmaxyx(stdscr, max_y, max_x);

	while(1)
	{
		clear();

		mvaddch(bola_y, bola_x, 'O');

		refresh();

		getmaxyx(stdscr, max_y, max_x);

		if(kbhit())
		{
			input = getchar();
			//printf("%d", input);
			
		}
		
		if(input == 65)
		{
			vel_x = vel_x * (-1);
		}	
		//mvprintw(0, 0, "%d", ch);

		if((bola_y >= max_y) || (bola_y < 0))
		{
			vel_y = vel_y * (-1);
		}

		if((bola_x >= max_x) || (bola_x < 0))
                {
                        vel_x = vel_x * (-1);
                }

		bola_y = bola_y + vel_y;
		bola_x = bola_x + vel_x;
		input = 0;
		usleep(100000);
	}

	getch();
	endwin();

	return 0;
}
