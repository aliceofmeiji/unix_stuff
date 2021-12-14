#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//printf("%d %c %d", a, op, b);
	if(argc == 4)
	{
		int a = strtol(argv[1], NULL, 16), b = strtol(argv[3], NULL, 16);
		char op = argv[2][0];
		switch(op)
		{
			case '+':
				printf("%02x", a + b);
				break;
			case '-':
				printf("%02x", a - b);
				break;
			case 'x':
				printf("%02x", a * b);
				break;
			case '*':
				printf("%02x", a * b);
				break;
			case '/':
				printf("%02x", a / b);
				break;
			case '%':
				printf("%02x", a % b);
				break;
			case 'o':
				printf("%02x", a | b);
				break;
			case 'a':
				printf("%02x", a & b);
				break;
		}
	}
	if(argc == 3)
	{
		int a = strtol(argv[1], NULL, 16);
		char op = argv[2][0];
		switch(op)
		{
			case 'd':
				printf("%02d", a);
				break;
			case '+':
				printf("%02x", a + 1);
				break;
			case '-':
				printf("%02x", a - 1);
				break;
		}
	}
	/*else
	{
		switch(op)
		{
			case '+':
				printf("%02X", a + b);
				break;
			case '-':
				printf("%02X", a - b);
				break;
			case 'x':
				printf("%02X", a * b);
				break;
			case '*':
				printf("%02X", a * b);
				break;
		}
	}*/
}
