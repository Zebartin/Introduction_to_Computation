/*
描述

	有一个N x N（N为奇数，且1<=N<=10）的矩阵，矩阵中的元素都是字符。这个矩阵可能会按照如下的几种变幻法则之一进行变幻（只会变幻一次）。 
	
	现在给出一个原始的矩阵，和一个变幻后的矩阵，请编写一个程序，来判定原始矩阵是按照哪一种法则变幻为目标矩阵的。 
	
	1. 按照顺时针方向旋转90度； 
	如： 
	1 2 3          7 4 1 
	4 5 6  变幻为  8 5 2 
	7 8 9          9 6 3 
	
	2. 按照逆时针方向旋转90度； 
	如： 
	1 2 3          3 6 9 
	4 5 6  变幻为  2 5 8 
	7 8 9          1 4 7 
	
	3. 中央元素不变（如下例中的 5），其他元素（如下例中的3）与“以中央元素为中心的对应元素”（如下例中的7）互换； 
	如： 
	1 2 3          9 8 7 
	4 5 6  变幻为  6 5 4 
	7 8 9          3 2 1 
	
	4. 保持原始矩阵，不变幻； 
	
	5. 如果 从原始矩阵 到 目标矩阵 的变幻，不符合任何上述变幻，请输出5
关于输入
	第一行：矩阵每行/列元素的个数 N； 
	
	第二行到第N+1行：原始矩阵，共N行，每行N个字符； 

	第N+2行到第2*N+1行：目标矩阵，共N行，每行N个字符；
关于输出
	只有一行，从原始矩阵 到 目标矩阵 的所采取的 变幻法则的编号。
*/
#include<iostream>
using namespace std;
int main()
{
	int i, j, f1 = 1, f2 = 1, N;
	char before[10][10], after[10][10];
	cin >> N;
	for (i = 0; i < N * N; i++)
		cin >> before[i / N][i % N];
	for (i = 0; i < N * N; i++)
	{
		cin >> after[i / N][i % N];
		if (before[i / N][i % N] != after[i / N][i % N])
			f1 = 0;
		if (after[i / N][i % N] != before[(N*N - 1 - i) / N][(N*N - 1 - i) % N])
			f2 = 0;
	}
	if (f1)
		cout << 4 << endl;
	else 
		if (f2)
			cout << 3 << endl;
		else
		{
			int f3, f4;
			f3 = f4 = 1;
			for (i = 0; i < N; i++)
				if (f3 || f4)
					for (j = 0; j < N; j++)
					{
						if (f3 && before[i][j] != after[j][N - 1 - i])
							f3 = 0;
						if (f4 && before[i][j] != after[N - 1 - j][i])
							f4 = 0;
					}
			if (f3)
				cout << 1 << endl;
			else
				if (f4)
					cout << 2 << endl;
				else
					cout << 5 << endl;
		}
	return 0;
}
