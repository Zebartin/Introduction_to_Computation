/*
����
	СӢ��ҩѧרҵ������ѧ��������ڼ�����ȥҽԺҩ��ʵϰ�Ļ��ᡣ 
	��ҩ��ʵϰ�ڼ䣬СӢ��ʵ��רҵ���������ҽ����һ�º�������֪СӢ�ڼ��������ȡ�ù��óɼ���
	�����ֶ��⽻����һ�����񣬽��ܿ�սʱ�ڱ����ܹ���һЩ��Ա�������� 
	�����о���СӢ���������¼��ܹ��ɣ������������ӣ� 
	1.  ԭ�������е��ַ�����ѭ��������������λ��dec  -> abz�� 
	2.  ����洢��abcd -> dcba �� 
	3.  ��Сд��ת��abXY -> ABxy�� 
��������
	��n+1�� 
	��һ�������������ֵĸ���n(1<=n <= 1000�� 
	�����n�У�ÿ����һ�����ܵ��ַ�����������С��12��
�������
	n�� 
	�����ֵ�˳��������ܺ���ַ���
��������
	5
	WDDFSSP
	SDSDSDDo
	SDKGGFSIa
	LLLHFGFOl
	GSOOWFASOq
�������
	Dlvijjngv
	Orijikooo
	Rggvgvgv
	Trvdizrrvj
	svviggz
*/
#include<iostream>
#include<cstring>
using namespace std;
int length[1000];
char name[1000][13], temp[1000][13];
int i, j, n;
void sort();
int change();
int main()
{
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> temp[i];
		length[i] = strlen(temp[i]);
		for (j = 0; j < length[i]; j++)
		{
			name[i][j] = temp[i][length[i] - j - 1];
			if (name[i][j] <= 'z'&&name[i][j] >= 'a')
				name[i][j] += 'A' - 'a';
			else
				name[i][j] += 'a' - 'A';
			switch (name[i][j])
			{
			case 'x':name[i][j] = 'a'; break;
			case 'y':name[i][j] = 'b'; break;
			case 'z':name[i][j] = 'c'; break;
			case 'X':name[i][j] = 'A'; break;
			case 'Y':name[i][j] = 'B'; break;
			case 'Z':name[i][j] = 'C'; break;
			default:name[i][j] += 3;
			}
		}
		name[i][j] = '\0';
	}
	sort();
	for (i = 0; i < n; i++)
		cout << name[i] << endl;
	system("pause");
	return 0;
}
void sort()
{
	int k, swap;
	for (i = 0; i < n - 1; i++)
	{
		swap = 0;
		for (j = 0; j < n - 1 - i; j++)
			if (strcmp(name[j], name[j + 1]) == 1)
				swap = change();
		if (!swap)
			break;
	}
}
int change()
{
	char str3[13];
	strcpy_s(str3, name[j]);
	strcpy_s(name[j], name[j + 1]);
	strcpy_s(name[j + 1], str3);
	return 1;
}
