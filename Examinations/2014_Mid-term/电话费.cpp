/*
描述
	每到月初，小明都会收到中国移动的扣费通知。小明很喜欢打电话，每个月的电话费都很多，所以他去办了优惠套餐。假设小明这个月打了n次电话，小明可以选择不交其中s次电话的话费。小明算术能力很差，请帮帮他算一下这个月最少要交多少话费。
关于输入
	输入包含两行：第一行为这个月打的电话数n，可以免费的电话数s，其中0 < s,n <100；第二行包含n个数，为每次电话的话费。每行中的二个数据之间均已空格间隔。 
关于输出
	输出只有一行，为小明这个月最少要交的话费（保留1位小数）。
*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	bool swap;
	int n, s, i, j;
	double dtemp, sum = 0, cost[99];
	cin >> n >> s;
	for (i = 0; i < n; i++)
		cin >> cost[i];
	for (i = 0; i < n - 1; i++)
	{
		swap = 0;
		for (j = 0; j < n - 1 - i; j++)
			if (cost[j]>cost[j + 1])
			{
				dtemp = cost[j + 1];
				cost[j + 1] = cost[j];
				cost[j] = dtemp;
				swap = 1;
			}
		if (!swap)
			break;
	}
	for (i = 0; i < n - s; i++)
		sum += cost[i];
	cout << fixed << setprecision(1) << sum << endl;
	return 0;
}
