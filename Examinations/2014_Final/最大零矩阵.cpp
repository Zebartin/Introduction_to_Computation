/*
描述
	有一个二位数组 m（<100）行, n（<100） 列，其元素为不大于100的非负整数。现要找元素值均为0的最大子二维数组，
	其中行相邻，列也相邻，行数与列数之积最大(即，所含0元素最多)，输出该最大积。例如： 
	
	2  5  0  0  8  11  15 
	3  0  0  0  0  12  16 
	7  0  0  0  0  13  17 
	8  0  0  7  1  14  18 
	4  0  0  0  0  0   0 
	6  0  0  0  0  0   0 
	
	这是6行，7列构成的二维数组，其中：由第4~5行(最后2行)，第1~6列（最后6列）构成的子数组最大，
	共有12个0元素，因此，应该输出 12。其它情况下的子数组都不多于12个0元素，例如，
	第1~5行与第1~2列构成子数组为第二大数组，含有10个0元素。 
关于输入
	第一行，m 和 n 的值，以空格间隔，m 和 n 均为 不大于 100 的正整数 
	之后，共 m 行，每行共 n 个元素，其间用空格间格。 
关于输出
	输出，最大零元素子二维数组所含的 0 元素个数，如果没有0元素，则输出0。
*/
#include<iostream>
using namespace std;
int m, n, matrix[100][100];
int largest = 0;
void zeroRectangle(int row, int col, int maxc)
{
	if (!maxc)
		return;
	int height = INT_MAX;
	for (int i = 0; i < maxc; i++)
	{
		int temp = 1;
		while (!matrix[row + temp][col + i] && row + temp < m)
			temp++;
		height = height < temp ? height : temp;
	}
	largest = largest > height * maxc ? largest : height * maxc;
	zeroRectangle(row, col, maxc - 1);
}
int main()
{
	int i, j;
	cin >> m >> n;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			cin >> matrix[i][j];
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (!matrix[i][j])
			{
				int temp = j, cnt = 1;
				while (++temp < n)
					if (!matrix[i][temp])
						cnt++;
					else
						break;
				zeroRectangle(i, j, cnt);
			}
	cout << largest << endl;
	return 0;
}
