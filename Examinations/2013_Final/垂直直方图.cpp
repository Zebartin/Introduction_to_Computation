/*
����
	����4��ȫ���ɴ�д��ĸ��ɵ��ı������һ����ֱֱ��ͼ������ÿ���ַ����ֵĴ�����
	ע�⣺ֻ������ַ��ĳ��ִ�������������հ��ַ������ֻ��߱����ŵ����������
��������
	�������4���ɴ�д��ĸ��ɵ��ı���ÿ�����ַ�����Ŀ������80����
�������
	������������С��������һ�и���26����дӢ����ĸ����Щ��ĸ֮���ÿո������ǰ��ļ��а����ո���Ǻţ�
	ÿ����ĸ���ּ��Σ����������ĸ���Ϸ����һ���Ǻš�ע�⣺����ĵ�һ�в����ǿ��С�
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
