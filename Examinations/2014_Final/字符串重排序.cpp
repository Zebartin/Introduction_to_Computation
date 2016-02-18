/*
描述
	判断一个字符串是否可以由另一个字符通过重排字符而得到。注意，此处区分字符大小写！
关于输入
	输入只有一行，为两个字符串，字符串之间以一个空格分隔。
关于输出
	如果两个字符串由同一组字符组成（且每一个字符出现次数相同），则输出“YES”； 
	否则输出“NO”。注意YES和NO都是大写字母！
*/
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int i, j, l1, l2, mark[1000] = { 0 };
	char str1[1000], str2[1000];
	cin >> str1 >> str2;
	l1 = strlen(str1);
	l2 = strlen(str2);
	if (l1 - l2)
		cout << "NO" << endl;
	else
	{
		int f = 1;
		for (i = 0; i < l1; i++)
			if (f)
			{
				for (j = 0; j < l2; j++)
					if (str2[j] == str1[i] && !mark[j])
					{
						mark[j] = 1;
						break;
					}
				if (!(j - l2))
					f = 0;
			}
		if ((j - l2) && !(i - l1))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
