/*
����
	��������int�����������ÿ�������Ķ����Ʋ��롣
��������
	�����������У������һ���⣬ÿ�а���һ��int�����������һ�н�����һ����������ĸ����־�����������
	���Ǳ�֤���������������int�ͱ����ı�ʾ��Χ
�������
	����ÿ����������������һ�У����������Ĳ����ʾ��
*/
#include<iostream>
using namespace std;
int buma[32];
int input(char[]);
void transform(int, int);
void output();
int main()
{
	int n;
	char c[15];
	while (true)
	{
		cin >> c;
		//����س�ʱ�Ĵ���
		while (c[0] == '\0')
			cin >> c;
		//������ĸʱ�˳�
		if ((c[0] >= 'a'&& c[0] <= 'z') || (c[0] >= 'A'&& c[0] <= 'Z'))
			break;
		//��������ַ���ת��Ϊ����
		n = input(c);
		memset(buma, 0, sizeof(buma));
		//��ĩλ����ʼ���㲹��
		transform(n, 31);
		//���
		output();
	}
	return 0;
}
int input(char c[15])
{
	//���ַ���ת��Ϊ����
	int i, s = 1, n = 0;
	if (c[0] == '-')
		return -input(c + 1);
	for (i = strlen(c) - 1; i >= 0; i--)
	{
		n += (c[i] - '0') * s;
		s *= 10;
	}
	return n;
}
void transform(int n, int cnt)
{
	//��������-2147483648�����
	if (n < -2147483647)
	{
		buma[0] = 1;
		for (int i = 1; i < 32; i++)
			buma[i] = 0;
		return;
	}
	if (n < 0)
	{
		buma[0] = 1;                 //�������ڵ�һλд��1
		transform(-n, cnt);          //�����ֵ��ԭ��
		for (int i = 1; i < 32; i++)
			buma[i] = 1 - buma[i];   //��λ
		for (int i = 31; i >= 0; i--)
			//����1�������λ
			if (buma[i])
				buma[i] = 0;
			else
			{
				buma[i] = 1;
				break;
			}
		return;
	}
	//nΪ0ʱ��Чλ������ϣ�����Ϊ0
	if (n == 0)
		return;
	//��λ���ݹ飬�Ӷ���������ԭ�룬�༴����
	buma[cnt] = n % 2;
	transform(n / 2, cnt - 1);
}
void output()
{
	int *p = buma;
	for (; p - buma < 32; p++)
		cout << *p;
	cout << endl;
}
