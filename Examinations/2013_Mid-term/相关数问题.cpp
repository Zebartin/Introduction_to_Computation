/*
����
	�г�һ������10��99֮���������������ָ������3��5��7����ص�������ν���������7Ϊ��������Щ��λ��/��ʮλ�ϰ���7���������ܱ�7������������
��������
	��һ��������n������n��ÿ��һ��������10��99֮������������һ��Ϊָ������3��5��7����������n+2�У�
�������
	����ж��С�������˳�����������ָ������ص��������ÿ��������һ�С�
*/
#include<iostream>
using namespace std;
int main()
{
	int integer[90], relevant[90], n, k, i, j = 0;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> integer[i];
	cin >> k;
	for (i = 0; i < n; i++)
	{
		if (integer[i] % k == 0 || integer[i] % 10 == k || integer[i] / 10 == k)
			relevant[j++] = integer[i];
	}
	int num = j;
	for (j = 0; j < num; j++)
		cout << relevant[j] << '\n' << endl;
	return 0;
}
