#include<iostream>
using namespace std;
int main()
{
	int n, length, area, i, k, max = 0, lowest, height[20000];
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> height[i];
	for (i = 0; i < n; i++)
		max = max > height[i] ? max : height[i];
	for (length = 2; length <= n; length++)
		for (i = 0; i < n - length + 1; i++)
		{	
			lowest = INT_MAX;
			for (k = i; k < i + length; k++)
				lowest = lowest < height[k] ? lowest : height[k];
			area = lowest * length;
			max = area > max ? area : max;
		}
	cout << max << endl;
	return 0;
}
