/*
描述
	一个商务人员要参加一个非常重要的商务活动，途中需要穿过一个 N*N 的正方形的网格。从正方形的一个角进入，
	相对着的另一个角出去（假定从左上角进，右下角出，N 不大于50 ）。每穿越中间1个小方格，都需要缴纳一定的过路费，
	同时参加这一活动也需要购买入场票。但这个人所带的费用有限。请根据这个人所带的费用，入场费以及穿越网格的费用，
	帮忙判断这个人能否参加这场商务活动。若能够，则输出YES，否则，输出NO 
	
	注意：不能对角穿越各个小方格（即，只能行号或列号之一增减1）。
关于输入
	输入格式如下： 
	第1行：要穿越的方阵大小N，所带的总费用，入场费用，三者之间以空格间隔 
	后面 N 行 N 列，穿越各个小方格所需的费用。 
	
	例如 
	
	如： 
	5 129 20 
	1  4  6  8  10 
	2  5  7  15 17 
	6  8  9  18 20 
	10 11 12 19 21 
	20 23 25 29 33
关于输出
	如果可以正常参加，则输出 
	YES 
	
	如果不能正常参加，则输出 
	NO 
	
	如，上述例子中： 
	穿越方阵的最小值为 109 = 1 + 2 + 5 + 7 + 9 + 12 + 19 + 21 + 33 
	同时，入场费为 20，而 20+109 =129 不高于所带的总费用 129，因此，可以参加。 
	应该输出： 
	
	YES 
	
	但是，如果所带费用少于129，或者入场费超过20，则无法参加。
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
