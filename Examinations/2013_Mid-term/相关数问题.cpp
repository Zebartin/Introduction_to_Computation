/*
描述
	列出一组数（10到99之间的数）中所有与指定数（3、5或7）相关的数。所谓相关数，以7为例，是那些个位或/且十位上包含7，或者它能被7整除的整数。
关于输入
	第一行是整数n，接着n行每行一个整数（10到99之间的数）。最后一行为指定数（3、5或7）。（共有n+2行）
关于输出
	输出有多行。按输入顺序，输出所有与指定数相关的相关数，每个数单独一行。
*/
#include<iostream>
using namespace std;
int main()
{
	int integer[90], relevant[90], n, k, i, j = 0;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> integer[i];
	cin >> k;
	for (i = 0; i < n; i++)
	{
		if (integer[i] % k == 0 || integer[i] % 10 == k || integer[i] / 10 == k)
			relevant[j++] = integer[i];
	}
	int num = j;
	for (j = 0; j < num; j++)
		cout << relevant[j] << '\n' << endl;
	return 0;
}
