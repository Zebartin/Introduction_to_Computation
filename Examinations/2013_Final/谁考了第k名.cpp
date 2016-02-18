/*
描述
	在一次考试中，每个学生的成绩都不相同，现知道了每个学生的学号和成绩，求考第k名学生的学号和成绩。
关于输入
	第一行有两个整数，学生的人数n（1≤n≤100），和求第k名学生的k（1≤k≤n）。 
	其后有n行数据，每行包括一个学号（整数）和一个成绩（浮点数），中间用一个空格分隔。
关于输出
	输出第k名学生的学号和成绩，中间用空格分隔。
*/
#include<iostream>
using namespace std;

struct student
{
	int num;
	double grade;
} stu[100];

void msort(int i, int n, int k)
{
	int j;
	student temp;
	if (i == k)
		return;
	for (j = 0; j < n - i - 1; j++)
		if (stu[j].grade > stu[j + 1].grade)
		{
			temp = stu[j];
			stu[j] = stu[j + 1];
			stu[j + 1] = temp;
		}
	msort(i + 1, n, k);
}
int main()
{
	int n, k, i;
	cin >> n >> k;
	for (i = 0; i < n; i++)
		cin >> stu[i].num >> stu[i].grade;
	msort(0, n, k);
	cout << stu[n - k].num << " " << stu[n - k].grade << endl;
	return 0;
}
