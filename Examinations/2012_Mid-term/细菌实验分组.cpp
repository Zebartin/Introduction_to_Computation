/*
����
	��һ��ϸ����ΪA��B�������֣����ǵ���������������ȫ��ͬ�������ڷ�ֳ���������������A���ַ�ֳ�����ǳ�ǿ��B���ֵķ�ֳ������������һ��Ϊʱһ��Сʱ��ϸ����ֳʵ���У�ʵ��Ա���������ϸ������������ˣ������дһ�����򣬸���ʵ���������������ֵ����������·ֳ����顣
��������
	�����ж��У���һ��Ϊ����n��n��100������ʾ��n�������� 
	����n�У�ÿ���������������ֱ�����������ţ�����ǰϸ�������������ϸ��������
�������
	����ж��У� 
	��һ�����A��������������������ÿ�����A����������ı�ţ�����ֳ���������С� 
	Ȼ��һ�����B��������������������ÿ�����B����������ı�ţ�Ҳ����ֳ���������С� 
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
