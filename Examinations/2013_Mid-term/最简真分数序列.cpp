/*
����
	��ν����������ָ����С�ڷ�ĸ���Ҳ���Լ�ֵķ��������� n��1 < n < 200�����Ǹ�������ÿ������������3λ���������������ֱ���Ϊ���Ӻͷ�ĸ�ܹ���������������������е�����������ϣ���û�У������NO�� 
��������
	��1��Ϊ����������n 
	���Ϊn���Ǹ��������ո�����
�������
	���������������������С������ǰ�棻��������ͬ����ĸС������ǰ�档������֮���ö��ż���� 
	��û�У������NO
*/
#include<iostream>
using namespace std;
int main()
{
	int n, i, j, swap, temp, mark, flag, a, b, number[200];
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> number[i];
	for (i = 0; i < n - 1; i++)
	{
		swap = 0;
		for (j = 0; j < n - 1 - i; j++)
			if (number[j]>number[j + 1])
			{
				swap = 1;
				temp = number[j + 1];
				number[j + 1] = number[j];
				number[j] = temp;
			}
		if (!swap)
			break;
	}
	mark = 0;
	flag = 0;
	for (i = 0; i < n - 1; i++)
		if (number[i] != 0)
			for (j = i + 1; j < n; j++)
			{
				a = number[i];
				b = number[j];
				while (a != 0)
				{
					temp = b % a;
					b = a;
					a = temp;
				}
				if (b == 1)
				{
					flag = 1;
					if (mark)
						cout << "," << number[i] << "/" << number[j];
					else
					{
						cout << number[i] << "/" << number[j];
						mark = 1;
					}
				}
			}
	if (!flag)
		cout << "NO";
	cout << endl;
	return 0;
}
