/*
描述
	给定某年某月，打印出当月的月历表，月历表的输出格式如样例所示。
关于输入
	输入为一行两个整数，第一个整数是年份year（1900 ≤ year ≤ 2099），第二个整数是月份month（1 ≤ month ≤ 12）。
关于输出
	输出为月历表。 
	
	月历表第一行为星期表头，如下所示： 
	Sun Mon Tue Wed Thu Fri Sat 
	注：在上行中，每个单词占4个字符位。也就是说，Sun之前有一个空格，其后每个单词之间有一个空格，最后一个单词Sat之后没有空格。 
	
	其余各行依次是当月各天的日期，从1日开始到30日（或31日 或28日）； 
	每个日期数字也占4个字符的位置，且 日期数字 与 相应的星期表头 右对齐。 
	
	第一个日期数字之前如果需要空出星期表头，可以用  四个空格  代替一个日期数字所占的4个字符位，最后一个日期数字之后没有换行或空格。
*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int daysOM[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int i, y, m;
	cin >> y >> m;
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		daysOM[1]++;

	int sum = 0;
	for (i = 1900; i < y; i++)
		if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			sum += 2;
		else
			sum += 1;
	for (i = 1; i < m; i++)
		sum += daysOM[i - 1];
	sum += 1, sum %= 7;
	
	cout << " Sun Mon Tue Wed Thu Fri Sat" << endl;
	for (i = 0; i < sum * 4; i++)
		cout << " ";
	for (i = 0; i < daysOM[m - 1] - 1; i++)
	{
		cout << setw(4) << setfill(' ') << i + 1;
		if (sum == 0 && (i + 1) % 7 == 0 || (i + 1) % 7 == 7 - sum)
			cout << endl;
	}
	cout << "  " << daysOM[m - 1] << endl;
	return 0;
}
