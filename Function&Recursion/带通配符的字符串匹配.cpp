/*
描述
	通配符是一类键盘字符，当我们不知道真正字符或者不想键入完整名字时，常常使用通配符代替一个或多个真正字符。
	通配符有问号(?)和星号(*)等，其中，“?”可以代替一个字符，而“*”可以代替零个或多个字符。 
	
	你的任务是，给出一个带有通配符的字符串和一个不带通配符的字符串，判断他们是否能够匹配。 
	
	例如，1?456 可以匹配 12456、13456、1a456，但是却不能够匹配23456、1aa456； 
	2*77?8可以匹配 24457798、237708、27798。
关于输入
	输入有两行，每行为一个不超过20个字符的字符串，第一行带通配符，第二行不带通配符
关于输出
	如果两者可以匹配，就输出“matched”，否则输出“not matched”
例子输入
	1*456?

	11111114567
例子输出
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
