/*
描述
	遥远的古代，人们发现某些自然数之间有特殊的关系：如果两个数a和b，a的所有除本身以外的因数之和等于b,
	b的所有除本身以外的因数之和等于a,则称a,b是一对亲和数。 
	例如：220和284就是一对亲和数 
	220的真因子包括：1,2,4,5,10,11,20,22,44,55,110. 
	1+2+4+5+10+ 11 + 20 + 22 + 44 + 55 +110 =284 
	284的真因数:1 + 2 + 4 + 71 + 142 = 220 
	那么 220和284就是一对亲和数.
关于输入
	一个正整数n，1<=n<=100000。
关于输出
	所有亲和数对"a b"，满足a和b均小于等于n。 
	每个亲和数对占一行，两个数之间用一个空格隔开，较小数在前，较大数在后。 
	对于多个亲和数对，以较小数递增的顺序输出它们。
*/
#include<iostream>
#include<cmath>
using namespace std;
int mark[1000][2] = { 0 }, cnt = 0;
int crumbleSum(int n)
{
	int i, s = 1, square = (int)sqrt(n);
	for (i = 2; i <= square; i++)
		if (n % i == 0)
			if (square - i)
				s += i + n / i;
			else
				s += i;
	return s;
}

void find(int fir, int sup)
{
	if (fir > sup)
		return;
	int i, f = 1;
	for (i = 0; i < cnt; i++)
		if (mark[i][1] == fir)
		{
			f = 0;
			break;
		}
	if (f)
	{
		int p = crumbleSum(fir);
		if (p < sup && fir - p )
			if(fir == crumbleSum(p))
			{
				mark[cnt][0] = fir;
				mark[cnt++][1] = p;
			}
	}
	find(fir + 1, sup);
}
int main()
{
	int n;
	cin >> n;
	find(220, n);
	for (int i = 0; i < cnt; i++)
		cout << mark[i][0] << " " << mark[i][1] << endl;
	return 0;
}
