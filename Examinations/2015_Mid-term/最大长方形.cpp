/*
描述
	有一个长为N，宽为M的长方形区域，它的初始状态每个点都是白色的 
	现在我们对其做如下操作：首先对于其中的k行染为黑色，行数在1-M之间；然后将其中的p列也染为黑色，列数在1-N之间。 
	我们需要求出在染色之后，所分割出的白色长方形面积最大的那个，输出其面积的值 
	比如这种情况（0代表白色，1代表黑色）： 
	0 0 0 1 0 0 
	0 0 0 1 0 0 
	1 1 1 1 1 1 
	0 0 0 1 0 0 
	左上角的白色长方形最大，是3*2的，所以应该输出的值为6
关于输入
	第一行为两个整数N M，表示原始长方形的长宽（1<=N,M<=100） 
	第二行为一个整数k，表示要染色的行数 
	第三行为k个整数，以空格分开，表示染色的行号，并按升序排序，范围是1-M 
	第四行为一个整数p，表示要染色的列数 
	第五行为p个整数，以空格分开，表示染色的列号，并按升序排序，范围是1-N
关于输出
	一个整数，表示最大白色长方形的面积
*/
#include<iostream>
using namespace std;
int main()
{
	int N, M, k, p, i, dyerow[102],dyecol[102];
	int rectangle[102][102] = { 0 };
	cin >> N >> M;
	cin >> k;
	dyerow[0] = 0;
	for (i = 1; i <= k; i++)
		cin >> dyerow[i];
	dyerow[k + 1] = M + 1;
	cin >> p;
	dyecol[0] = 0;
	for (i = 1; i <= p; i++)
		cin >> dyecol[i];
	dyecol[p + 1] = N + 1;
	int maxheight = dyerow[1] - dyerow[0] - 1;
	for (i = 1; i <= k; i++)
		maxheight = maxheight>(dyerow[i + 1] - dyerow[i] - 1) ? maxheight : (dyerow[i + 1] - dyerow[i] - 1);
	int maxwidth = dyecol[1] - dyecol[0] - 1;
	for (i = 1; i <= p; i++)
		maxwidth = maxwidth>(dyecol[i + 1] - dyecol[i] - 1) ? maxwidth : (dyecol[i + 1] - dyecol[i] - 1);
	cout << maxheight * maxwidth << endl;
	return 0;
}
