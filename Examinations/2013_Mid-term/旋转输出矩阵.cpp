#include<iostream>
using namespace std;
int main()
{
	int N, flag = 0, i = 0, j = 0, k;
	int left, right, up, down;
	int matrix[100][100], temp[10000];
	cin >> N;
	for (k = 0; k < N * N; k++)
		cin >> matrix[k / N][k % N];
	left = 0;
	right = N - 1;
	up = 0;
	down = N - 1;
	k = 0;
	while (left <= right && up <= down)
	{
		for (j = left; j <= right; j++)
			temp[k++] = matrix[i][j];
		up++;
		j--;
		for (i = up; i <= down; i++)
			temp[k++] = matrix[i][j];
		right--;
		i--;
		for (j = right; j >= left; j--)
			temp[k++] = matrix[i][j];
		down--;
		j++;
		for (i = down; i >= up; i--)
			temp[k++] = matrix[i][j];
		left++;
		i++;
	}
	switch (N)
	{
	case 1:cout << temp[0]; break;
	default:
		cout << temp[0] << " " << temp[N * N - 1];
		for (i = 1, j = N * N - 2; i < j; i++, j--)
			cout << " " << temp[i] << " " << temp[j];
		if (j == i)
			cout << " " << temp[i];
	}
	cout << endl;
	return 0;
}
