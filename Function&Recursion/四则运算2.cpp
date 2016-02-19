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
