/*
����
	�ڼ���������У����������ʹ���ַ��������ڲ�ͬ���ַ�����������ϣ���ܹ��а취�ж������ƶȡ�
	��ˣ����Ƕ�����һ�ײ�����������������ͬ���ַ��������ͬ�� 
	
	�����ѡ�Ĳ��������У� 
	1. �޸�һ���ַ������罫"a"�޸�Ϊ"b"�� 
	2. ����һ���ַ������罫"abdd"��Ϊ"aebdd" 
	3. ɾ��һ���ַ������罫"travelling"��Ϊ"traveling" 
	
	���磬���������ַ���"abcdefg"��"abcdef"�����ַ�����˵�����ǿ���ͨ������ǰһ���ַ�������һ��g��
	���ߡ�����һ���ַ�������һ��g�������ַ�ʽ��ʹ��������ͬ�������ַ�����������Ҫһ�β����� 
	
	���޸��ַ���������Ҫ�Ĵ�������Ϊ�����ַ���֮��ľ��룬�����ƶȵ��ڡ�����+1���ĵ��������磬
	������"abcdefg"��"abcdef"�ľ���Ϊ1���������ƶ�Ϊ1/2=0.5. 
	
	�������������ַ���(����20����)��д��һ��������������ǵ����ƶȡ� 

��������
	��һ����һ������n����ʾ�������ݵ������� 
	��������n�У�ÿ�������ַ������ÿո��������ʾҪ�������������ַ��� 
	�ַ������Ȳ�����20��
�������
	���ÿһ�����������������ַ��������ƶȣ�����С�����6λ��
*/
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
char str1[21], str2[21];

int compare(char *p1, char *p2)
{
	if (!*p2)
		return 1 + strlen(str1) - (p1 - str1);
	if (!*p1)
		return 1 + strlen(str2) - (p2 - str2);
	if (*p1 == *p2)
		return compare(p1 + 1, p2 + 1);
	else
	{
		int s1 = 1 + compare(p1, p2 + 1);
		int s2 = 1 + compare(p1 + 1, p2 + 1);
		return s1 < s2 ? s1 : s2;
	}
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		cin >> str1 >> str2;
		if (strlen(str1) > strlen(str2))
		{
			char temp[21];
			strcpy(temp, str1);
			strcpy(str1, str2);
			strcpy(str2, temp);
		}
		cout << fixed << setprecision(6) << 1.0 / compare(str1, str2) << endl;
	}

	return 0;
}
