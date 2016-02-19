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

char s[1001];

bool eval(char *start, char *end)
{
	bool val = false;
	for (char *c = end - 1; c >= start; --c)
	{
		if (*c == 'V')
			val = true;
		else if (*c == '&')
			return eval(start, c) && val;
		else if (*c == '|')
			return eval(start, c) || val;
		else if (*c == ')')
		{
			char *p = c - 1;
			for (int lev = 0; lev || *p != '('; --p)
				lev += (*p == ')') - (*p == '(');
			val = eval(p + 1, c);
			c = p;
		}
		else if (*c == '!')
			val = !val;
	}
	return val;
}

int main()
{
	while (cin.getline(s, 1001))
		if (eval(s, s + strlen(s)))
			cout << "V" << endl;
		else
			cout << "F" << endl;
}
