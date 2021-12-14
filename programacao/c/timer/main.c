#include <pthread.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void *getkey(int *finished)
{
	if(getch() == ' ')
	{
		*finished = 1;
	}
}

int main()
{
	int finished = 0;
	pthread_t thread;
	pthread_create(&thread, NULL, getkey, (int *)finished);
	while(finished != 1)
	{
		printf("1\n");
		sleep(1);
	}
}
