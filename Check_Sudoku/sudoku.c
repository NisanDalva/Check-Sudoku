#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "sudoku.h"
#include "general.h"


void initSudoku(SUDOKU* pS)
{
	if (!pS)
		return;
	do
	{
		printf("Enter size of board: ");
		scanf("%d", &pS->boardSize);
	} while (!checkBoardSize(pS->boardSize));

	printf("boardSize = %d\n", pS->boardSize);

	initMat((int*)pS->board, pS->boardSize, pS->boardSize);
	printMat((int*)pS->board, pS->boardSize, pS->boardSize);

	memset(tempArr, 0, MAX_LEN * sizeof(int)); //initialize temporary array to zero value
}

int isValidSudoku(SUDOKU* pS)
{
	if (checkAllRows((int*)pS->board, pS->boardSize)
		&& checkAllColumns((int*)pS->board, pS->boardSize)
		&& checkAllBoxes((int*)pS->board, pS->boardSize))
		return 1;

	return 0;
}

int checkAllRows(int* pBoard, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!checkEachRow(pBoard, size, i))
			return 0; // found row that is invalid
	}

	return 1; //all rows are valid
}

int checkEachRow(int* pBoard, int size, int row)
{
	int num;
	for (int j = 0; j < size; j++)
	{
		num = *(pBoard + size * row + j); // num = board[row][j], row = const
		if (*(tempArr + num - 1) != 0 || num > size || num <= 0)
			return 0; //same number appears more than ones or number is not in correct range, invalid row
		else
			*(tempArr + num - 1) = 1;
	}

	memset(tempArr, 0, MAX_LEN * sizeof(int)); // each row is not independent on other row
	return 1; //valid row
}

int checkAllColumns(int* pBoard, int size)
{
	for (int j = 0; j < size; j++)
	{
		if (!checkEachColumn(pBoard, size, j))
			return 0; // found column that is invalid
	}

	return 1; // all columns are valid
}

int checkEachColumn(int* pBoard, int size, int col)
{
	int num;
	for (int i = 0; i < size; i++)
	{
		num = *(pBoard + size * i + col); // num = board[i][col], col = const
		if (*(tempArr + num - 1) != 0 || num > size || num <= 0)
			return 0; //same number appears more than ones or number is not in correct range, invalid column
		else
			*(tempArr + num - 1) = 1;
	}

	memset(tempArr, 0, MAX_LEN * sizeof(int)); // each col is not independent on other col
	return 1; //valid column
}

int checkAllBoxes(int* pBoard, int size)
{
	int boxSize = (int)sqrt(size);

	for (int x = 0; x < size; x = x + boxSize) // run all over horizontal boxes
	{
		for (int y = 0; y < size; y = y + boxSize) // run all over vertical boxes
		{
			if (!checkEachBox(pBoard, size, x, y))
				return 0; // found box that is invalid
		}
	}

	return 1; // all boxes are valid
}

int checkEachBox(int* pBoard, int size, int startRow, int StartCol)
{
	int boxSize = (int)sqrt(size);
	int num;
	for (int i = 0; i < boxSize; i++) // run all over rows in each box
	{
		for (int j = 0; j < boxSize; j++) // run all over columns in each box
		{
			num = *(pBoard + size * (i + startRow) + (j + StartCol)); // num = board[i+x][j+y];
			if (*(tempArr + num - 1) != 0 || num > size || num <= 0)
				return 0; //same number appears more than ones or number is not in correct range, invalid box
			else
				*(tempArr + num - 1) = 1;
		}
	}

	memset(tempArr, 0, MAX_LEN * sizeof(int)); // each box is not independent on other box
	return 1; //valid box
}

int checkBoardSize(int num)
{
	double temp = sqrt(num);
	if (temp - (int)temp == 0 && temp <= 5 && num >= 4) //temp - (int)temp == 0 --> check if sqrt(num) is an integer number
		return 1;
	return 0;
}