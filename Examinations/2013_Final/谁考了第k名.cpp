/*
����
	��һ�ο����У�ÿ��ѧ���ĳɼ�������ͬ����֪����ÿ��ѧ����ѧ�źͳɼ����󿼵�k��ѧ����ѧ�źͳɼ���
��������
	��һ��������������ѧ��������n��1��n��100���������k��ѧ����k��1��k��n���� 
	�����n�����ݣ�ÿ�а���һ��ѧ�ţ���������һ���ɼ��������������м���һ���ո�ָ���
�������
	�����k��ѧ����ѧ�źͳɼ����м��ÿո�ָ���
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
