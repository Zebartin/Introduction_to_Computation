#include<iostream>
using namespace std;
int step = 1;
void move(int, char, char, char);
int main()
{
	int n;
	cout << "请输入盘子个数n：" << endl;
	cin >> n;
	cout << "在3根柱子上移" << "n" << "个盘子的步骤数为：" << endl;
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