/*
����
	��һ�����������ϣ������±�Ϊi��������������������������ڵ�������
	����С�����������ڵ����������Ϊ������Ϊһ����ֵ�㣬��ֵ����±����i��
��������
	��2��n+1�����룺��һ����Ҫ���������ĸ���n��n<1000��������2��n�У���һ���Ǵ������Ԫ�ظ���k(4<k<80)��
	�ڶ�����k��������ÿ��������֮���ÿո�ָ���
�������
	���Ϊn�У�ÿ�ж�Ӧ����Ӧ��������м�ֵ���±�ֵ���±�ֵ֮���ÿո�ָ�����С���������
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
