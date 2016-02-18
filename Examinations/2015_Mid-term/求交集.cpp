/*
描述
	给定两个整数集合，输出交集，输出时，按元素从小到大的顺序输出，以逗号间隔。 
	
	注意：给定的集合中可能有重复元素，但输出的交集中不能有重复元素。如果没有交集，则输出 NULL 

	例： 
	集合A：1,3,5,6,10,6,8,11 
	集合B: 2,4,8,6,10,6,12,13 
	
	那么，输出为： 
	6,8,10
关于输入
	2行，每行表示一个集合的元素序列，元素之间以逗号间隔，假定每个集合不超出200个元素。
关于输出
	两个集合的交集，按元素从小到大输出，以逗号间隔。如果没有交集，则输出 NULL
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
