/*
����
	����һ���ַ���,������ǿ��������ֲ�ͬ�İ취�����зֳɵ��ʵ�����,��ô����˵����ַ������������.
	����iskill,�����зֳ�is��kill,Ҳ�����зֳ�i��skill. 
	���ڸ���һ�����ʱ�,���㹹�����������ʱ��ϵ�������崮,����������������ַ����зֳɵ��ʱ��еĵ���,
	Ҫ�����崮�����ܶ�.
��������
	��һ����һ������n(n<=100)��ʾ�ʱ�Ĵ�С. 
	������n��,ÿ��һ������,ֻ�������ֺ�Сд��ĸ,���Ȳ�����20.
�������
	���������崮,���������崮�ж��ֿ���,������ֵ�����С����һ��.
*/
#include<iostream>
#include<cstring>
using namespace std;
/*
������˵����
n�������ַ���������table[100][21]��������ַ�����
all[100][100]�����е����崮��allRemain[100][21]�����е�ʣ�മ��
���Ƿֱ���cnt1��cnt2������temp[100]����ʱ���崮��
�������ܣ�Ѱ����remain[21]��ͷ�����崮��remain[21]ָʣ�മ��t[100]ָ���ڹ�������崮
*/
int n, cnt1 = 0, cnt2 = 0;
char table[100][21], all[100][100], allRemain[100][21], temp[100];
void MMS(char[], char[]);
int main()
{
	int i, j, lS;
	char shortestS[100];
	//����
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> table[i];
	//����
	memset(shortestS, 0, sizeof(shortestS));
	memset(all, 0, sizeof(all));
	//�ҳ��������崮
	for (i = 0; i < n; i++)
	{
		memset(temp, 0, sizeof(temp));
		MMS(table[i], temp);
	}
	//�ҳ�������崮
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
	//���
	cout << shortestS << endl;
	return 0;
}
void MMS(char remain[21], char t[100])
{
	int i, j;
	int l1 = strlen(remain), l2 = strlen(t);
	//���ʣ�മ�Ѿ����ֹ���˵����������������ѭ���γ����޳������崮
	//���߹���������崮���֮ǰ�ĳ���ֱ����ȥ
	for (i = 0; i < cnt2; i++)
		if (!strcmp(allRemain[i], remain))
			return;
	//δ���ֹ��򴢴�
	strcpy_s(allRemain[cnt2++], remain);
	//����������봮�Ƿ���ʣ�മ�а�����ϵ
	for (i = 0; i < n; i++)
	{
		int l3 = strlen(table[i]);
		//ʣ�മ�����봮���
		if (!strcmp(remain, table[i]))
			if (l2)
			{
				//��ѭ���൱��strcat(t, remain)
				for (j = l2; j < l1 + l2; j++)
					t[j] = remain[j - l2];
				strcpy_s(all[cnt1++], t);
				return;
			}
			else
				continue;
		//���봮��ʣ�മ���Ӵ��ҷ��ص�ַ��remain�������봮��ȫ��ʣ�മ���󲿸���
		if (strstr(remain, table[i]) != NULL && !strcmp(strstr(remain, table[i]), remain))
		{
			for (j = l2; j < l3 + l2; j++)
				t[j] = table[i][j - l2];
			MMS(remain + l3, t);
			//����
			for (j = l2; j < l3 + l2; j++)
				t[j] = '\0';
		}
		//ʣ�മ�����봮���Ӵ��ҷ��ص�ַ��table[i]����ʣ�മ��ȫ�����봮���󲿸���
		if (strstr(table[i], remain) != NULL && !strcmp(strstr(table[i], remain), table[i]))
		{
			for (j = l2; j < l1 + l2; j++)
				t[j] = remain[j - l2];
			MMS(table[i] + l1, t);
			//����
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
