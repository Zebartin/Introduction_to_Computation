/*
����
	��һ������1���������ֽ�Ϊ�������Ļ�
��������
	һ������1�����������磬72
�������
	�ֽ�Ϊ�������Ļ���������� 
	72=2*2*2*3*3
*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	bool flag = 0;
	int N, i, tempN;
	cin >> N;
	tempN = N;
	int sN = sqrt(N);
	cout << N << "=";
	for (i = 2; i <= sN && N != 1; i++)
		if (N % i == 0)
		{
			N /= i;
			flag = 1;
			if (N == tempN / i)
				cout << i;
			else
				cout << "*" << i;
			i--;
		}
		
	if (!flag)
		cout << N << endl;
	else
		cout << endl;
	return 0;
}
