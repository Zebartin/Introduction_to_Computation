#include <iostream>
#include<iomanip>
#include <cstdio>
#include <fstream>
#define MAX 10
int n, i, j, x, y, total = 0;
int board[MAX][MAX];
int dx[8] = { 1,-1,-2,-2,-1,1,2,2 };
int dy[8] = { 2,2,1,-1,-2,-2,-1,1 };

using namespace std;

void Display() 
{
	for (i = 0; i<n; i++) 
	{
		for (j = 0; j < n; j++)
			if (board[i][j] == 0)
				cout << n*n << " ";
			else
				cout << setw(2) << setfill(' ') << board[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void Trace(int step, int x, int y) {
	int i;
	total++;
	if (n*n == step) 
	{
		Display();
		return;
	}
	for (i = 0; i<8; i++)
		if (x + dx[i] >= 0 && x + dx[i]<n &&
			y + dy[i] >= 0 && y + dy[i]<n && board[x + dx[i]][y + dy[i]] == 0) 
		{
			board[x + dx[i]][y + dy[i]] = step + 1;
			Trace(step + 1, x + dx[i], y + dy[i]);
			board[x + dx[i]][y + dy[i]] = 0;
		}
}
int main()
{
	cin >> n;
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++) 
		{
			board[i][j] = 0;
		}
	cin >> x >> y;
	board[x][y] = 1;
	Trace(1, x, y);
	system("pause");
	return 0;
}