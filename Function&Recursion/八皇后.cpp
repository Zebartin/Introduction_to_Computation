#include<iostream>
using namespace std;
int board[9][9], line[9], leftline[16], rightline[16];
void printBoard();
void putQueen(int);
int main()
{
	memset(board, 0, sizeof(board));
	memset(line, 0, sizeof(line));
	memset(leftline, 0, sizeof(leftline));
	memset(rightline, 0, sizeof(rightline));
	putQueen(1);
	system("pause");
	return 0;
}
void printBoard()
{
	int i, j;
	for (i = 1; i < 9; i++)
		for (j = 1; j < 9; j++)
		{
			if (j != 1)
				cout << " ";
			if (board[i][j] == 1)
				cout << "¡ñ";
			else
				cout << "¡ð";
			if (j == 8)
				cout << "\n";
		}
	cout << "\n";
}
void putQueen(int col)
{
	int row = 1;
	while (row <= 8)
	{
		if (!line[row] && !leftline[row + col - 1] && !rightline[8 + row - col])
		{
			board[row][col] = 1;
			line[row] = 1;
			leftline[row + col - 1] = 1;
			rightline[8 + row - col] = 1;
			if (col < 8)
				putQueen(col + 1);
			else
				printBoard();
			board[row][col] = 0;
			line[row] = 0;
			leftline[row + col - 1] = 0;
			rightline[8 + row - col] = 0;
		}
		row++;
	}
}