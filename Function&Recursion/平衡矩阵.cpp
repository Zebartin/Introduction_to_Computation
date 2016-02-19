/*
����
	������һ��n������������n<=7�������ڿ��ԶԾ��������һ�н������ƣ��������Ϊ��
	ÿ�ζ���ĳһ��a_i1,a_i2,��,a_in����һ�����ƣ�����ߵ�Ԫ���ƶ�����һ�е�ĩβ��
	����Ԫ�ؾ������ƶ�һλ������Ϊa_i2,a_i3,��,a_in,a_i1����ĳһ�п���ִ������ε����ơ� 
	�������ǵ�Ŀ���ǣ�ͨ���Ծ����ÿһ�н������ɴ����ƣ�ʹ�þ�����ÿ�к͵����ֵ��С�� 
��������
	��������������ݡ� 
	����ÿ�����ݣ���һ��Ϊһ��������n��1<=n<=7�����������Ľס���������n�У�ÿ��n����������������10000����
	����������� 
	����������һ��-1Ϊ��β�������������
�������
	����ÿ�����ݣ����һ��һ����������Ϊ��С������к͡�
*/
#include<iostream>
using namespace std;
int matrix[7][7], stuff[117649], addup[7], n, cnt;
void move(int);
int max(int[]);
int min(int[]);
int main()
{
	while (cin >> n)
	{
		cnt = 0;
		memset(addup, 0, sizeof(addup));
		memset(stuff, 0, sizeof(stuff));

		if (n == -1)
			break;

		int i;
		for (i = 0; i < n * n; i++)
		{
			//�������
			cin >> matrix[i / n][i % n];
			//��һ�в�����
			if (i < n)
				addup[i] = matrix[0][i];
		}
		//�ӵڶ��п�ʼ����
		move(1);
		//������͵���Сֵ
		cout << min(stuff) << endl;
	}
	return 0;
}
void move(int row)
{
	int i, j, temp[7];
	//�����һ��ʱ�ݹ���������һ������к�
	if (row == n)
	{
		stuff[cnt++] = max(addup);
		return;
	}
	//iΪ��������
	for (i = 0; i < n; i++)
	{
		//jΪ���ƺ���к�
		for (j = 0; j < n; j++)
		{
			temp[j] = addup[j];                    //���ڻ���
			addup[j] += matrix[row][(j + i) % n];  //���
		}
		//û�����һ���������һ��
		move(row + 1);
		//����
		for (j = 0; j < n; j++)
			addup[j] = temp[j];
	}
}
int max(int a[7])
{
	//�����ֵ
	int i, k = a[0];
	for (i = 1; i < n; i++)
		k = k > a[i] ? k : a[i];
	return k;
}
int min(int a[117649])
{
	//����Сֵ
	int i, k = a[0];
	for (i = 1; i < cnt; i++)
		k = k < a[i] ? k : a[i];
	return k;
}
