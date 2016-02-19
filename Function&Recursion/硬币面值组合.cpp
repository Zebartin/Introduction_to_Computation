/*
描述
	使用1角、2角、5角硬币组成 n 角钱。 
	设1角、2角、5角的硬币各用了a、b、c个，列出所有可能的a, b, c组合。 
	输出顺序为，按c的值从小到大，c相同的按b的值从小到大输出。 
	要求必须使用递归。
关于输入
	输入只有一个整数n（1 <= n <= 100)，代表需要组成的钱的角数。
关于输出
	输出有若干行，每行的形式为： 
	i           a           b           c 
	
	第1列i代表当前行数（行数从001开始，固定3个字符宽度，宽度不足3的用0填充）， 
	后面3列a, b, c分别代表1角、2角、5角硬币的个数（每个数字固定12个字符宽度，宽度不足的在左边填充空格）
*/
#include<iostream>
#include<iomanip>
using namespace std;
const int money[3] = { 1,2,5 };
int a, cnt = 1, num[3] = { 0 };
void trymoney(int, int);
void output();
int main()
{
	cin >> a;
	trymoney(a, 2);
	return 0;
}
void trymoney(int a, int n)
{
	//递归结束条件
	if (n == 0)
	{
		num[0] = a / money[0];
		output();
		return;
	}
	//分面值大的，再将剩余的钱数用面值较小的组合
	while (num[n] * money[n] <= a)
	{
		trymoney(a - num[n] * money[n], n - 1);
		num[n]++;
	}
	//回溯
	num[n] = 0;
}
void output()
{
	cout << setw(3) << setfill('0') << cnt++;
	//按指针方式输出
	int *p = num;
	for (; p - num < 3; p++)
		cout << setw(12) << setfill(' ') << *p;
	cout << "\n";
}
