/*
����
	�ڳ�������У�����ʹ��С����ǿ�����ʽ������˳�򣬵��ǣ�����С���ű���ƥ�䡣
	�ָ���һ��������500�����ŵı��ʽ�����������п��ܴ��ڶ��С���ţ�����С���ŵ�ƥ�����⡣
	�������С���Ų�ƥ�䣬����� mismatch���������С����ƥ�䣬���������ŵ�ƥ�������С��������������ŵ�λ�ã�
	�����ƥ��ľ�����ȣ����������ȳ��ֵ�ƥ��������������������û��С���ţ�������λ�þ����0���� 0,0��
	�涨�����е�һ�����ŵ�λ��Ϊ1�� 
	ƥ�����=������λ�� - ������λ�á� 
	
	���磺 
	����Ϊ��    (x+y*(z-5)*(x+y))*(x+98) 
	���Ϊ�� 
	6,10 
	12,16 
	19,24 
	1,17 
	�������Ϊ  (x+y*(z-5))*x+y) 
	��ƥ�䣬��Ϊ�����ķ�����û����ƥ��������š���ˣ������ 
	mismatch
��������
	һ������
�������
	��ƥ�������������ƥ��Ե�����λ�ã����ż�������������ͬ���������ų��ֵ��Ⱥ�˳�������
	������������г��ֲ�ƥ����������� mismatch�� 
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
