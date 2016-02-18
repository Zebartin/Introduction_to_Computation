#include<iostream>
#include<memory.h> 
using namespace std;

int weight[20], c[2], n, sum = 0;
int candidate[20], chosen[20], maxW = 0;

void load(int num, int ts)
{
	if (sum - ts <= c[1])
		if (maxW < ts)
		{
			maxW = ts;
			memcpy(chosen, candidate, sizeof(chosen));
			return;
		}
	if (num == n)
		return;
	for (int i = num; i < n; i++)
		if (!candidate[i] && ts + weight[i] <= c[0])
		{
			candidate[i] = 1;
			load(num + 1, ts + weight[i]);
			candidate[i] = 0;
		}
	return;
}
int main()
{
	memset(candidate, 0, sizeof(candidate));
	memset(chosen, 0, sizeof(chosen));
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
		sum += weight[i];
	}
	cin >> c[0] >> c[1];
	load(0, 0);
	if (maxW)
	{
		int i, f = 1;
		cout << "ok,can load it\na way is:\nthe first trip load:";
		for (i = 0; i < n; i++)
			if (chosen[i])
				if (f)
				{
					cout << weight[i];
					f = 0;
				}
				else
					cout << " " << weight[i];
		f = 1;
		cout << "\nthe second trip load:";
		for (i = 0; i < n; i++)
			if(!chosen[i])
				if (f)
				{
					cout << weight[i];
					f = 0;
				}
				else
					cout << " " << weight[i];
		cout << endl;
	}
	else
		cout << "can't find a way to Loading" << endl;
	return 0;
}
