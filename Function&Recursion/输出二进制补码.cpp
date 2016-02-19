/*
描述
	输入若干int型整数，输出每个整数的二进制补码。
关于输入
	输入有若干行，除最后一行外，每行包含一个int型整数。最后一行仅包含一个不定的字母，标志着输入结束。
	我们保证输入的整数不超出int型变量的表示范围
关于输出
	对于每个输入的整数，输出一行，即该整数的补码表示。
*/
#include<iostream>
using namespace std;
int buma[32];
int input(char[]);
void transform(int, int);
void output();
int main()
{
	int n;
	char c[15];
	while (true)
	{
		cin >> c;
		//输入回车时的处理
		while (c[0] == '\0')
			cin >> c;
		//输入字母时退出
		if ((c[0] >= 'a'&& c[0] <= 'z') || (c[0] >= 'A'&& c[0] <= 'Z'))
			break;
		//将输入的字符串转化为整数
		n = input(c);
		memset(buma, 0, sizeof(buma));
		//从末位数开始计算补码
		transform(n, 31);
		//输出
		output();
	}
	return 0;
}
int input(char c[15])
{
	//将字符串转化为整数
	int i, s = 1, n = 0;
	if (c[0] == '-')
		return -input(c + 1);
	for (i = strlen(c) - 1; i >= 0; i--)
	{
		n += (c[i] - '0') * s;
		s *= 10;
	}
	return n;
}
void transform(int n, int cnt)
{
	//单独处理-2147483648的情况
	if (n < -2147483647)
	{
		buma[0] = 1;
		for (int i = 1; i < 32; i++)
			buma[i] = 0;
		return;
	}
	if (n < 0)
	{
		buma[0] = 1;                 //负数则在第一位写入1
		transform(-n, cnt);          //求绝对值的原码
		for (int i = 1; i < 32; i++)
			buma[i] = 1 - buma[i];   //反位
		for (int i = 31; i >= 0; i--)
			//加上1，处理进位
			if (buma[i])
				buma[i] = 0;
			else
			{
				buma[i] = 1;
				break;
			}
		return;
	}
	//n为0时有效位计算完毕，其余为0
	if (n == 0)
		return;
	//进位、递归，从而求正数的原码，亦即补码
	buma[cnt] = n % 2;
	transform(n / 2, cnt - 1);
}
void output()
{
	int *p = buma;
	for (; p - buma < 32; p++)
		cout << *p;
	cout << endl;
}
