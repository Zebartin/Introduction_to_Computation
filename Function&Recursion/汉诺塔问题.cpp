#include<iostream>
using namespace std;
int step = 1;
void move(int, char, char, char);
int main()
{
	int n;
	cout << "���������Ӹ���n��" << endl;
	cin >> n;
	cout << "��3����������" << "n" << "�����ӵĲ�����Ϊ��" << endl;
	move(n, 'a', 'b', 'c');
	system("pause");
	return 0;
}
void move(int m, char p, char q, char r)
{
	if (m == 1)
	{
		cout << step << ": move " << m << " from " << p << " to " << r << endl;
		step += 1;
	}
	else
	{
		move(m - 1, p, r, q);
		cout << step << ": move " << m << " from " << p << " to " << r << endl;
		step += 1;
		move(m - 1, q, p, r);
	}
}