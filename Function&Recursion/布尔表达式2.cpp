/*
����
	����һ���������ʽ����������������ֵ�� 
	���磺( V | V ) & F & ( F | V ) 
	V��ʾtrue��F��ʾfalse��&��ʾ�룬|��ʾ��!��ʾ�ǡ� 
	��ʽ�Ľ����F
��������
	����������У�ÿ��һ���������ʽ�����ʽ�п����пո��ܳ��Ȳ�����1000
�������
	��ÿ�����룬������ʽΪ�棬���"V",�������"F"
��������
	( V | V ) & F & ( F| V)
	
	!V | V & V & !F & (F | V ) & (!F | F | !V & V)
	
	(F&F|V|!V&!F&!(F|F&V))
�������
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
