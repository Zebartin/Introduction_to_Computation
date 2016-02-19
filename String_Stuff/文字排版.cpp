/*
描述
	给一段英文短文，单词之间以空格分隔（每个单词应包括其前后紧邻的标点符号）。请将短文重新排版，要求如下：
	每行不超过80个字符；每个单词居于同一行上；在同一行的单词之间以一个空格分隔；行首和行尾都没有空格。 
关于输入
	第一行是一个整数n，表示英文短文中单词的数目. 其后是n个以空格分隔的英文单词
	（单词包括其前后紧邻的标点符号，且每个单词长度都不大于40个字母）。
关于输出
	排版后的多行文本，每行文本字符数最多80个字符，单词之间以一个空格分隔，每行文本首尾都没有空格。
*/
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	const int max = 80;
	int i, n, length = 0;
	char words[40];
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> words;
		if (length)
		{
			length += strlen(words) + 1;
			if (length <= max)
				cout << " " << words;
			else
			{
				cout << endl << words;
				length = strlen(words);
			}
		}
		else
		{
			length += strlen(words);
			cout << words;
		}
	}
	cout << endl;
	return 0;
}
