/*
����
	ʹ��1�ǡ�2�ǡ�5��Ӳ����� n ��Ǯ�� 
	��1�ǡ�2�ǡ�5�ǵ�Ӳ�Ҹ�����a��b��c�����г����п��ܵ�a, b, c��ϡ� 
	���˳��Ϊ����c��ֵ��С����c��ͬ�İ�b��ֵ��С��������� 
	Ҫ�����ʹ�õݹ顣
��������
	����ֻ��һ������n��1 <= n <= 100)��������Ҫ��ɵ�Ǯ�Ľ�����
�������
	����������У�ÿ�е���ʽΪ�� 
	i           a           b           c 
	
	��1��i����ǰ������������001��ʼ���̶�3���ַ���ȣ���Ȳ���3����0��䣩�� 
	����3��a, b, c�ֱ����1�ǡ�2�ǡ�5��Ӳ�ҵĸ�����ÿ�����̶ֹ�12���ַ���ȣ���Ȳ������������ո�
*/
#include<iostream>
#include<iomanip>
using namespace std;
const int money[3] = { 1,2,5 };
int a, cnt = 1, num[3] = { 0 };
void trymoney(int, int);
void output();
int main()
{
	cin >> a;
	trymoney(a, 2);
	return 0;
}
void trymoney(int a, int n)
{
	//�ݹ��������
	if (n == 0)
	{
		num[0] = a / money[0];
		output();
		return;
	}
	//����ֵ��ģ��ٽ�ʣ���Ǯ������ֵ��С�����
	while (num[n] * money[n] <= a)
	{
		trymoney(a - num[n] * money[n], n - 1);
		num[n]++;
	}
	//����
	num[n] = 0;
}
void output()
{
	cout << setw(3) << setfill('0') << cnt++;
	//��ָ�뷽ʽ���
	int *p = num;
	for (; p - num < 3; p++)
		cout << setw(12) << setfill(' ') << *p;
	cout << "\n";
}
