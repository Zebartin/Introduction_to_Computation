/*
描述
	海上有一个岛，在环海边上建有一条环岛高速公路，沿着公路有n（5 < n < 10000）个居民点，假设每个居民点有一个编号，从0开始，按顺时针依次从小到大（即，0,1，…，n-1）编号。在岛上啤酒很受青睐。某啤酒企业计划在岛上投资建一个啤酒厂，并根据啤酒需求每天向居住点送啤酒。已知两个相邻的居民点的距离以及每个居住点每天的啤酒需求量（假设每个居住点每天不超过2000桶）。假定每单位长度的路程送一桶啤酒需要的费用恒定（为单位费用）。请问，选择哪一个居民点建啤酒厂，才能使每天送啤酒的费用最小（空车不计费用）。
关于输入
	第一行：为居民点数目n 
	后面为n行，每行为一个居民点的啤酒需求量以及按顺时针离下一个居民点的距离（均为整数,空格间隔），从编号为0的开始，按单增顺次给出。 

	注意：后面第n行对应于居民点（n-1)的啤酒需求量以及到编号为0的居民点距离。 
关于输出
	啤酒厂所在的居民点编号以及每天的运输费用，其间以逗号间隔
*/
#include<iostream>
using namespace std;

int main()
{
	int n, i, j, circle = 0, r[10000][2], sum[10000] = { 0 };
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> r[i][0] >> r[i][1];
		circle += r[i][1];
	}
	int dis, disp;
	for (i = 0; i < n; i++)
	{
		dis = 0;
		for (j = i + 1; j <= n - 1; j++)
		{
			dis += r[j - 1][1];
			disp = dis < (circle - dis) ? dis : (circle - dis);
			sum[i] += disp * r[j][0];
		}
		dis = 0;
		for (j = i - 1; j >= 0; j--)
		{
			dis += r[j][1];
			disp = dis < (circle - dis) ? dis : (circle - dis);
			sum[i] += disp * r[j][0];
		}
	}
	int mark = 0, min = sum[0];
	for (i = 1; i < n; i++)
	{
		mark = min < sum[i] ? mark : i;
		min = min < sum[i] ? min : sum[i];
	}
	cout << mark << "," << min << endl;
	return 0;
}
