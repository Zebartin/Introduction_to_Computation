/*
����
	����һ������A[m,n](100 �� m �� 1,100 �� n �� 1) ����һ������B[r,s],��0 < r �� m, 0 < s �� n��A��B����Ԫ��ֵ����С��100������������A�к�B��ƥ��ľ���C[r,s]����ν��ƥ����ָB��C�Ķ�ӦԪ�ز�ֵ�ľ���ֵ֮����С������ж�����ƥ��ֻ�������һ�����к���С���к���ͬʱ���к���С����
��������
	��һ����m��n���Կո���� 
	����m��ÿ����n����������ʾA�����еĸ��� 
	��m+2��Ϊr��s���Կո���� 
	����r��ÿ����s����������ʾB�����еĸ���
�������
	���A�к�B��ƥ��ľ���C�����֮ 
	ע�⣺ÿһ�����ֺ��涼�пո񣬰���һ���е����һ������ 
*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int m, n, r, s, i, j, p, q;
	int A[100][100], B[100][100], C[100][100] = { 0 };

	cin >> m >> n;
	for (i = 0; i < m * n; i++)
		cin >> A[i / n][i % n];
	
	cin >> r >> s;
	for (j = 0; j < r * s; j++)
		cin >> B[j / s][j % s];
	
	for (i = 0; i <= m - r; i++)
		for (j = 0; j <= n - s; j++)
			for (p = 0; p < r; p++)
				for (q = 0; q < s; q++)
					C[i][j] += abs(A[i + p][j + q] - B[p][q]);
	
	int min = C[0][0], mark[2] = { 0 };

	for (j = 0; j <= n - s; j++)
		for (i = 0; i <= m - r; i++)
		{
			mark[0] = min < C[i][j] ? mark[0] : i;
			mark[1] = min < C[i][j] ? mark[1] : j;
			min = min < C[i][j] ? min : C[i][j];
		}

	for (i = mark[0]; i < mark[0] + r; i++)
		for (j = mark[1]; j < mark[1] + s; j++)
		{
			cout << A[i][j] << " ";
			if (j == mark[1] + s - 1)
				cout << endl;
		}
	return 0;
}
