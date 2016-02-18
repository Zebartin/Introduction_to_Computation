/*
描述
	为了庆祝成功度过世界末日，A研究所决定给研究员更换电脑。但是由于经费原因，并不是所有电脑都可以被更换。 
	A研究所规定，凡是在2009年3月1日以后生产的电脑，都不能进行更换（不含3月1日，也就是说2009年3月1日生产的电脑可以更换）。同时研究员对电脑的品牌也有自己的偏好。 
	研究员仅仅使用Dell和Lenovo的电脑，并且更换规则如下： 
	使用过Dell的研究员想要体验Lenovo的电脑； 
	使用过Lenovo的研究员想要体验Dell的电脑； 
	使用Desktop（台式机）的研究员想换成Laptop（笔记本）； 
	使用Laptop（笔记本）的研究员想换成Desktop（台式机）。
关于输入
	第一行为研究员的数目N，N<=100 
	接下来N行，每行表示研究员现在使用的电脑，格式为 
	人名 电脑牌子 生产日期 电脑类型 
	它们之间用空格分开，且人名、电脑牌子、生产日期、电脑类型均不含空格，且长度不超过50个字符 
	注：生产日期格式为：YYYY-MM-DD
关于输出
	输出N行，每行为更换后的电脑信息，包括： 
	人名 电脑牌子 电脑类型 
	如果无法更换，则输出： 
	人名 ToT
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
