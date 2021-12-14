#include "sudoku.h"

int main(int argc, char *argv[])
{
	int i, j;
	Board board;
	init_board(&board);

	if(argc > 1)
	{
		read_to_board(&board, argv[1]);
	}

	while(!(check_board(board)))
	{
		printf("%d\n", check_board(board));
	
		print_board(board);
	
		input_to_board(&board);
	}
	print_board(board);
	printf("%d\n", check_board(board));
}
