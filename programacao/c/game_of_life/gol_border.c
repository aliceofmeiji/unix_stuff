#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void read_game(int width, int height, char* field);
void do_step(int width, int height, char* input_field, char* output_field);
void output_game(int width, int height, char* field);

int main(int argc, char *argv[])
{
	int width = 6;
	int height = 6;

	width = strtol(argv[1], NULL, 10);
	height = strtol(argv[2], NULL, 10);
	
	//char * field = malloc(height * width);

	char input_field[height][width];
	char output_field[height][width];

	read_game(width, height, (char *)input_field);

	do_step(width, height, (char *)input_field, (char *)output_field);

	//printf("\n\n");
	output_game(width, height, (char *)output_field);
	//output_game(width, height, (char *)input_field);
}

void read_game(int width, int height, char* field)
{
	int i, j;
	char buf;
	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			do
			{
				read(STDIN_FILENO, &buf, 1); 
				*(field + j + (i*width)) = buf;
			}
			while((buf == '\n') || (buf == ' '));
		}
	}
}

void do_step(int width, int height, char* input_field, char* output_field)
{
	int i, j;
	char neighbor_field[height][width];
	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			//*(output_field + j + (i*width)) = *(input_field + j + (i*width)) + 1;
			if(i == 0)
			{
				if(j == 0)
				{
					neighbor_field[i][j] = 
						*(input_field + (j + 1) + (i*width)) - '0' +
						*(input_field +	(j + 1) + ((i + 1)*width)) - '0' +
						*(input_field +	j + ((i + 1)*width)) - '0' +
						'0';
						
				}
				else if(j == width - 1)
				{
					neighbor_field[i][j] = 
						*(input_field + (j - 1) + (i*width)) - '0' +
						*(input_field +	(j - 1) + ((i + 1)*width)) - '0' +
						*(input_field +	j + ((i + 1)*width)) - '0' +
						'0';
				}
				else
				{
					neighbor_field[i][j] = 
						*(input_field + (j + 1) + (i*width)) - '0' +
						*(input_field +	(j + 1) + ((i + 1)*width)) - '0' +
						*(input_field +	j + ((i + 1)*width)) - '0' +
						*(input_field + (j - 1) + (i*width)) - '0' +
						*(input_field +	(j - 1) + ((i + 1)*width)) - '0' +
						'0';
				}
			}

			else if(i == height - 1)
			{
				if(j == 0)
				{
					neighbor_field[i][j] = 
						*(input_field + (j + 1) + (i*width)) - '0' +
						*(input_field +	(j + 1) + ((i - 1)*width)) - '0' +
						*(input_field +	j + ((i - 1)*width)) - '0' +
						'0';
				}
				else if(j == width - 1)
				{
					neighbor_field[i][j] = 
						*(input_field + (j - 1) + (i*width)) - '0' +
						*(input_field +	(j - 1) + ((i - 1)*width)) - '0' +
						*(input_field +	j + ((i - 1)*width)) - '0' +
						'0';
				}
				else
				{
					neighbor_field[i][j] = 
						*(input_field + (j + 1) + (i*width)) - '0' +
						*(input_field +	(j + 1) + ((i - 1)*width)) - '0' +
						*(input_field +	j + ((i - 1)*width)) - '0' +
						*(input_field + (j - 1) + (i*width)) - '0' +
						*(input_field +	(j - 1) + ((i - 1)*width)) - '0' +
						'0';
				}
			}

			else
			{
				if(j == 0)
				{
					neighbor_field[i][j] = 
						*(input_field + j + ((i - 1)*width)) - '0' +
						*(input_field +	(j + 1) + ((i - 1)*width)) - '0' +
						*(input_field +	(j + 1) + (i*width)) - '0' +
						*(input_field +	(j + 1) + ((i + 1)*width)) - '0' +
						*(input_field +	j + ((i + 1)*width)) - '0' +
						'0';
				}
				else if(j == width - 1)
				{
					neighbor_field[i][j] = 
						*(input_field + j + ((i - 1)*width)) - '0' +
						*(input_field +	(j - 1) + ((i - 1)*width)) - '0' +
						*(input_field +	(j - 1) + (i*width)) - '0' +
						*(input_field +	(j - 1) + ((i + 1)*width)) - '0' +
						*(input_field +	j + ((i + 1)*width)) - '0' +
						'0';
				}
				else
				{
					neighbor_field[i][j] = 
						*(input_field + j + ((i - 1)*width)) - '0' +
						*(input_field +	(j - 1) + ((i - 1)*width)) - '0' +
						*(input_field +	(j - 1) + (i*width)) - '0' +
						*(input_field +	(j - 1) + ((i + 1)*width)) - '0' +
						*(input_field +	j + ((i + 1)*width)) - '0' +
						*(input_field +	(j + 1) + ((i + 1)*width)) - '0' +
						*(input_field +	(j + 1) + (i*width)) - '0' +
						*(input_field +	(j + 1) + ((i - 1)*width)) - '0' +
						'0';

				}
			}
		}
	}
	
	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			//*(output_field + j + (i*width)) = neighbor_field[i][j];
			if((neighbor_field[i][j] == '2') || (neighbor_field[i][j] == '3'))
			{
				*(output_field + j + (i*width)) = *(input_field + j + (i*width));
			}
			else
			{
				*(output_field + j + (i*width)) = '0';
			}
			
			if(neighbor_field[i][j] == '3')
			{
				*(output_field + j + (i*width)) = '1';
			}
		}
	}
}

void output_game(int width, int height, char* field)
{
	int i, j;
	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			printf("%c", *(field + j + (i*width)) );
		}
		printf("\n");
	}
}

