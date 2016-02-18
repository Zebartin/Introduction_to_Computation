/*
描述
	有一个小型的报账系统，它有如下功能： 
	（1）统计每个人所报发票的总钱数 
	（2）统计每类发票的总钱数 
	将此系统简化为如下：假设发票类别共有A、B、C三种;一共有三个人，ID分别为1、2、3。
关于输入
	系统输入包含三行，每行第一个数为人员ID（整型，1或2或3），第二个数为发票总张数(张数不超过100)，
	之后是多个发票类别（字符型，A或B或C）和相应发票金额（单进度浮点型,不超过1000.0）。 
关于输出
	输出包含六行，前三行为每人（按ID由小到大输出）所报发票总钱数（保留两位小数），后
	三行为每类发票的总钱数（保留两位小数）。
*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	char type;
	double money;
	int i, j, ID, n;
	double sum[2][3] = { 0 };
	for (i = 0; i < 3; i++)
	{
		cin >> ID >> n;
		for (j = 0; j < n; j++)
		{
			cin >> type >> money;
			sum[0][type - 'A'] += money;
			sum[1][ID - 1] += money;
		}
	}
	for (i = 0; i < 3; i++)
		cout << i + 1 << " " << fixed << setprecision(2) << sum[1][i] << endl;
	for (i = 0; i < 3; i++)
		cout << char(i + 'A') << " " << sum[0][i] << endl;
	return 0;
}
