/*
����
	Ϊ����ף�ɹ��ȹ�����ĩ�գ�A�о����������о�Ա�������ԡ��������ھ���ԭ�򣬲��������е��Զ����Ա������� 
	A�о����涨��������2009��3��1���Ժ������ĵ��ԣ������ܽ��и���������3��1�գ�Ҳ����˵2009��3��1�������ĵ��Կ��Ը�������ͬʱ�о�Ա�Ե��Ե�Ʒ��Ҳ���Լ���ƫ�á� 
	�о�Ա����ʹ��Dell��Lenovo�ĵ��ԣ����Ҹ����������£� 
	ʹ�ù�Dell���о�Ա��Ҫ����Lenovo�ĵ��ԣ� 
	ʹ�ù�Lenovo���о�Ա��Ҫ����Dell�ĵ��ԣ� 
	ʹ��Desktop��̨ʽ�������о�Ա�뻻��Laptop���ʼǱ����� 
	ʹ��Laptop���ʼǱ������о�Ա�뻻��Desktop��̨ʽ������
��������
	��һ��Ϊ�о�Ա����ĿN��N<=100 
	������N�У�ÿ�б�ʾ�о�Ա����ʹ�õĵ��ԣ���ʽΪ 
	���� �������� �������� �������� 
	����֮���ÿո�ֿ������������������ӡ��������ڡ��������;������ո��ҳ��Ȳ�����50���ַ� 
	ע���������ڸ�ʽΪ��YYYY-MM-DD
�������
	���N�У�ÿ��Ϊ������ĵ�����Ϣ�������� 
	���� �������� �������� 
	����޷�������������� 
	���� ToT
*/
#include<iostream>
#include<cstring>
using namespace std;
char name[51], brand[7], pdate[11], type[8];
char twob[2][7] = { "Lenovo","Dell" }, twot[2][8] = { "Desktop","Laptop" };
void input();
void output();
bool date();
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		input();
		output();
	}
	return 0;
}
void input()
{
	cin >> name >> brand >> pdate >> type;
}
void output()
{
	cout << name << " ";
	int i;
	bool f = date();
	if (f)
	{
		for (i = 0; i < 2; i++)
			if (!strcmp(twob[i], brand))
				break;
		cout << twob[1 - i] << " ";
		for (i = 0; i < 2; i++)
			if (!strcmp(twot[i], type))
				break;
		cout << twot[1 - i] << endl;
	}
	else
		cout << "ToT" << endl;
}
bool date()
{
	int y = 0, m = 0, d = 0, i, s;
	s = 1;
	for (i = 3; i >=0; i--)
	{
		y += s * (pdate[i] - '0');
		s *= 10;
	}
	if (y > 2009)
		return false;
	if (y < 2009)
		return true;
	s = 1;
	for (i = 6; i >= 5; i--)
	{
		m += s * (pdate[i] - '0');
		s *= 10;
	}
	if (m > 3)
		return false;
	if (m < 3)
		return true;
	d = pdate[9] - '0';
	if (d == 1)
		return true;
	else
		return false;
}
