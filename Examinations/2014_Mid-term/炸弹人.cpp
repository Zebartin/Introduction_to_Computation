/*
����
	���һ�����ը������Ϸ�ɣ�һ��ը��һ���γ�һ��ʮ���ƻ��� 
	����һ��MxN�� (M<=100, N<=100)�������������һ��Ԫ��Ϊ0�� 
	�����õ���ը�����򽫸õ����ڵ��к���������Ԫ�ؾ�����Ϊ0��
��������
	����ΪM, N, �� M*N��������
�������
	���Ϊը����ը��ľ���
*/
#include<iostream>
using namespace std;
int main()
{
	int rec[100][100], rectemp[100][100], M, N, i, j;
	cin >> M >> N;
	for (i = 0; i < M * N; i++)
	{
		cin >> rec[i / N][i % N];
		rectemp[i / N][i % N] = rec[i / N][i % N];
	}
	for (i = 0; i < M * N; i++)
		if (rectemp[i / N][i % N] == 0)
		{
			for (j = 0; j < N; j++)
				rec[i / N][j] = 0;
			for (j = 0; j < M; j++)
				rec[j][i % N] = 0;
		}
	for (i = 0; i < M * N; i++)
	{
		if (i % N < N - 1)
			cout << rec[i / N][i % N] << " ";
		else
			cout << rec[i / N][i % N] << "\n";
	}
	return 0;
}
