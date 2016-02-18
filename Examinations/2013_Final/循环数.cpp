/*
描述
	当一个N位的整数X满足下列条件时，称其为循环数：X与任意一个整数1≤Y ≤ N相乘时，都将产生一个X的“循环”。
	即：分别将这两个整数的第1位数字与最后1位数字连在一起，可以得到一个相同的数字循环；
	当然两个整数在该数字循环中的起始位置不同。例如，142857是一个循环数 
	142857 *1 = 142857 
	142857 *2 = 285714 
	142857 *3 = 428571 
	142857 *4 = 571428 
	142857 *5 = 714285 
	142857 *6 = 857142
关于输入
	写一个程序判断一个整数是否是循环数。输入文件是一个整数序列，每个整数长度为2~60。注
	意：每个整数前面的零被看作是该整数的一部分，在计算N时要统计。
	例如“01”是一个2位的整数，而“1”是一个1位的整数。
关于输出
	对每个输入整数，输出一行，说明该整数是否是循环数。
*/
#include<iostream>
#include<cstring>
using namespace std;
char s[100];
int number[100];
bool judge(int n)
{
	int j, l = strlen(s);
	int t[130];
	char ns[130];
	memset(t, 0, sizeof(t));
	memset(ns, 0, sizeof(ns));
	int k = 0;
	for (j = l - 1; j >= 0; j--)
		t[k++] = (s[j] - '0') * n;
	for (j = 0; j < l * 2; j++)
	{
		t[j + 1] += t[j] / 10;
		t[j] %= 10;
	}
	j = l * 2;
	while (t[j] == 0)
		j--;
	while (j < l - 1)
		j++;
	k = 0;
	for (; j >= 0; j--)
		ns[k++] = t[j] + '0';
	ns[k] = 0;

	int i, l1 = strlen(s), l2 = strlen(ns);
	char temp[100], rt[100];
	for (i = 0; i < l2; i++)
		if (ns[i] == s[0])
		{
			strcpy_s(temp, ns + i);
			strcpy_s(rt, ns);
			rt[i] = 0;
			strcat_s(temp, rt);
			if (!strcmp(temp, s))
				return true;
		}
	return false;
}

bool multi(int i)
{
	if (i == strlen(s))
		if (judge(i))
			return true;
		else
			return false;
	if (judge(i))
		return multi(i + 1);
	else
		return false;
}
int main()
{
	while (1)
	{
		memset(s, 0, sizeof(s));
		memset(number, 0, sizeof(number));
		cin >> s;
		if (s[0] == 0)
			break;
		if (multi(1))
			cout << s << " is cyclic" << endl;
		else
			cout << s << " is not cyclic" << endl;
	}
	return 0;
}
