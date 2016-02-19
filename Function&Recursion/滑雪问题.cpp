#include<iostream>
using namespace std;
int h[100][100], f[100][100] = { 0 };
int m, n;
int ski(int, int);
int main()
{
	int i, j, longest = INT_MIN;
	cin >> m >> n;
	for (i = 0; i < m * n; i++)
		cin >> h[i / n][i % n];
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			int t = ski(i, j);
			if (t > longest)
				longest = t;
		}
	cout << longest << endl;
	system("pause");
	return 0;
}
int ski(int x, int y)
{
	if (!f[x][y])
	{
		int max = 0, temp[4] = { 0 };
		if (x - 1 >= 0 && h[x - 1][y] < h[x][y])
			temp[0] = ski(x - 1, y);
		if (x + 1 < m && h[x + 1][y] < h[x][y])
			temp[1] = ski(x + 1, y);
		if (y + 1 < n && h[x][y + 1] < h[x][y])
			temp[2] = ski(x, y + 1);
		if (y - 1 >= 0 && h[x][y - 1] < h[x][y])
			temp[3] = ski(x, y - 1);
		for (int i = 0; i < 4; i++)
			if (temp[i] > max)
				max = temp[i];
		f[x][y] = max + 1;
	}
	return f[x][y];
}