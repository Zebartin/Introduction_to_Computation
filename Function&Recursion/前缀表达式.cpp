/*
����
	ǰ׺���ʽ��һ�ְ������ǰ�õ��������ʽ��������ͨ�ı��ʽ2 + 3��ǰ׺��ʾ��Ϊ+ 2 3��
	ǰ׺���ʽ���ŵ��������֮�䲻�������ȼ���ϵ��Ҳ���������Ÿı������������(2 + 3) * 4��
	ǰ׺��ʾ��Ϊ* + 2 3 4���������ǰ׺���ʽ��ֵ���������������+ - * /�ĸ���
��������
	����Ϊһ�У������������������֮�䶼�ÿո�ָ����������Ǹ�������
�������
	���Ϊһ�У����ʽ��ֵ�� 
	��ֱ����printf("%f\n", v)������ʽ��ֵv��
��������
	* + 11.0 12.0 + 24.0 35.0
�������
	1357.000000

��ʾ
	��ʹ��atof(str)���ַ���ת��Ϊһ��double���͵ĸ�������atof������stdlib.h�С� 
	�����ʹ�ú����ݹ���õķ�����⡣
*/
#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
double calculate();
int main()
{
	cout << fixed << setprecision(6) << calculate() << endl;

	return 0;
}
double calculate()
{
	char s[1111];
	cin >> s;
	switch (s[0])
	{
	case '+':return calculate() + calculate();
	case '-':return calculate() - calculate();
	case '*':return calculate()*calculate();
	case '/':return calculate() / calculate();
	default:return atof(s);
	}
}
