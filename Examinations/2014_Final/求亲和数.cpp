/*
����
	ңԶ�ĹŴ������Ƿ���ĳЩ��Ȼ��֮��������Ĺ�ϵ�����������a��b��a�����г��������������֮�͵���b,
	b�����г��������������֮�͵���a,���a,b��һ���׺����� 
	���磺220��284����һ���׺��� 
	220�������Ӱ�����1,2,4,5,10,11,20,22,44,55,110. 
	1+2+4+5+10+ 11 + 20 + 22 + 44 + 55 +110 =284 
	284��������:1 + 2 + 4 + 71 + 142 = 220 
	��ô 220��284����һ���׺���.
��������
	һ��������n��1<=n<=100000��
�������
	�����׺�����"a b"������a��b��С�ڵ���n�� 
	ÿ���׺�����ռһ�У�������֮����һ���ո��������С����ǰ���ϴ����ں� 
	���ڶ���׺����ԣ��Խ�С��������˳��������ǡ�
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
