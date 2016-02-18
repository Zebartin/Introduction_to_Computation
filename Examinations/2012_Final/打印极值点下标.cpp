/*
描述
	在一个整数数组上，对于下标为i的整数，如果它大于所有它相邻的整数，
	或者小于所有它相邻的整数，则称为该整数为一个极值点，极值点的下标就是i。
关于输入
	有2×n+1行输入：第一行是要处理的数组的个数n，n<1000；对其余2×n行，第一行是此数组的元素个数k(4<k<80)，
	第二行是k个整数，每两个整数之间用空格分隔。
关于输出
	输出为n行：每行对应于相应数组的所有极值点下标值，下标值之间用空格分隔，从小到大输出。
*/
#include<iostream>
using namespace std;
int main()
{
	int i, n, k, number[79];
	cin >> n;
	while (n--)
	{
		int flag = 0;
		cin >> k;
		i = 0;
		while (k--)
			cin >> number[i++];
		if (number[0] != number[1])
		{
			cout << 0;
			flag = 1;
		}
		for (k = 1; k < i - 1; k++)
			if ((number[k] - number[k + 1])*(number[k] - number[k - 1]) > 0)
				if (flag)
					cout << " " << k;
				else
					cout << k, flag = 1;
		if (number[i - 1] != number[i - 2])
			if (flag)
				cout << " " << i - 1;
			else
				cout << i - 1;
		cout << endl;
	}
	return 0;
}
