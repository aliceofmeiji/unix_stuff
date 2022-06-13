#include <stdio.h>

void gr(int width, float min, float max, float value, char ch)
{
	int i, x;

	x = ((value - min) * width) / (max - min);
	for(i = 0; i < width; i++)
		putchar(x == i ? ch : ' ');
	putchar('\n');
}

int main(int argc, char **argv)
{
	char ch;
	int width;
	float min, max, value;

	if(argc < 4)
	{
		fprintf(stderr, "gr WIDTH MIN MAX [CHAR]\n");
		return(1);
	}
	sscanf(argv[1], "%d", &width);
	sscanf(argv[2], "%f", &min);
	sscanf(argv[3], "%f", &max);
	ch = argc == 5 ? *argv[4] : '|';
	if(width < 1)
	{
		fprintf(stderr, "width must be positive integer\n");
		return(1);
	}

	while(scanf("%f", &value) != EOF)
		gr(width, min, max, value, ch);

	return(0);
}
