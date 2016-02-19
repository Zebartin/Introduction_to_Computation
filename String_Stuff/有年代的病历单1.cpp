/*
描述
	小英是药学专业大三的学生，暑假期间获得了去医院药房实习的机会。 
	在药房实习期间，小英扎实的专业基础获得了医生的一致好评，得知小英在计算概论中取得过好成绩后，
	主任又额外交给她一项任务，解密抗战时期被加密过的一些伤员的名单。 
	经过研究，小英发现了如下加密规律（括号中是例子） 
	1.  原文中所有的字符都被循环左移了三个单位（dec  -> abz） 
	2.  逆序存储（abcd -> dcba ） 
	3.  大小写反转（abXY -> ABxy） 
关于输入
	共n+1行 
	第一行是名单中名字的个数n(1<=n <= 1000） 
	随后是n行，每行是一个加密的字符串。（串长小于12）
关于输出
	n行 
	按照字典顺序输出解密后的字符串
例子输入
	5
	WDDFSSP
	SDSDSDDo
	SDKGGFSIa
	LLLHFGFOl
	GSOOWFASOq
例子输出
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
