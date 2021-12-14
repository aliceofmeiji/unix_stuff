#include <pthread.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>


void *getkey(void *finishedp)
{
	
	int saida = (int)&finishedp;
	if(getch() == ' ')
	{
		saida = 1;
	}
	
	
	/*while(1)
	{
		printf("a\n");
		sleep(2);
	}*/
}

int main()
{
	int finished = 0;
	int *finishedp = &finished;
	pthread_t thread;
	pthread_create(&thread, NULL, getkey, (void *)finishedp);
	while(finished != 1)
	{
		printf("1\n");
		sleep(1);
	}
}
