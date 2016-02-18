/*
描述
	大家一定玩过炸弹人游戏吧，一个炸弹一放形成一个十字破坏。 
	给定一个MxN的 (M<=100, N<=100)的整数矩阵，如果一个元素为0， 
	表明该点有炸弹，则将该点所在的行和列上所有元素均设置为0。
关于输入
	输入为M, N, 和 M*N个整数。
关于输出
	输出为炸弹爆炸后的矩阵。
*/
#include<iostream>
using namespace std;
int main()
{
	int rec[100][100], rectemp[100][100], M, N, i, j;
	cin >> M >> N;
	for (i = 0; i < M * N; i++)
	{
		cin >> rec[i / N][i % N];
		rectemp[i / N][i % N] = rec[i / N][i % N];
	}
	for (i = 0; i < M * N; i++)
		if (rectemp[i / N][i % N] == 0)
		{
			for (j = 0; j < N; j++)
				rec[i / N][j] = 0;
			for (j = 0; j < M; j++)
				rec[j][i % N] = 0;
		}
	for (i = 0; i < M * N; i++)
	{
		if (i % N < N - 1)
			cout << rec[i / N][i % N] << " ";
		else
			cout << rec[i / N][i % N] << "\n";
	}
	return 0;
}
