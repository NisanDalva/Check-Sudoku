#include <stdio.h>
#include "sudoku.h"


int main()
{
	SUDOKU sudoku;
	initSudoku(&sudoku);

	if (isValidSudoku(&sudoku))
		printf("Is valid sudoku!");
	else
		printf("Is NOT valid sudoku!");
}