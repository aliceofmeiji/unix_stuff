#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void read_game(int width, int height, char* field);
void do_step(int width, int height, char* input_field, char* output_field, int* born_rule, int* survive_rule);
void output_game(int width, int height, char* field);

int main(int argc, char *argv[])
{
	int width = 6;
	int height = 6;
	int i;

	int input_born_rule[9]		= {-1, -1, -1, -1, -1, -1, -1, -1, -1};
	int input_survive_rule[9] 	= {-1, -1, -1, -1, -1, -1, -1, -1, -1};

	int born_rule[9]		= {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int survive_rule[9]		= {0, 0, 0, 0, 0, 0, 0, 0, 0};

	/*for(i = 0; i < 9; i++)
	{
		input_born_rule[i]	= argv[3][i] - '0';
		input_survive_rule[i]	= argv[4][i] - '0';
	}*/

	i = 0;
	while(argv[3][i] != '\0')
	{
		input_born_rule[i] = argv[3][i] - '0';
		i++;
	}

	i = 0;
	while(argv[4][i] != '\0')
	{
		input_survive_rule[i] = argv[4][i] - '0';
		i++;
	}

	/*for(i = 0; i < 9; i++)
	{
		printf("%d", input_survive_rule[i]);
	}*/
	
	i = 0;
	while(input_born_rule[i] != -1)
	{
		born_rule[input_born_rule[i]] = 1;
		i++;
	}

	i = 0;
	while(input_survive_rule[i] != -1)
	{
		survive_rule[input_survive_rule[i]] = 1;
		i++;
	}

	/*for(i = 0; i < 9; i++)
	{
		printf("%d", born_rule[i]);
	}
	printf("\n");

	for(i = 0; i < 9; i++)
	{
		printf("%d", survive_rule[i]);
	}
	printf("\n");*/
	
	/*for(i = 0; i < 9; i++)
	{
		born_rule[i]	= input_born_rule[i];
		survive_rule[i]	= input_survive_rule[i];
	}*/

	width = strtol(argv[1], NULL, 10);
	height = strtol(argv[2], NULL, 10);
	
	//char * field = malloc(height * width);

	char input_field[height][width];
	char output_field[height][width];

	read_game(width, height, (char *)input_field);

	do_step(width, height, (char *)input_field, (char *)output_field, (char *)born_rule, (char *)survive_rule);

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

void do_step(int width, int height, char* input_field, char* output_field, int* born_rule, int* survive_rule)
{
	int i, j, k;
	int survived, born;
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

						*(input_field + (width - 1) + ((i + 1)*width)) - '0' +
						*(input_field + (width - 1) + (i*width)) - '0' +
						*(input_field + (width - 1) + ((height - 1)*width)) - '0' +
						*(input_field + j + ((height - 1)*width)) - '0' +
						*(input_field + (j + 1) + ((height - 1)*width)) - '0' +
						'0';
						
				}
				else if(j == width - 1)
				{
					neighbor_field[i][j] = 
						*(input_field + (j - 1) + (i*width)) - '0' +
						*(input_field +	(j - 1) + ((i + 1)*width)) - '0' +
						*(input_field +	j + ((i + 1)*width)) - '0' +

						*(input_field +	0 + ((i + 1)*width)) - '0' +
						*(input_field +	0 + (i*width)) - '0' +
						*(input_field +	0 + ((height - 1)*width)) - '0' +
						*(input_field +	j + ((height -1)*width)) - '0' +
						*(input_field +	(j - 1) + ((height -1)*width)) - '0' +
						'0';
				}
				else
				{
					neighbor_field[i][j] = 
						*(input_field + (j + 1) + (i*width)) - '0' +
						*(input_field +	(j + 1) + ((i + 1)*width)) - '0' +
						*(input_field +	j + ((i + 1)*width)) - '0' +
						*(input_field +	(j - 1) + ((i + 1)*width)) - '0' +
						*(input_field + (j - 1) + (i*width)) - '0' +

						*(input_field +	(j - 1) + ((height - 1)*width)) - '0' +
						*(input_field +	j + ((height - 1)*width)) - '0' +
						*(input_field +	(j + 1) + ((height - 1)*width)) - '0' +
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

						*(input_field +	(width - 1) + ((i - 1)*width)) - '0' +
						*(input_field +	(width - 1) + (i*width)) - '0' +
						*(input_field +	(width - 1) + 0) - '0' +
						*(input_field +	j + 0) - '0' +
						*(input_field +	(j + 1) + 0) - '0' +
						'0';
				}
				else if(j == width - 1)
				{
					neighbor_field[i][j] = 
						*(input_field + (j - 1) + (i*width)) - '0' +
						*(input_field +	(j - 1) + ((i - 1)*width)) - '0' +
						*(input_field +	j + ((i - 1)*width)) - '0' +

						*(input_field +	0 + ((i - 1)*width)) - '0' +
						*(input_field +	0 + (i*width)) - '0' +
						*(input_field +	0 + 0) - '0' +
						*(input_field +	j + 0) - '0' +
						*(input_field +	(j - 1) + 0) - '0' +
						'0';
				}
				else
				{
					neighbor_field[i][j] = 
						*(input_field + (j + 1) + (i*width)) - '0' +
						*(input_field +	(j + 1) + ((i - 1)*width)) - '0' +
						*(input_field +	j + ((i - 1)*width)) - '0' +
						*(input_field +	(j - 1) + ((i - 1)*width)) - '0' +
						*(input_field + (j - 1) + (i*width)) - '0' +

						*(input_field +	(j - 1) + 0) - '0' +
						*(input_field +	j + 0) - '0' +
						*(input_field +	(j + 1) + 0) - '0' +
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

						*(input_field +	(width - 1) + ((i + 1)*width)) - '0' +
						*(input_field +	(width - 1) + (i*width)) - '0' +
						*(input_field +	(width - 1) + ((i - 1)*width)) - '0' +
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

						*(input_field +	0 + ((i + 1)*width)) - '0' +
						*(input_field +	0 + (i*width)) - '0' +
						*(input_field +	0 + ((i - 1)*width)) - '0' +
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
	
	//generate result from neighbor field

	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			//*(output_field + j + (i*width)) = neighbor_field[i][j];
			
			if
			(
				(neighbor_field[i][j] == '0') * *(survive_rule + 0) ||
				(neighbor_field[i][j] == '1') * *(survive_rule + 1) ||
				(neighbor_field[i][j] == '2') * *(survive_rule + 2) ||
				(neighbor_field[i][j] == '3') * *(survive_rule + 3) ||
				(neighbor_field[i][j] == '4') * *(survive_rule + 4) ||
				(neighbor_field[i][j] == '5') * *(survive_rule + 5) ||
				(neighbor_field[i][j] == '6') * *(survive_rule + 6) ||
				(neighbor_field[i][j] == '7') * *(survive_rule + 7) ||
				(neighbor_field[i][j] == '8') * *(survive_rule + 8)
			)
			{
				*(output_field + j + (i*width)) = *(input_field + j + (i*width));
			}
			else
			{
				*(output_field + j + (i*width)) = '0';
			}
			
			if
			(
				(neighbor_field[i][j] == '0') * *(born_rule + 0) ||
				(neighbor_field[i][j] == '1') * *(born_rule + 1) ||
				(neighbor_field[i][j] == '2') * *(born_rule + 2) ||
				(neighbor_field[i][j] == '3') * *(born_rule + 3) ||
				(neighbor_field[i][j] == '4') * *(born_rule + 4) ||
				(neighbor_field[i][j] == '5') * *(born_rule + 5) ||
				(neighbor_field[i][j] == '6') * *(born_rule + 6) ||
				(neighbor_field[i][j] == '7') * *(born_rule + 7) ||
				(neighbor_field[i][j] == '8') * *(born_rule + 8)
			)
			{
				*(output_field + j + (i*width)) = '1';
			}
			
			/*
			//survive
			survived = '0';

			*(output_field + j + (i*width)) = '0';

			for(k = 0; k < 8; k++)
			{
				//printf("%c", *(survive_rule + k) );
				if( neighbor_field[i][j] == *(survive_rule + k) )
				{
					*(output_field + j + (i*width)) = *(input_field + j + (i*width));
				}
				else
				{
					*(output_field + j + (i*width)) = '0';
				}
			}
			//printf("\n");
			//born
			born = '0';
			for(k = 0; k < 8; k++)
			{
				//printf("%c", *(born_rule + k) );
				if( neighbor_field[i][j] == *(born_rule + k) )
				{
					*(output_field + j + (i*width)) = '1';
				}
			}
			//printf("\n");
			*/
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

