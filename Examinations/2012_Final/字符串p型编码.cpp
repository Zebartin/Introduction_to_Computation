/*
描述
	给定一个完全由数字字符（'0','1','2','3'…'9'）构成的字符串str，请写出str的p型编码串。
	例如：字符串122344111可被描述为"1个1、2个2、1个3、2个4、3个1"，因此我们说122344111的p型编码串为1122132431；
	类似的道理，编码串101可以用来描述1111111111；00000000000可描述为"11个0"，因此它的p型编码串即为110；
	100200300可描述为"1个1、2个0、1个2、2个0、1个3、2个0"，因此它的p型编码串为112012201320。
关于输入
	输入包含若干测试。第一行给出测试的组数k，接着k行输入为字符串。每一行字符串最多包含1000个数字字符。
关于输出
	对每一组测试，输出该字符串对应的p型编码串，输出k行结果（每一输出结果后只需换一行）。
*/
#include<iostream>
using namespace std;
int main()
{
	int i, k, cnt;
	char number[1001], temp = 0;
	cin >> k;
	while (k--)
	{
		cnt = 0;
		temp = 0;
		cin >> number;
		for (char *p = number; *p != '\0'; p++)
			if (!cnt)
			{
				cnt++;
				temp = *p;
			}
			else 
				if (temp == *p)
					cnt++;
				else
				{
					cout << cnt << temp;
					cnt = 1;
					temp = *p;
				}
		cout << cnt << temp << endl;
	}
	return 0;
}
