#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

typedef struct
{
	char value;
	char possible_values[9];
} Cell;

typedef struct
{
	Cell cells[9][9];
} Board;

void print_board(Board board)
{
	int i, j;
	for(i = 0; i < 9; i++)
	{
		if((i % 3) == 0) { printf("#---#---#---#\n"); }
		for(j = 0; j < 9; j++)
		{
			if((j % 3) == 0) { printf("|"); }
			printf("%c", board.cells[i][j].value);
		}
		printf("|\n");
	}
	if((i % 3) == 0) { printf("#---#---#---#\n"); }
}

void init_board(Board *board)
{
	int i, j;
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			board->cells[i][j].value = ' ';
		}
	}
}

void read_to_board(Board *board, char *argv)
{
	int i, j;
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			board->cells[i][j].value = *(argv + (i * 9) + j);
		}
	}
}

int check_row(Board board, int row)
{
	int amount[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int i, check = 1;
	for(i = 0; i < 9; i++)
	{
		amount[board.cells[row][i].value - '1']++;
	}
	for(i = 0; i < 9; i++)
	{
		if(amount[i] != 1)
		{
			check = 0;
		}
	}
	return check;
}

int check_collumn(Board board, int collumn)
{
	int amount[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int i, check = 1;
	for(i = 0; i < 9; i++)
	{
		amount[board.cells[i][collumn].value - '1']++;
	}
	for(i = 0; i < 9; i++)
	{
		if(amount[i] != 1)
		{
			check = 0;
		}
	}
	return check;
}

int check_block(Board board, int block_row, int block_collumn)
{
	int amount[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int i, j, check = 1;
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			amount[board.cells[(3*block_row) + i][(block_collumn*3) + j].value - '1']++;
		}
	}
	for(i = 0; i < 9; i++)
	{
		if(amount[i] != 1)
		{
			check = 0;
		}
	}
	return check;
}

int check_board(Board board)
{
	int i, j, check_rows = 1, check_collumns = 1, check_blocks = 1;
	
	int amount_rows		[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int amount_collumns	[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int amount_blocks	[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	for(i = 0; i < 9; i++)
	{
		amount_rows[i] = check_row(board, i);
	}
	for(i = 0; i < 9; i++)
	{
		if(amount_rows[i] != 1)
		{
			check_rows = 0;
		}
	}

	for(i = 0; i < 9; i++)
	{
		amount_collumns[i] = check_collumn(board, i);
	}
	for(i = 0; i < 9; i++)
	{
		if(amount_collumns[i] != 1)
		{
			check_collumns = 0;
		}
	}

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			amount_blocks[(3*i) + j] = check_block(board, i, j);
		}
	}
	for(i = 0; i < 9; i++)
	{
		if(amount_blocks[i] != 1)
		{
			check_blocks = 0;
		}
	}
	
	if(check_rows && check_collumns && check_blocks)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void input_to_board(Board *board)
{
	int row, collumn;
	char value;
	scanf("%d %d %c", &row, &collumn, &value);
	board->cells[row - 1][collumn - 1].value = value;
}

void auto_input_to_board(Board *board, int row, int collumn)
{
	char value;
	scanf("%c", &value);
	board->cells[row][collumn].value = value;
}
