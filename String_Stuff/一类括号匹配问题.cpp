/*
描述
	在程序设计中，常常使用小括号强调表达式的运算顺序，但是，左右小括号必须匹配。
	现给定一个不多于500个符号的表达式（串），其中可能存在多个小括号，想检查小括号的匹配问题。
	如果存在小括号不匹配，则输出 mismatch；如果所有小括号匹配，则按左右括号的匹配距离由小到大输出左、右括号的位置；
	若多个匹配的距离相等，则左括号先出现的匹配先输出；如果整个串中没有小括号，则左右位置均输出0，即 0,0；
	规定，串中第一个符号的位置为1。 
	匹配距离=右括号位置 - 左括号位置。 
	
	例如： 
	输入为：    (x+y*(z-5)*(x+y))*(x+98) 
	输出为： 
	6,10 
	12,16 
	19,24 
	1,17 
	如果输入为  (x+y*(z-5))*x+y) 
	则不匹配，因为在最后的反括号没有相匹配的正括号。因此，输出： 
	mismatch
关于输入
	一串符号
关于输出
	按匹配距离的增序输出匹配对的左右位置，逗号间隔；如果距离相同，则按左括号出现的先后顺序输出；
	如果整个序列中出现不匹配现象，则输出 mismatch； 
*/
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int i, j, length, cnt1 = 0, cnt2 = 0;
	int labelleft[501], labelright[501], match[250][2];;
	char str[501];
	cin >> str;
	length = strlen(str);
	memset(labelleft, 0, sizeof(labelleft));
	memset(labelright, 0, sizeof(labelright));
	for (i = 0; i < length; i++)
		if (str[i] == '(')
		{
			labelleft[i + 1] = 1;
			cnt1++;
		}
		else
			if (str[i] == ')')
			{
				labelright[i + 1] = 1;
				cnt2++;
			}
	if (cnt1 != cnt2)
		cout << "mismatch" << endl;
	else
		if (cnt1 == 0)
			cout << 0 << ',' << 0 << endl;
		else
		{
			int k = 0;
			while (1)
			{
				for (i = length; i >= 1; i--)
					if (labelleft[i] == 1)
					{
						labelleft[i] = 0;
						cnt1--;
						break;
					}
				if (i == 0)
					break;
				for (j = i; j <= length; j++)
					if (labelright[j] == 1)
					{
						labelright[j] = 0;
						cnt2--;
						break;
					}
				match[k][0] = i;
				match[k++][1] = j;
			}
			if (cnt1 != 0 || cnt2 != 0)
				cout<< "mismatch" << endl;
			else
			{
				int swap, temp;
				for (i = 0; i < k - 1; i++)
				{
					swap = 0;
					for (j = 0; j < k - i - 1; j++)
						if (match[j][1] - match[j][0]>match[j + 1][1] - match[j + 1][0])
						{
							swap = 1;
							temp = match[j][0];
							match[j][0] = match[j + 1][0];
							match[j + 1][0] = temp;
							temp = match[j][1];
							match[j][1] = match[j + 1][1];
							match[j + 1][1] = temp;
						}
						else
							if (match[j][1] - match[j][0] == match[j + 1][1] - match[j + 1][0])
								if (match[j][0]>match[j + 1][0])
								{
									swap = 1;
									temp = match[j][0];
									match[j][0] = match[j + 1][0];
									match[j + 1][0] = temp;
									temp = match[j][1];
									match[j][1] = match[j + 1][1];
									match[j + 1][1] = temp;
								}
					if (!swap)
						break;
				}
				for (i = 0; i < k; i++)
					cout << match[i][0] << "," << match[i][1] << endl;
			}
		}
	return 0;
}
