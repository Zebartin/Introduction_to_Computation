/*
����
	��һ��Nλ������X������������ʱ������Ϊѭ������X������һ������1��Y �� N���ʱ����������һ��X�ġ�ѭ������
	�����ֱ������������ĵ�1λ���������1λ��������һ�𣬿��Եõ�һ����ͬ������ѭ����
	��Ȼ���������ڸ�����ѭ���е���ʼλ�ò�ͬ�����磬142857��һ��ѭ���� 
	142857 *1 = 142857 
	142857 *2 = 285714 
	142857 *3 = 428571 
	142857 *4 = 571428 
	142857 *5 = 714285 
	142857 *6 = 857142
��������
	дһ�������ж�һ�������Ƿ���ѭ�����������ļ���һ���������У�ÿ����������Ϊ2~60��ע
	�⣺ÿ������ǰ����㱻�����Ǹ�������һ���֣��ڼ���NʱҪͳ�ơ�
	���硰01����һ��2λ������������1����һ��1λ��������
�������
	��ÿ���������������һ�У�˵���������Ƿ���ѭ������
*/
#include<iostream>
#include<cstring>
using namespace std;
char s[100];
int number[100];
bool judge(int n)
{
	int j, l = strlen(s);
	int t[130];
	char ns[130];
	memset(t, 0, sizeof(t));
	memset(ns, 0, sizeof(ns));
	int k = 0;
	for (j = l - 1; j >= 0; j--)
		t[k++] = (s[j] - '0') * n;
	for (j = 0; j < l * 2; j++)
	{
		t[j + 1] += t[j] / 10;
		t[j] %= 10;
	}
	j = l * 2;
	while (t[j] == 0)
		j--;
	while (j < l - 1)
		j++;
	k = 0;
	for (; j >= 0; j--)
		ns[k++] = t[j] + '0';
	ns[k] = 0;

	int i, l1 = strlen(s), l2 = strlen(ns);
	char temp[100], rt[100];
	for (i = 0; i < l2; i++)
		if (ns[i] == s[0])
		{
			strcpy_s(temp, ns + i);
			strcpy_s(rt, ns);
			rt[i] = 0;
			strcat_s(temp, rt);
			if (!strcmp(temp, s))
				return true;
		}
	return false;
}

bool multi(int i)
{
	if (i == strlen(s))
		if (judge(i))
			return true;
		else
			return false;
	if (judge(i))
		return multi(i + 1);
	else
		return false;
}
int main()
{
	while (1)
	{
		memset(s, 0, sizeof(s));
		memset(number, 0, sizeof(number));
		cin >> s;
		if (s[0] == 0)
			break;
		if (multi(1))
			cout << s << " is cyclic" << endl;
		else
			cout << s << " is not cyclic" << endl;
	}
	return 0;
}
