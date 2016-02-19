/*
描述
	输入一个布尔表达式，请你输出它的真假值。 
	比如：( V | V ) & F & ( F | V ) 
	V表示true，F表示false，&表示与，|表示或，!表示非。 
	上式的结果是F
关于输入
	输入包含多行，每行一个布尔表达式，表达式中可以有空格，总长度不超过1000
关于输出
	对每行输入，如果表达式为真，输出"V",否则出来"F"
例子输入
	( V | V ) & F & ( F| V)
	
	!V | V & V & !F & (F | V ) & (!F | F | !V & V)
	
	(F&F|V|!V&!F&!(F|F&V))
例子输出
	F
	
	V
	
	V
*/
#include<iostream>
using namespace std;
int leftBracket;
char s[1001];

bool judge(char *start, char *end)
{
	char *p = start;
	leftBracket = 0;
	while (end - p)
	{
		switch (*p)
		{
			case '(': leftBracket++; break;
			case ')': leftBracket--; break;
			case '|':
				if (!leftBracket)
					return judge(start, p) || judge(p + 1, end);
				break;
		}
		p++;
	}
	p = start;
	leftBracket = 0;
	while (end - p)
	{
		switch (*p)
		{
			case '(': leftBracket++; break;
			case ')': leftBracket--; break;
			case '&':
				if (!leftBracket)
					return judge(start, p) && judge(p + 1, end);
				break;
		}
		p++;
	}
	switch (*start)
	{
		case 'V': return true;
		case 'F': return false;
		case '!': return !judge(start + 1, end);
		case '(': return judge(start + 1, end - 1);
		case ' ': return judge(start + 1, end);
	}
}
int main()
{
	while (cin.getline(s, 1001))
	{
		if (judge(s, s + strlen(s)))
			cout << "V" << endl;
		else
			cout << "F" << endl;
	}
	return 0;
}
