/*
描述
	对于一个字符串,如果我们可以用两种不同的办法把它切分成单词的序列,那么我们说这个字符串是有歧义的.
	比如iskill,可以切分成is和kill,也可以切分成i和skill. 
	现在给你一个单词表,请你构造出在这个单词表上的最短歧义串,即这个串可以用两种方案切分成单词表中的单词,
	要求歧义串尽可能短.
关于输入
	第一行是一个整数n(n<=100)表示词表的大小. 
	接下来n行,每行一个单词,只包含数字和小写字母,长度不超过20.
关于输出
	输出最短歧义串,如果最短歧义串有多种可能,请输出字典序最小的那一个.
*/
#include<iostream>
#include<cstring>
using namespace std;
/*
各变量说明：
n是输入字符串总数，table[100][21]是输入的字符串，
all[100][100]是所有的歧义串，allRemain[100][21]是所有的剩余串，
它们分别用cnt1，cnt2计数，temp[100]是临时歧义串。
函数功能：寻找以remain[21]开头的歧义串，remain[21]指剩余串，t[100]指正在构造的歧义串
*/
int n, cnt1 = 0, cnt2 = 0;
char table[100][21], all[100][100], allRemain[100][21], temp[100];
void MMS(char[], char[]);
int main()
{
	int i, j, lS;
	char shortestS[100];
	//输入
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> table[i];
	//清零
	memset(shortestS, 0, sizeof(shortestS));
	memset(all, 0, sizeof(all));
	//找出所有歧义串
	for (i = 0; i < n; i++)
	{
		memset(temp, 0, sizeof(temp));
		MMS(table[i], temp);
	}
	//找出最短歧义串
	strcpy_s(shortestS, all[0]);
	lS = strlen(all[0]);
	for (j = 1; j < cnt1; j++)
	{
		int length = strlen(all[j]);
		if (!length && length < lS)
		{
			strcpy_s(shortestS, all[j]);
			lS = length;
		}
		if (length == lS && strcmp(shortestS, all[j]) == 1)
			strcpy_s(shortestS, all[j]);
	}
	//输出
	cout << shortestS << endl;
	return 0;
}
void MMS(char remain[21], char t[100])
{
	int i, j;
	int l1 = strlen(remain), l2 = strlen(t);
	//如果剩余串已经出现过，说明接下来会陷入死循环形成无限长的歧义串
	//或者构造出的歧义串会比之前的长，直接舍去
	for (i = 0; i < cnt2; i++)
		if (!strcmp(allRemain[i], remain))
			return;
	//未出现过则储存
	strcpy_s(allRemain[cnt2++], remain);
	//逐个尝试输入串是否与剩余串有包含关系
	for (i = 0; i < n; i++)
	{
		int l3 = strlen(table[i]);
		//剩余串与输入串相等
		if (!strcmp(remain, table[i]))
			if (l2)
			{
				//此循环相当于strcat(t, remain)
				for (j = l2; j < l1 + l2; j++)
					t[j] = remain[j - l2];
				strcpy_s(all[cnt1++], t);
				return;
			}
			else
				continue;
		//输入串是剩余串的子串且返回地址是remain，则输入串完全被剩余串的左部覆盖
		if (strstr(remain, table[i]) != NULL && !strcmp(strstr(remain, table[i]), remain))
		{
			for (j = l2; j < l3 + l2; j++)
				t[j] = table[i][j - l2];
			MMS(remain + l3, t);
			//回溯
			for (j = l2; j < l3 + l2; j++)
				t[j] = '\0';
		}
		//剩余串是输入串的子串且返回地址是table[i]，则剩余串完全被输入串的左部覆盖
		if (strstr(table[i], remain) != NULL && !strcmp(strstr(table[i], remain), table[i]))
		{
			for (j = l2; j < l1 + l2; j++)
				t[j] = remain[j - l2];
			MMS(table[i] + l1, t);
			//回溯
			for (j = l2; j < l1 + l2; j++)
				t[j] = '\0';
		}
	}
}
/*
Input of in case 0:
6
101
1000
100
1011
0001
00

Standard Output:
101100


Input of in case 1:
4
0110111011
0101110
010
0101110010

Standard Output:
0101110010


Input of in case 2:
8
00101010
1010001001
110001110
100
0010101010
100010
011100011
10100

Standard Output:
0010101010100


Input of in case 3:
5
1010001001110110010
11111111000
101000100111
01100101111
1111000

Standard Output:
101000100111011001011111111000


Input of in case 4:
7
10110000000111
0101110111110
1111101001101
10110000000
111010111011
111011111010
01101

Standard Output:
1011000000011101011101111101111101001101


Input of in case 5:
6
011110101110010
0000100101011101000
1100011111110100
00001001010
11101000110
0011111110100

Standard Output:
00001001010111010001100011111110100


Input of in case 6:
8
100011000100
010101100110001101
111010001000010
001000001101101
10001100010001010
110011000110111101
000100001000
1000001101101

Standard Output:
100011000100010101100110001101111010001000010001000001101101


Input of in case 7:
9
101010100000
11010010000011
01111001000111001
001011101001011110
100010010
10101010000011010010
0000110111100100011
10010010111010010111
10100010010

Standard Output:
1010101000001101001000001101111001000111001001011101001011110100010010


Input of in case 8:
13
01000111111001
100001110011010111
0101011110011000
1001001100101
0011111100001
00001100010111100001
101011
010001111110
011000011100110101
110101011110
01100010010011001
01001111110000100001
100010111100001

Standard Output:
01000111111001001111110000100001100010111100001
*/
