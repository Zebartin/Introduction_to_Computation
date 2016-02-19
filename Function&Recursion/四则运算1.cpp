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
#include<cstring>
using namespace std;

char str[400];

void addBrackets(char *s)
{
	char *p = s;
	int f = 0;
	for (; *p != '\0'; p++)
		if (*p == '/' || *p == '*')
		{
			char *t;
			f = 0;
			for (t = p - 1; t - s >= -1; t--)
			{
				switch (*t)
				{
				case '(': 
					char *x;
					for (x = s + strlen(str); x >= t; x--)
						*(x + 1) = *x;
					f = 1;
					p++;
					break;
				case ')':
					char *c;
					c = t - 1;
					for (int lev = 0; lev || *c != '('; --c)
						lev += (*c == ')') - (*c == '(');
					char *z;
					for (z = s + strlen(str); z >= c + 1; z--)
						*(z + 1) = *z;
					*(c + 1) = '(';
					f = 1;
					p++;
					break;
				case '-':
					if (*(t - 1) == '(')
					{
						char *z;
						for (z = s + strlen(str); z >= t - 1; z--)
							*(z + 1) = *z;
						f = 1;
						p++;
						break;
					}
					if (t == s)
					{
						char *z;
						for (z = s + strlen(str); z >= s; z--)
							*(z + 1) = *z;
						*s = '(';
						f = 1;
						p++;
						break;
					}
				case '+':
					char *zp;
					for (zp = s + strlen(str); zp >= t; zp--)
						*(zp + 1) = *zp;
					*(t + 1) = '(';
					f = 1;
					p++;
					break;
				}
				if (t - s == -1)
				{
					char *z;
					for (z = s + strlen(str); z != s - 1; z--)
						*(z + 1) = *z;
					*s = '(';
					f = 1;
					p++;
				}
				if (f)
					break;
			}
			f = 0;
			for (t = p + 1;; t++)
			{
				switch (*t)
				{
				case ')':
					char *x;
					for (x = s + strlen(str); x >= t; x--)
						*(x + 1) = *x;
					f = 1;
					p++;
					break;
				case '(':
					char *c;
					c = t + 1;
					for (int lev = 0; lev || *c != ')'; ++c)
						lev += (*c == ')') - (*c == '(');
					char *z;
					if (*(c + 1))
					{
						for (z = s + strlen(str); z >= c + 1; z--)
							*(z + 1) = *z;
						*(c + 1) = ')';
					}
					else
						*(c + 1) = ')', *(c + 2) = 0;
					f = 1;
					p++;
					break;
				case '-':
				case '+':
					char *zp;
					for (zp = s + strlen(str); zp >= t; zp--)
						*(zp + 1) = *zp;

					*t = ')';
					f = 1;
					p++;
					break;
				}
				if (*t == 0)
					*t = ')', *(t + 1) = 0, f = 1;
				if (f)
					break;
			}
		}
}

int calculate(char *s, char *p)
{
	int result = 0, a = 1;
	for (char *c = p - 1; c >= s; --c)
		switch (*c)
		{
			case '+': 
				return calculate(s, c) + result; 
				a = 1;
				break;
			case '-': 
				return calculate(s, c) - result;
				a = 1;
				break;
			case '*': 
				return calculate(s, c) * result;
				a = 1;
				break;
			case '/': 
				return calculate(s, c) / result; 
				a = 1;
				break;
			case ')':
				a = 1;
				char *p;
				p = c - 1;
				for (int lev = 0; lev || *p != '('; --p)
					lev += (*p == ')') - (*p == '(');
				result = calculate(p + 1, c);
				c = p;
				break;
			default: 
				if (a == 1)
				{
					result = *c - '0';
					a *= 10;
				}
				else
				{
					result += (*c - '0') * a;
					a *= 10;
				}
		}
	return result;
}

int main()
{
	while (1)
	{
		memset(str, 0, sizeof(str));
		cin >> str;
		if (str[0] == 0)
			break;
		addBrackets(str);
		cout << calculate(str, str+strlen(str)) << endl;
	}

	return 0;
}
