/*
描述
	把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）
	5，1，1和1，5，1 是同一种分法。
关于输入
	第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
关于输出
	对输入的每组数据M和N，用一行输出相应的K。
*/
#include<iostream>
using namespace std;
int place(int, int, int);
int main()
{
	int t, M, N;
	cin >> t;
	//输入t组测试数据，t为0时退出
	while (t--)
	{
		cin >> M >> N;
		cout << place(M, N, 0) << endl;
	}
	return 0;
}
int place(int m, int n, int t)
{
	int i, cnt = 0;
	//递归结束条件：只剩一个盘子。此时只有一种放置方法
	if (n == 1)
		return 1;	
	//为保证不重复计数，按个数由少到多排列，为保证这一点，“第一个”盘子中的苹果数不能大于平均数
	for (i = t; i <= m / n; i++)
		cnt += place(m - i, n - 1, i);
	return cnt;
}
