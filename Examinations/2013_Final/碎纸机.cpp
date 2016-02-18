#include<iostream>
#include<cstring>
using namespace std;
int target, tempNumber, numbers[6], cutNum[6], cnt1;
char str[7];
struct largest
{
	int s;
	int cut[6];
	int cnt;
	int n;
} lar;

void cut(int p,int ts)
{
	if (p == cnt1)
	{
		if (lar.s < ts)
		{
			memcpy(lar.cut, cutNum, sizeof(cutNum));
			lar.s = ts;
			lar.cnt = tempNumber;
			lar.n = 1;
		}
		else if (lar.s == ts)
			lar.n++;
		return;
	}
	int value = 0;
	for (int i = p + 1; i <= cnt1; i++)
	{
		value *= 10;
		value += numbers[i - 1];
		if (value + ts > target)
			return;
		cutNum[tempNumber++] = value;
		cut(i, value + ts);
		cutNum[--tempNumber] = 0;
	}
}
int main()
{
	while (cin >> target >> str)
	{
		lar.s = lar.n = tempNumber = lar.cnt = 0;
		memset(lar.cut, 0, sizeof(lar.cut));
		memset(cutNum, 0, sizeof(cutNum));
		memset(numbers, 0, sizeof(numbers));
		if (!target)
			break;
		cnt1 = 0;
		for (int i = 0; i < strlen(str); i++)
			numbers[cnt1++] = str[i] - '0';
		cut(0, 0);
		if (lar.s)
			if (lar.n - 1)
				cout << "rejected" << endl;
			else
			{
				cout << lar.s;
				for (int i = 0; i < lar.cnt; i++)
					cout << " " << lar.cut[i];
				cout << endl;
			}
		else
			cout << "error" << endl;
	}
	return 0;
}
