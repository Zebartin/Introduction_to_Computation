/*
����
	��һ��Ӣ�Ķ��ģ�����֮���Կո�ָ���ÿ������Ӧ������ǰ����ڵı����ţ����뽫���������Ű棬Ҫ�����£�
	ÿ�в�����80���ַ���ÿ�����ʾ���ͬһ���ϣ���ͬһ�еĵ���֮����һ���ո�ָ������׺���β��û�пո� 
��������
	��һ����һ������n����ʾӢ�Ķ����е��ʵ���Ŀ. �����n���Կո�ָ���Ӣ�ĵ���
	�����ʰ�����ǰ����ڵı����ţ���ÿ�����ʳ��ȶ�������40����ĸ����
�������
	�Ű��Ķ����ı���ÿ���ı��ַ������80���ַ�������֮����һ���ո�ָ���ÿ���ı���β��û�пո�
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
