#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	unsigned char data_tape[256*256];
	char instruction_tape[256*256];
	int i;
	for(i = 0; i < 256*256; i++)
	{
		instruction_tape[i] = ' ';
	}
	int instruction_depth = 0;
	int search_depth;
	int data_pointer = 32768;
	int search_pointer = 0;
	int instruction_pointer = 32768;
	char read_func;

	while(read(STDIN_FILENO, &read_func, 1) > 0)
	{
		if
		(
			(read_func == '>') || 
			(read_func == '<') || 
			(read_func == '+') || 
			(read_func == '-') || 
			(read_func == '.') || 
			(read_func == ',') || 
			(read_func == '[') || 
			(read_func == ']')
		)
		{
			if(argc > 1)
			{
				printf("%c", read_func);
			}
			instruction_tape[instruction_pointer] = read_func;
			instruction_pointer++;
		}
	}
	if(argc > 1)
	{
		printf("\n");
	}
	//printf("\n%s\n", instruction_tape);

	//FILE * stdin_copy = freopen("/dev/tty", "r+", stdin);
	freopen("/dev/tty", "r+", stdin);

	for(instruction_pointer = 32768; instruction_tape[instruction_pointer] != ' '; instruction_pointer++)
	{
		if(argc > 1)
		{
			printf	("\n=======================\n");
			printf	(	"%03d, %03d, %03d, %03d, %03d\n", 
					data_tape[data_pointer - 2], 
					data_tape[data_pointer - 1], 
					data_tape[data_pointer], 
					data_tape[data_pointer + 1], 
					data_tape[data_pointer + 2]
				);
			printf	("           ^ (%d)\n", data_pointer - 32768);
			printf	(	"%c%c%c%c%c\n", 
					instruction_tape[instruction_pointer - 2], 
					instruction_tape[instruction_pointer - 1], 
					instruction_tape[instruction_pointer], 
					instruction_tape[instruction_pointer + 1], 
					instruction_tape[instruction_pointer + 2]
				);
			printf	("  ^ (%d)\n=======================\n\n", instruction_pointer - 32768);
		}
		switch(instruction_tape[instruction_pointer])
		{
			case '>':
				data_pointer++;
				break;
			case '<':
				data_pointer--;
				break;
			case '+':
				data_tape[data_pointer]++;
				break;
			case '-':
				data_tape[data_pointer]--;
				break;
			case '.':
				if(argc > 1)
				{
					printf("~~~\n|%c|\n~~~\n", data_tape[data_pointer]);
				}
				else
				{
					printf("%c", data_tape[data_pointer]);
				}
				break;
			case ',':
				scanf("%c", &data_tape[data_pointer]);
				break;
			case '[':
				if(data_tape[data_pointer] == 0)
				{
					//find matching ]
					search_depth = instruction_depth;
					search_pointer = instruction_pointer;
					while
					(
						(instruction_tape[search_pointer] != ']') ||
						(search_depth != -1)
					)
					{
						//printf("%d\n", search_depth);
						search_pointer++;
						if(instruction_tape[search_pointer] == ']')
						{
							search_depth--;
						}
						else if(instruction_tape[search_pointer] == '[')
						{
							search_depth++;
						}
					}
					instruction_pointer = search_pointer;
				}
				break;
			case ']':
				if(data_tape[data_pointer] != 0)
				{
					//find matching [
					search_depth = instruction_depth;
					search_pointer = instruction_pointer;
					while
					(
						(instruction_tape[search_pointer] != '[') ||
						(search_depth != -1)
					)
					{
						//printf("%d\n", search_depth);
						search_pointer--;
						if(instruction_tape[search_pointer] == '[')
						{
							search_depth--;
						}
						else if(instruction_tape[search_pointer] == ']')
						{
							search_depth++;
						}
					}
					instruction_pointer = search_pointer;
				}
				break;
		}

	}
}
