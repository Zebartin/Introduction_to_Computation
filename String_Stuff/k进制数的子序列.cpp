/*
描述
	任意给定一个k（其中，k 大于1小于10）进制的数（不超过30位，且第一位不为0），以此为基点，
	按增1的方式连续输出后面的m个k进制数，其间以逗号间隔,这里，m为正整数。输出的每个数第一位不能为0，
	每行输出5个数，最后一行可以少于5个。 
	
	例如，给定12位的5进制数：321234232132，后面的6个数依次为： 
	
	321234232133,321234232134,321234232140,321234232141,321234232142,321234232143 
	
	如果输出6个数，则应该是： 
	
	321234232133,321234232134,321234232140,321234232141,321234232142 
	321234232143
关于输入
	输入三个数k,m,和k进制数，三个数之间以逗号间隔，k进制数不超过30位，m为正整数。 
关于输出
	输出后续的m个数，每行5个数（每行的最后一个数之后没有逗号），最后一行可以少于5个数。
*/
#include<iostream>
using namespace std;
int num[31] = { 0 };
void calculator(int, char[] );
void output();
int main()
{
	int m, i, j, k, f1, f2, len;
	char integer[31], comma;
	cin >> k >> comma >> m >> comma >> integer;
	len = strlen(integer);
	for (i = len - 1, j = 0; i >= 0; i--, j++)
		num[j] = integer[i] - '0';
	f1 = 1;
	f2 = 1;
	for (i = 0; i < m; i++)
	{
		calculator(k, integer);
		output();
		if (i % 5 == 4 || i == m - 1)
			f2 = 0;
		if (f1)
		{
			f1 = 0;
			if (f2)
				cout << ",";
			else
				cout << "\n";
		}
		else
			if (f2)
				cout << ",";
			else
			{
				cout << "\n";
				f2 = 1;
				f1 = 1;
			}
	}
	return 0;
}
void calculator(int k,char integer[31])
{
	int i, j, len = strlen(integer);
	num[0] += 1;
	for (j = 0; j <= len; j++)
		if (num[j] == k)
		{
			num[j] = 0;
			num[j + 1] += 1;
		}
		else
			break;
}
void output()
{
	int j = 30;
	while (num[j] == 0)
		j--;
	for (; j >= 0; j--)
		cout << num[j];
}
