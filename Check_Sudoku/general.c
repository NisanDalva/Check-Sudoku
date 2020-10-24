#include "general.h"


void initMat(int* mat, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			printf("Enter a number in row %d on column %d:\t", i, j);
			scanf("%d", (mat + cols * i + j)); //arr[i][j]
		}
	}
}

void printMat(const int* mat, int rows, int cols)
{
	printf("\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%4d", *(mat + cols * i + j)); //arr[i][j]

		printf("\n");
	}
}