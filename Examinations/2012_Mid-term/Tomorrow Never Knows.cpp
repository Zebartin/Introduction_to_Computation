/*
����
	�׿ǳ�ġ�A day in the life���͡�Tomorrow never knows�������˿ڣ����������a day in the life,��Ļ���tomorrow never knows?����ѧ�˼Ƹ�֮��������������⣬���ھ���ʵ�ְɡ� 
	����һ����ʽΪyyyy-mm-dd�����ڣ����꣭�£��գ���������������һ������ڡ����Լٶ���������ڲ�����1600-01-01��Ҳ������2999-12-30�� 
��������
	�����һ�У���ʽΪyyyy-mm-dd�����ڡ�
�������
	���Ҳ��һ�У���ʽΪyyyy-mm-dd������
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
