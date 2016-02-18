/*
描述
	给定一个矩阵A[m,n](100 ≥ m ≥ 1,100 ≥ n ≥ 1) 和另一个矩阵B[r,s],有0 < r ≤ m, 0 < s ≤ n，A、B所有元素值都是小于100的正整数。求A中和B最匹配的矩阵C[r,s]，所谓最匹配是指B和C的对应元素差值的绝对值之和最小，如果有多个最佳匹配只需输出第一个（行号最小，行号相同时，列号最小）。
关于输入
	第一行是m和n，以空格隔开 
	以下m行每行有n个整数，表示A矩阵中的各行 
	第m+2行为r和s，以空格隔开 
	以下r行每行有s个整数，表示B矩阵中的各行
关于输出
	求出A中和B最匹配的矩阵C并输出之 
	注意：每一个数字后面都有空格，包括一行中的最后一个数字 
*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int m, n, r, s, i, j, p, q;
	int A[100][100], B[100][100], C[100][100] = { 0 };

	cin >> m >> n;
	for (i = 0; i < m * n; i++)
		cin >> A[i / n][i % n];
	
	cin >> r >> s;
	for (j = 0; j < r * s; j++)
		cin >> B[j / s][j % s];
	
	for (i = 0; i <= m - r; i++)
		for (j = 0; j <= n - s; j++)
			for (p = 0; p < r; p++)
				for (q = 0; q < s; q++)
					C[i][j] += abs(A[i + p][j + q] - B[p][q]);
	
	int min = C[0][0], mark[2] = { 0 };

	for (j = 0; j <= n - s; j++)
		for (i = 0; i <= m - r; i++)
		{
			mark[0] = min < C[i][j] ? mark[0] : i;
			mark[1] = min < C[i][j] ? mark[1] : j;
			min = min < C[i][j] ? min : C[i][j];
		}

	for (i = mark[0]; i < mark[0] + r; i++)
		for (j = mark[1]; j < mark[1] + s; j++)
		{
			cout << A[i][j] << " ";
			if (j == mark[1] + s - 1)
				cout << endl;
		}
	return 0;
}
