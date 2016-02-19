#include<iostream>
#include<cstring>
using namespace std;
int n;
char str[10], a[10];
void permutation(int);
int main()
{
	cin.getline(str, 10);
	n = strlen(str);
	memset(a, 0, sizeof(a));
	permutation(0);
	system("pause");
	return 0;
}
void permutation(int z)
{
	int i, j;
	if (z == n)
	{
		a[z] = '\0';
		cout << a << endl;
		return;
	}
	for (i = 0; i < n; i++)
	{
		int f = 0;
		for (j = 0; j < z; j++)
			if (a[j] == str[i])
			{
				f = 1;
				break;
			}
		if (!f)
		{
			a[z] = str[i];
			permutation(z + 1);
		}
	}
}