/*
����
	����һ������+��-��*��/��()������������ʽ������������ʽ��ֵ�� 
	
	������ʽ���㣺 
	1��û�����Ų�ƥ����������������Ƕ�׵����� 
	2����������Ϊ���������迼�������� 
	3��û�зǷ����ʽ��Ҳû��������������� 
	4�����в�����������Ϊ���ͼ��㣬�����Ƿ�����С������� 
	5���м��������ս�����ᳬ��int�ı�ʾ��Χ
��������
	�����У�ÿ��Ϊһ���Ϸ�������������ʽ
�������
		�����У�Ϊ��Ӧ��������
	��������
	1+3+5
	
	5*(3+7)
	
	-(-4/(1+3))*5-1*2*3

�������
	9
	
	50
	
	-1
*/
#include<iostream>
using namespace std;
char s[1001];

double calculate(char *start, char *end)
{
	char *p;
	int leftBracket = 0;
	for (p = start; end - p; p++)
		switch (*p)
		{
			case '(': leftBracket++; break;
			case ')': leftBracket--; break;
			case '+':
				if(!leftBracket)
					if (!(p == start || *(p - 1) == '('))
						return calculate(start, p) + calculate(p + 1, end);
		}
	leftBracket = 0;
	for (p = start; end - p; p++)
		switch (*p)
		{
		case '(': leftBracket++; break;
		case ')': leftBracket--; break;
		case '-':
			if (!leftBracket)
				if (!(p == start || *(p - 1) == '('))
					return calculate(start, p) - calculate(p + 1, end);
		}
	leftBracket = 0;
	for (p = start; end - p; p++)
		switch (*p)
		{
			case '(': leftBracket++; break;
			case ')': leftBracket--; break;
			case '*': 
				if (!leftBracket)
					return calculate(start, p) * calculate(p + 1, end);
		}
	leftBracket = 0;
	for (p = start; end - p; p++)
		switch (*p)
		{
		case '(': leftBracket++; break;
		case ')': leftBracket--; break;
		case '/':
			if (!leftBracket)
				return calculate(start, p) / calculate(p + 1, end);
		}
	switch (*start)
	{
		case '(': return calculate(start + 1, end - 1);
		case '-': return -calculate(start + 1, end);
		case '+': return calculate(start + 1, end);
		default:
			int value = 0;
			for (p = start; *p >= '0' && *p <= '9'; p++)
			{
				value *= 10;
				value += *p - '0';
			}
			return value;
	}
}
int main()
{
	while (cin.getline(s, 1001))
		if (s[0])
			cout << calculate(s, s + strlen(s)) << endl;
	return 0;
}
