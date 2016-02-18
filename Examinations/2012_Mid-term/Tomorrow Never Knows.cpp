/*
描述
	甲壳虫的《A day in the life》和《Tomorrow never knows》脍炙人口，如果告诉你a day in the life,真的会是tomorrow never knows?相信学了计概之后这个不会是难题，现在就来实现吧。 
	读入一个格式为yyyy-mm-dd的日期（即年－月－日），输出这个日期下一天的日期。可以假定输入的日期不早于1600-01-01，也不晚于2999-12-30。 
关于输入
	输入仅一行，格式为yyyy-mm-dd的日期。
关于输出
	输出也仅一行，格式为yyyy-mm-dd的日期
*/
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	char c = '-';
	int year, month, date;
	int days_EachMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	cin >> year >> c >> month >> c >> date;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		days_EachMonth[1] += 1;
	if (date == days_EachMonth[month - 1])
	{
		date = 1;
		if (month == 12)
		{
			year += 1;
			month = 1;
		}
		else
			month += 1;
	}
	else
		date += 1;
	cout << year << c << setw(2) << setfill('0') << month << c << setw(2) << setfill('0') << date << endl;
	return 0;
}
