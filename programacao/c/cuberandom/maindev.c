#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[])
{
	char moves[6] = {'U', 'D', 'R', 'L', 'F', 'B'};
	char direction[3] = {' ', '2', '\''};
	char deep[3] = {'\0', 'w', '3'};
	int defaultqtt[8] = {0, 0, 9, 20, 45, 60, 80, 100};
	srandom(time(NULL));
	int i, side, last, qtt, last2 = -1, in = 20, cubesize = 3, depth = 0;
	if(argc > 1)
	{
		sscanf(argv[1], "%d", &cubesize);
		in = defaultqtt[cubesize];
		if(argc > 2)
		{
			sscanf(argv[argc - 1], "%d", &in);
		}
	}
	for(i = 0; i < in; i++)
	{
		side = random() % 6;
		while((side == last) || (side == last2))
		{
			side = random() % 6;
		}
		if(i != 0)
		{
			last2 = last;
		}
		last = side;
		qtt = random() % 3;
		switch(cubesize)
		{
			case 2:
				depth = 0;
				break;
			case 3:
				depth = 0;
				break;
			case 4:
				depth = random() % 2;
				break;
			case 5:
				depth = random() % 2;
				break;
			case 6:
				depth = random() % 3;
				break;
			case 7:
				depth = random() % 3;
				break;
		}
		if(depth < 2)
		{
			printf("%c%c%c\n", moves[side], deep[depth], direction[qtt]);
		}
		else
		{
			printf("%c%cw%c\n", deep[depth], moves[side], direction[qtt]);
		}
	}
}
