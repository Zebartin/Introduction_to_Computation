/*
����
	��һ����ΪN����ΪM�ĳ������������ĳ�ʼ״̬ÿ���㶼�ǰ�ɫ�� 
	�������Ƕ��������²��������ȶ������е�k��ȾΪ��ɫ��������1-M֮�䣻Ȼ�����е�p��ҲȾΪ��ɫ��������1-N֮�䡣 
	������Ҫ�����Ⱦɫ֮�����ָ���İ�ɫ��������������Ǹ�������������ֵ 
	�������������0�����ɫ��1�����ɫ���� 
	0 0 0 1 0 0 
	0 0 0 1 0 0 
	1 1 1 1 1 1 
	0 0 0 1 0 0 
	���Ͻǵİ�ɫ�����������3*2�ģ�����Ӧ�������ֵΪ6
��������
	��һ��Ϊ��������N M����ʾԭʼ�����εĳ���1<=N,M<=100�� 
	�ڶ���Ϊһ������k����ʾҪȾɫ������ 
	������Ϊk���������Կո�ֿ�����ʾȾɫ���кţ������������򣬷�Χ��1-M 
	������Ϊһ������p����ʾҪȾɫ������ 
	������Ϊp���������Կո�ֿ�����ʾȾɫ���кţ������������򣬷�Χ��1-N
�������
	һ����������ʾ����ɫ�����ε����
*/
#include<iostream>
using namespace std;
int main()
{
	int N, M, k, p, i, dyerow[102],dyecol[102];
	int rectangle[102][102] = { 0 };
	cin >> N >> M;
	cin >> k;
	dyerow[0] = 0;
	for (i = 1; i <= k; i++)
		cin >> dyerow[i];
	dyerow[k + 1] = M + 1;
	cin >> p;
	dyecol[0] = 0;
	for (i = 1; i <= p; i++)
		cin >> dyecol[i];
	dyecol[p + 1] = N + 1;
	int maxheight = dyerow[1] - dyerow[0] - 1;
	for (i = 1; i <= k; i++)
		maxheight = maxheight>(dyerow[i + 1] - dyerow[i] - 1) ? maxheight : (dyerow[i + 1] - dyerow[i] - 1);
	int maxwidth = dyecol[1] - dyecol[0] - 1;
	for (i = 1; i <= p; i++)
		maxwidth = maxwidth>(dyecol[i + 1] - dyecol[i] - 1) ? maxwidth : (dyecol[i + 1] - dyecol[i] - 1);
	cout << maxheight * maxwidth << endl;
	return 0;
}
