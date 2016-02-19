/*
描述
	现在有一个n阶正整数方阵（n<=7），现在可以对矩阵的任意一行进行左移，具体操作为：
	每次对于某一行a_i1,a_i2,…,a_in进行一次左移，最左边的元素移动到这一行的末尾，
	其他元素均向左移动一位，即变为a_i2,a_i3,…,a_in,a_i1。对某一行可以执行任意次的左移。 
	现在我们的目标是：通过对矩阵的每一行进行若干次左移，使得矩阵中每列和的最大值最小。 
关于输入
	输入包含多组数据。 
	对于每组数据，第一行为一个正整数n（1<=n<=7），代表矩阵的阶。接下来的n行，每行n个正整数（不超过10000），
	代表这个矩阵。 
	输入数据以一个-1为结尾代表输入结束。
关于输出
	对于每组数据，输出一行一个正整数，为最小的最大列和。
*/
#include<iostream>
using namespace std;
int matrix[7][7], stuff[117649], addup[7], n, cnt;
void move(int);
int max(int[]);
int min(int[]);
int main()
{
	while (cin >> n)
	{
		cnt = 0;
		memset(addup, 0, sizeof(addup));
		memset(stuff, 0, sizeof(stuff));

		if (n == -1)
			break;

		int i;
		for (i = 0; i < n * n; i++)
		{
			//输入矩阵
			cin >> matrix[i / n][i % n];
			//第一行不左移
			if (i < n)
				addup[i] = matrix[0][i];
		}
		//从第二行开始左移
		move(1);
		//输出最大和的最小值
		cout << min(stuff) << endl;
	}
	return 0;
}
void move(int row)
{
	int i, j, temp[7];
	//到最后一行时递归结束，求得一个最大列和
	if (row == n)
	{
		stuff[cnt++] = max(addup);
		return;
	}
	//i为左移列数
	for (i = 0; i < n; i++)
	{
		//j为左移后的列号
		for (j = 0; j < n; j++)
		{
			temp[j] = addup[j];                    //便于回溯
			addup[j] += matrix[row][(j + i) % n];  //求和
		}
		//没到最后一行则继续下一行
		move(row + 1);
		//回溯
		for (j = 0; j < n; j++)
			addup[j] = temp[j];
	}
}
int max(int a[7])
{
	//求最大值
	int i, k = a[0];
	for (i = 1; i < n; i++)
		k = k > a[i] ? k : a[i];
	return k;
}
int min(int a[117649])
{
	//求最小值
	int i, k = a[0];
	for (i = 1; i < cnt; i++)
		k = k < a[i] ? k : a[i];
	return k;
}
