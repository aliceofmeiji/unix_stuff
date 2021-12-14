#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n = 1, n1 = 1, n2 = 1, i, j;
	sscanf(argv[1], "%d", &i);
	for(j = 0; j < i; j++)
	{
		n = n1 + n2;
		n2 = n1;
		n1 = n;
	}
	printf("%d\n", n);
}