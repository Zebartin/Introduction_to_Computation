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
