/*
描述
	输入一个包括+、-、*、/和()的四则运算表达式，你能算出表达式的值吗？ 
	
	这个表达式满足： 
	1、没有括号不匹配的情况，但可能有嵌套的情形 
	2、操作数均为整数，但需考虑正负数 
	3、没有非法表达式，也没有零作除数的情况 
	4、所有操作都可以视为整型计算，不考虑分数和小数的情况 
	5、中间结果和最终结果不会超出int的表示范围
关于输入
	若干行，每行为一个合法的四则运算表达式
关于输出
		若干行，为对应的运算结果
	例子输入
	1+3+5
	
	5*(3+7)
	
	-(-4/(1+3))*5-1*2*3

例子输出
	9
	
	50
	
	-1
*/
//此版思路是强行加上括号从而用布尔表达式的方法解决
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
