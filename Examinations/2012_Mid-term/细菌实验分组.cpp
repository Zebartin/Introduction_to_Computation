/*
描述
	有一种细菌分为A、B两个亚种，它们的外在特征几乎完全相同，仅仅在繁殖能力上有显著差别，A亚种繁殖能力非常强，B亚种的繁殖能力很弱。在一次为时一个小时的细菌繁殖实验中，实验员由于疏忽把细菌培养皿搞乱了，请你编写一个程序，根据实验结果，把两个亚种的培养皿重新分成两组。
关于输入
	输入有多行，第一行为整数n（n≤100），表示有n个培养皿。 
	其余n行，每行有三个整数，分别代表培养皿编号，试验前细菌数量，试验后细菌数量。
关于输出
	输出有多行： 
	第一行输出A亚种培养皿的数量，其后每行输出A亚种培养皿的编号，按繁殖率升序排列。 
	然后一行输出B亚种培养皿的数量，其后每行输出B亚种培养皿的编号，也按繁殖率升序排列。 
*/
#include<iostream>
using namespace std;
int main()
{
	int i, j, swap, itemp;
	int n, bac[100][3];
	double dtemp, multip[100];
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> bac[i][0] >> bac[i][1] >> bac[i][2];
		multip[i] = double(bac[i][2]) / bac[i][1];
	}
	for (i = 0; i < n - 1; i++)
	{
		swap = 0;
		for (j = 0; j < n - i - 1; j++)
			if (multip[j] > multip[j + 1])
			{
				swap = 1;
				dtemp = multip[j];
				multip[j] = multip[j + 1];
				multip[j + 1] = dtemp;
				itemp = bac[j][0];
				bac[j][0] = bac[j + 1][0];
				bac[j + 1][0] = itemp;
			}
		if (!swap)
			break;
	}
	int low = 0, high = n - 1, mid = (low + high) / 2;
	while (high != low + 1)
	{
		if (multip[mid] - multip[low] >= multip[high] - multip[mid])
		{
			high = mid;
			mid = (low + high) / 2;
		}
		if (multip[mid] - multip[low] < multip[high] - multip[mid])
		{
			low = mid;
			mid = (low + high) / 2;
		}
	}
	int num_A = n - high, num_B = low + 1;
	cout << num_A << endl;
	for (i = high; i < n; i++)
		cout << bac[i][0] << endl;
	cout << num_B << endl;
	for (i = 0; i <= low; i++)
		cout << bac[i][0] << endl;
	return 0;
}
