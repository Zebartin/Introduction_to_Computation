/*
描述
	有1堆苹果共 m 个，由 n 只猴子按个数平均分配。每次到达苹果堆放地的猴子只有1只，
	而且每个猴子都会平均分 1 次苹果。第1个到达的猴子将苹果平均分成 n 等份，但发现多 k ( k < n )个，
	于是，将多余的k个扔掉，然后拿走其中的1等份。第 2 个猴子同样将剩余的苹果又分成 n 等份，也发现多 k 个，
	并同样将多余的 k 个扔掉，然后拿走其中1等份。之后的每个猴子都这样（将剩余的苹果又分成 n 等份，也发现多 k 个，
	并将多余的 k 个扔掉，然后拿走其中1等份）。假设最后的猴子分配后至少可以拿走1个苹果，
	请根据输入的 n 和 k值，计算最小的 m
关于输入
	输入猴子数目n 和扔掉的个数 k，其中 k 小于 n，n 和 k 之间以空格间隔。
关于输出
	输出最小苹果数目
*/
#include<iostream>
using namespace std;
int n, k, i = 1;
int apple(int);
int main()
{
	cin >> n >> k;             //输入
	cout << apple(1) << endl;  //从第一只猴子开始算最少苹果数
	return 0;
}
int apple(int a)
{
	//第n只猴子分苹果，每份i个苹果，剩余k个，故前一只猴子分后剩下n*i+k个
	if (a == n)
		return n * i++ + k;
	else
	{
		int b;
		//该循环与i++一起，以最后一只猴子分的每份苹果数为变量从小到大尝试符合条件的总苹果数，该变量最小时苹果数最少
		do
		{
			b = apple(a + 1) * n / (n - 1) + k;
			if (b % n == k)
				return b;
		} while (true);
	}
}
