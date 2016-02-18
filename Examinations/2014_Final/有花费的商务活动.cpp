/*
����
	һ��������ԱҪ�μ�һ���ǳ���Ҫ��������;����Ҫ����һ�� N*N �������ε����񡣴������ε�һ���ǽ��룬
	����ŵ���һ���ǳ�ȥ���ٶ������Ͻǽ������½ǳ���N ������50 ����ÿ��Խ�м�1��С���񣬶���Ҫ����һ���Ĺ�·�ѣ�
	ͬʱ�μ���һ�Ҳ��Ҫ�����볡Ʊ��������������ķ������ޡ����������������ķ��ã��볡���Լ���Խ����ķ��ã�
	��æ�ж�������ܷ�μ��ⳡ���������ܹ��������YES���������NO 
	
	ע�⣺���ܶԽǴ�Խ����С���񣨼���ֻ���кŻ��к�֮һ����1����
��������
	�����ʽ���£� 
	��1�У�Ҫ��Խ�ķ����СN���������ܷ��ã��볡���ã�����֮���Կո��� 
	���� N �� N �У���Խ����С��������ķ��á� 
	
	���� 
	
	�磺 
	5 129 20 
	1  4  6  8  10 
	2  5  7  15 17 
	6  8  9  18 20 
	10 11 12 19 21 
	20 23 25 29 33
�������
	������������μӣ������ 
	YES 
	
	������������μӣ������ 
	NO 
	
	�磬���������У� 
	��Խ�������СֵΪ 109 = 1 + 2 + 5 + 7 + 9 + 12 + 19 + 21 + 33 
	ͬʱ���볡��Ϊ 20���� 20+109 =129 �������������ܷ��� 129����ˣ����Բμӡ� 
	Ӧ������� 
	
	YES 
	
	���ǣ����������������129�������볡�ѳ���20�����޷��μӡ�
*/
#include<iostream>
#include<cstring>
using namespace std;
int N, square[50][50], moneyC[50][50];
void input();
int moneyCost(int, int);
int main()
{
	int bring, entry;
	memset(moneyC, 0, sizeof(moneyC));
	cin >> N >> bring >> entry;
	input();
	if (moneyCost(N - 1, N - 1) +entry <= bring)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
void input()
{
	int i;
	for (i = 0; i < N * N; i++)
		cin >> square[i / N][i % N];
}
int moneyCost(int row, int col)
{
	if (moneyC[row][col])
		return moneyC[row][col];
	if (row&&col)
	{
		int min(int, int);
		moneyC[row][col] = min(moneyCost(row - 1, col), moneyCost(row, col - 1)) + square[row][col];
		return moneyC[row][col];
	}
	else
	{
		if (!(col || row))
		{
			moneyC[row][col] = square[row][col];
			return moneyC[row][col];
		}
		else
			if (!row)
			{
				moneyC[row][col] = square[row][col] + moneyCost(row, col - 1);
				return moneyC[row][col];
			}
			else
			{
				moneyC[row][col] = square[row][col] + moneyCost(row - 1, col);
				return moneyC[row][col];
			}
	}
}
int min(int a, int b)
{
	return a < b ? a : b;
}
