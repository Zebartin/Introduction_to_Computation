/*
����
	���������������ϣ�������������ʱ����Ԫ�ش�С�����˳��������Զ��ż���� 
	
	ע�⣺�����ļ����п������ظ�Ԫ�أ�������Ľ����в������ظ�Ԫ�ء����û�н���������� NULL 

	���� 
	����A��1,3,5,6,10,6,8,11 
	����B: 2,4,8,6,10,6,12,13 
	
	��ô�����Ϊ�� 
	6,8,10
��������
	2�У�ÿ�б�ʾһ�����ϵ�Ԫ�����У�Ԫ��֮���Զ��ż�����ٶ�ÿ�����ϲ�����200��Ԫ�ء�
�������
	�������ϵĽ�������Ԫ�ش�С����������Զ��ż�������û�н���������� NULL
*/
#include<iostream>
using namespace std;
int main()
{
	char comma;
	int i = 0, j = 0, k = 0;
	int A[200], B[200], same[200];
	cin >> A[0];
	while ((comma = cin.get()) != '\n')
		cin >> A[++i];
	int num_A = i + 1;
	cin >> B[0];
	while ((comma = cin.get()) != '\n')
		cin >> B[++j];
	int num_B = j + 1;
	for (i = 0; i < num_A; i++)
		for (j = 0; j < num_B; j++)
			if (A[i] == B[j])
				same[k++] = A[i];
	if (k)
	{
		int swap, temp;
		int num_same = k;
		for (i = 0; i < num_same - 1; i++)
		{
			swap = 1;
			for (j = 0; j < num_same - i - 1; j++)
				if (same[j]>same[j + 1])
				{
					swap = 0;
					temp = same[j];
					same[j] = same[j + 1];
					same[j + 1] = temp;
				}
			if (swap)
				break;
		}
		cout << same[0];
		for (k = 1; k < num_same; k++)
			if (same[k] != same[k - 1])
				cout << "," << same[k];
	}
	else
		cout << "NULL";
	cout << endl;
	return 0;
}
