/*
����
	ÿ���³���С�������յ��й��ƶ��Ŀ۷�֪ͨ��С����ϲ����绰��ÿ���µĵ绰�Ѷ��ܶ࣬������ȥ�����Ż��ײ͡�����С������´���n�ε绰��С������ѡ�񲻽�����s�ε绰�Ļ��ѡ�С�����������ܲ��������һ�����������Ҫ�����ٻ��ѡ�
��������
	����������У���һ��Ϊ����´�ĵ绰��n��������ѵĵ绰��s������0 < s,n <100���ڶ��а���n������Ϊÿ�ε绰�Ļ��ѡ�ÿ���еĶ�������֮����ѿո����� 
�������
	���ֻ��һ�У�ΪС�����������Ҫ���Ļ��ѣ�����1λС������
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
