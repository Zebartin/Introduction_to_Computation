/*
例子输入
	4
例子输出
	1 2 6 7
	
	3 5 8 13
	
	4 9 12 14
	
	10 11 15 16
*/
#include<iostream>
using namespace std;
int snake[100][100];
void fill(int n)
{
	int i = 0, j = 0, m = 1, d = 1;
	while (m <= n*n)
	{
		if (i < n && j < n)
			snake[i][j] = m++;
		if (d == 1)
		{
			if (i == 0)
			{
				j++;
				d = 2;
			}
			else if (j == n - 1)
			{
				i++;
				d = 2;
			}
			else
			{
				j++;
				i--;
			}
		}
		else if (d == 2)
		{
			if (j == 0)
			{
				i++;
				d = 1;
			}
			else if (i == n - 1)
			{
				j++;
				d = 1;
			}
			else
			{
				j--;
				i++;
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	memset(snake, 0, sizeof(snake));
	fill(n);
	for (int i = 0; i < n; i++)
	{
		cout << snake[i][0];
		for (int j = 1; j < n; j++)
			cout << " " << snake[i][j];
		cout << endl;
	}
	return 0;
}
