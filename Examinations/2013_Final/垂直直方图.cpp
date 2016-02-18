/*
描述
	输入4行全部由大写字母组成的文本，输出一个垂直直方图，给出每个字符出现的次数。
	注意：只用输出字符的出现次数，不用输出空白字符，数字或者标点符号的输出次数。
关于输入
	输入包括4行由大写字母组成的文本，每行上字符的数目不超过80个。
关于输出
	输出包括若干行。其中最后一行给出26个大写英文字母，这些字母之间用空格隔开。前面的几行包括空格和星号，
	每个字母出现几次，就在这个字母的上方输出一个星号。注意：输出的第一行不能是空行。
*/
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char graph[53], sen[81];
	int mtime, i, j, k, len, cnt[26];
	for (i = 0; i < 53; i++)
		graph[i] = ' ';
	memset(cnt, 0, sizeof(cnt));
	for (i = 0; i < 4; i++)
	{
		cin.getline(sen, 81);
		len = strlen(sen);
		for (j = 0; j < len; j++)
			if (sen[j] >= 'A'&&sen[j] <= 'Z')
				cnt[sen[j] - 'A']++;
	}
	mtime = cnt[0];
	for (i = 1; i < 26; i++)
		mtime = mtime > cnt[i] ? mtime : cnt[i];
	for (i = mtime; i > 0; i--)
	{
		for (j = 0; j < 26; j++)
			if (cnt[j] >= i)
				graph[2 * j] = '*';
		k = 51;
		while (graph[k] == ' ')
			k--;
		graph[k + 1] = '\0';
		cout << graph << endl;
		for (k = 0; k < 53; k++)
			graph[k] = ' ';
	}
	cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << endl;
	return 0;
}
