/*
����
	ͨ�����һ������ַ��������ǲ�֪�������ַ����߲��������������ʱ������ʹ��ͨ�������һ�����������ַ���
	ͨ������ʺ�(?)���Ǻ�(*)�ȣ����У���?�����Դ���һ���ַ�������*�����Դ�����������ַ��� 
	
	��������ǣ�����һ������ͨ������ַ�����һ������ͨ������ַ������ж������Ƿ��ܹ�ƥ�䡣 
	
	���磬1?456 ����ƥ�� 12456��13456��1a456������ȴ���ܹ�ƥ��23456��1aa456�� 
	2*77?8����ƥ�� 24457798��237708��27798��
��������
	���������У�ÿ��Ϊһ��������20���ַ����ַ�������һ�д�ͨ������ڶ��в���ͨ���
�������
	������߿���ƥ�䣬�������matched�������������not matched��
��������
	1*456?

	11111114567
�������
	matched
*/
#include<iostream>
using namespace std;
bool judge(char[], char[]);
int main()
{
	char s1[21], s2[21];
	cin >> s1 >> s2;
	if (judge(s1, s2))
		cout << "matched" << endl;
	else
		cout << "not matched" << endl;
	return 0;
}
bool judge(char a[21], char b[21])
{
	switch (a[0])
	{
	case '\0':
		return b[0] == '\0';
	case '?':
		if (b[0] == '\0')
			return false;
		return judge(a + 1, b + 1);
	case '*':
		if (b[0] == '\0')
			return true;
		int i, l;
		l = strlen(b);
		for (i = 0; i <= l; i++)
			if (judge(a + 1, b + i))
				return true;
		return false;
	default:
		if (a[0] == b[0])
			return judge(a + 1, b + 1);
		else
			return false;
	}
}
