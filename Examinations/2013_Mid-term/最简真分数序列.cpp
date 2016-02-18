/*
描述
	所谓最简真分数是指分子小于分母，且不能约分的分数。给定 n（1 < n < 200）个非负整数（每个整数不超过3位），哪两个整数分别作为分子和分母能够构成最简真分数。输出所有的最简真分数组合；若没有，则输出NO。 
关于输入
	第1行为正整数个数n 
	其后为n个非负整数，空格间隔。
关于输出
	输出所有最简真分数，分子小的排在前面；若分子相同，分母小的排在前面。各分数之间用逗号间隔。 
	若没有，则输出NO
*/
#include<iostream>
using namespace std;
int main()
{
	int n, i, j, swap, temp, mark, flag, a, b, number[200];
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> number[i];
	for (i = 0; i < n - 1; i++)
	{
		swap = 0;
		for (j = 0; j < n - 1 - i; j++)
			if (number[j]>number[j + 1])
			{
				swap = 1;
				temp = number[j + 1];
				number[j + 1] = number[j];
				number[j] = temp;
			}
		if (!swap)
			break;
	}
	mark = 0;
	flag = 0;
	for (i = 0; i < n - 1; i++)
		if (number[i] != 0)
			for (j = i + 1; j < n; j++)
			{
				a = number[i];
				b = number[j];
				while (a != 0)
				{
					temp = b % a;
					b = a;
					a = temp;
				}
				if (b == 1)
				{
					flag = 1;
					if (mark)
						cout << "," << number[i] << "/" << number[j];
					else
					{
						cout << number[i] << "/" << number[j];
						mark = 1;
					}
				}
			}
	if (!flag)
		cout << "NO";
	cout << endl;
	return 0;
}
