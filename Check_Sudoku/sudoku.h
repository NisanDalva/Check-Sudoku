#ifndef __SUDOKU__
#define __SUDOKU__

#define MAX_LEN 25
int tempArr[MAX_LEN];

/* defenition */
typedef struct {
	int board[MAX_LEN][MAX_LEN];
	int boardSize;
} SUDOKU;

/* prototypes */
void initSudoku(SUDOKU* pS);
int checkBoardSize(int num);
int isValidSudoku(SUDOKU* pS);

int checkAllRows(int* pBoard, int size);
int checkEachRow(int* pBoard, int size, int row);

int checkAllColumns(int* pBoard, int size);
int checkEachColumn(int* pBoard, int size, int col);

int checkAllBoxes(int* pBoard, int size);
int checkEachBox(int* pBoard, int size, int startRow, int StartCol);


#endif