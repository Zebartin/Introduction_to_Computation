/*
����
	�ж�һ���ַ����Ƿ��������һ���ַ�ͨ�������ַ����õ���ע�⣬�˴������ַ���Сд��
��������
	����ֻ��һ�У�Ϊ�����ַ������ַ���֮����һ���ո�ָ���
�������
	��������ַ�����ͬһ���ַ���ɣ���ÿһ���ַ����ִ�����ͬ�����������YES���� 
	���������NO����ע��YES��NO���Ǵ�д��ĸ��
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
