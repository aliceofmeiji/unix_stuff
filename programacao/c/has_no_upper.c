#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	int i;
	char *pwd = argv[1], c = 0;
	for(i = 0; islower(pwd[i]) && pwd[i]; i++);
	printf("%d\n", pwd[i]);
}

