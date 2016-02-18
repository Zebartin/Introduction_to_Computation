/*
描述
	有一批易感人群住在网格状的宿舍区内，宿舍区为n*n的矩阵，每个格点为一个房间，房间里可能住人，也可能空着。
	在第一天，有些房间里的人得了流感，以后每天，得流感的人会使其邻居传染上流感，（已经得病的不变），
	空房间不会传染。请输出第m天得流感的人数。
关于输入
	第一行一个数字n，n不超过100，表示有n*n的宿舍房间。 
	接下来的n行，每行n个字符，’.’表示第一天该房间住着健康的人，’#’表示该房间空着，
	’@’表示第一天该房间住着得流感的人。 
	接下来的一行是一个整数m，m不超过100. 
关于输出
	输出第m天，得流感的人数
*/ 
#include<iostream>
using namespace std;
int main()
{
	int i, j, n, m, number = 0;
	char rooms[102][102],temp[102][102];
	int drow[4] = { -1,1,0,0 }, dcol[4] = { 0,0,-1,1 };
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			cin >> rooms[i][j];
			temp[i][j] = rooms[i][j];
		}
	cin >> m;
	for (int day = 0; day < m; day++)
	{
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				rooms[i][j] = temp[i][j];
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (rooms[i][j] == '@')
					for (int k = 0; k < 4; k++)
						if (rooms[i + drow[k]][j + dcol[k]] == '.')
							temp[i + drow[k]][j + dcol[k]] = '@';
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (rooms[i][j] == '@')
				number++;
	cout << number << endl;
	return 0;
}
