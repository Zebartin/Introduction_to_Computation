/*
描述
    新年将至，幼儿园的老师们为小朋友们准备了各种各样的糖果。不同的小朋友所喜欢的糖果可能是不同的，
	为了让更多的小朋友得到他/她喜爱的糖果，幼儿园的老师们对小朋友们的“糖果偏好”（即哪位小朋友喜欢哪几种糖果）
	进行了统计。 
    现已知老师们共准备了F（1 ≤ F ≤ 20）种糖果，准备为幼儿园里的N位小朋友（1≤ N ≤20）分配糖果。同上所述，我们假设: 
（1）每位小朋友只会接受自己喜欢的糖果，不接受自己不喜欢的糖果； 
（2）每种糖果只能分给某一位小朋友（即：一旦某种糖果分给某位小朋友，则其他小朋友就不能再被分配到该种糖果）； 
（3）我们不保证所有小朋友都能获得糖果； 
（4）每个小朋友喜欢哪种糖果将在输入数据中给出。 

    请你构造一个程序，帮助老师们分配糖果，以使得在上述条件下，老师们能够将现有糖果分配给最多的小朋友。
	请输出可分到糖果的小朋友的最多的人数。
关于输入
    第1行为两个整数：N 和 F，以空格隔开。其中，N（1≤ N ≤100）表示小朋友的总人数；
	F（1 ≤ F ≤ 100）表示糖果的总种数（糖果种类分别用整数1,2,3,...,F进行编号）。 

    接下来有N行，每行包含多个以空格隔开的整数；其中，第一个整数m，表示某位小朋友所喜爱的糖果的种数，
	其后的m个整数，表示该小朋友所喜爱的糖果种类的编号序列。 
	例如：若某行的输入为“3 1 2 3”，则表示该位小朋友共喜欢3种类型的糖果，其糖果类型编号分别为“1”“2”“3”。
关于输出
	仅一行，即在上述输入条件下，能分到糖果的小朋友的人数的最大值。
*/
#include<iostream>
using namespace std;
int N, F, most = 0;
int table[101][101], haveGotSugar[101];

void divide(int v, int s)
{
	if (v == F + 1)
	{
		most = most > s ? most : s;
		return;
	}
	int i, f = 1;
	for (i = 1; i <= N; i++)
	{
		if (table[i][v])
		{
			f = 0;
			int t;
			if (!(t = haveGotSugar[i]))
				s++;
			haveGotSugar[i] = 1;
			divide(v + 1, s);
			if (!(haveGotSugar[i] = t))
				s--;
		}
	}
	if (f)
		divide(v + 1, s);
}
int main()
{
	int i, m, t;
	memset(table, 0, sizeof(table));
	memset(haveGotSugar, 0, sizeof(haveGotSugar));
	cin >> N >> F;
	for (i = 1; i <= N; i++)
	{
		cin >> m;
		while (m--)
		{
			cin >> t;
			table[i][t] = 1;
		}
	}
	divide(1, 0);
	cout << most << endl;
	return 0;
}
