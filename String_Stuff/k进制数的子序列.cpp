/*
����
	�������һ��k�����У�k ����1С��10�����Ƶ�����������30λ���ҵ�һλ��Ϊ0�����Դ�Ϊ���㣬
	����1�ķ�ʽ������������m��k������������Զ��ż��,���mΪ�������������ÿ������һλ����Ϊ0��
	ÿ�����5���������һ�п�������5���� 
	
	���磬����12λ��5��������321234232132�������6��������Ϊ�� 
	
	321234232133,321234232134,321234232140,321234232141,321234232142,321234232143 
	
	������6��������Ӧ���ǣ� 
	
	321234232133,321234232134,321234232140,321234232141,321234232142 
	321234232143
��������
	����������k,m,��k��������������֮���Զ��ż����k������������30λ��mΪ�������� 
�������
	���������m������ÿ��5������ÿ�е����һ����֮��û�ж��ţ������һ�п�������5������
*/
#include<iostream>
using namespace std;
int num[31] = { 0 };
void calculator(int, char[] );
void output();
int main()
{
	int m, i, j, k, f1, f2, len;
	char integer[31], comma;
	cin >> k >> comma >> m >> comma >> integer;
	len = strlen(integer);
	for (i = len - 1, j = 0; i >= 0; i--, j++)
		num[j] = integer[i] - '0';
	f1 = 1;
	f2 = 1;
	for (i = 0; i < m; i++)
	{
		calculator(k, integer);
		output();
		if (i % 5 == 4 || i == m - 1)
			f2 = 0;
		if (f1)
		{
			f1 = 0;
			if (f2)
				cout << ",";
			else
				cout << "\n";
		}
		else
			if (f2)
				cout << ",";
			else
			{
				cout << "\n";
				f2 = 1;
				f1 = 1;
			}
	}
	return 0;
}
void calculator(int k,char integer[31])
{
	int i, j, len = strlen(integer);
	num[0] += 1;
	for (j = 0; j <= len; j++)
		if (num[j] == k)
		{
			num[j] = 0;
			num[j + 1] += 1;
		}
		else
			break;
}
void output()
{
	int j = 30;
	while (num[j] == 0)
		j--;
	for (; j >= 0; j--)
		cout << num[j];
}
