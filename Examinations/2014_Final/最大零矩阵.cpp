/*
����
	��һ����λ���� m��<100����, n��<100�� �У���Ԫ��Ϊ������100�ķǸ���������Ҫ��Ԫ��ֵ��Ϊ0������Ӷ�ά���飬
	���������ڣ���Ҳ���ڣ�����������֮�����(��������0Ԫ�����)����������������磺 
	
	2  5  0  0  8  11  15 
	3  0  0  0  0  12  16 
	7  0  0  0  0  13  17 
	8  0  0  7  1  14  18 
	4  0  0  0  0  0   0 
	6  0  0  0  0  0   0 
	
	����6�У�7�й��ɵĶ�ά���飬���У��ɵ�4~5��(���2��)����1~6�У����6�У����ɵ����������
	����12��0Ԫ�أ���ˣ�Ӧ����� 12����������µ������鶼������12��0Ԫ�أ����磬
	��1~5�����1~2�й���������Ϊ�ڶ������飬����10��0Ԫ�ء� 
��������
	��һ�У�m �� n ��ֵ���Կո�����m �� n ��Ϊ ������ 100 �������� 
	֮�󣬹� m �У�ÿ�й� n ��Ԫ�أ�����ÿո��� 
�������
	����������Ԫ���Ӷ�ά���������� 0 Ԫ�ظ��������û��0Ԫ�أ������0��
*/
#include<iostream>
using namespace std;
int m, n, matrix[100][100];
int largest = 0;
void zeroRectangle(int row, int col, int maxc)
{
	if (!maxc)
		return;
	int height = INT_MAX;
	for (int i = 0; i < maxc; i++)
	{
		int temp = 1;
		while (!matrix[row + temp][col + i] && row + temp < m)
			temp++;
		height = height < temp ? height : temp;
	}
	largest = largest > height * maxc ? largest : height * maxc;
	zeroRectangle(row, col, maxc - 1);
}
int main()
{
	int i, j;
	cin >> m >> n;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			cin >> matrix[i][j];
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (!matrix[i][j])
			{
				int temp = j, cnt = 1;
				while (++temp < n)
					if (!matrix[i][temp])
						cnt++;
					else
						break;
				zeroRectangle(i, j, cnt);
			}
	cout << largest << endl;
	return 0;
}
