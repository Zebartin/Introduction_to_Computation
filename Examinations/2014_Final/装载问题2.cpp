#include <iostream>
#include <memory.h>
using namespace std;
int container[20], v[20], load1[20], load2[20], n, c1, c2;

struct l {
	int ww;
	int loadon[20];
	int cnt;
} bw;
l load(l m) {
	int i, f = 0;
	for (i = 0; i < n; i++)
		if (c1 - m.ww >= container[i] && !v[i])
			break;
	if (i == n)
		return m;
	for (i = 0; i < n; i++) {
		if (v[i])
			continue;
		m.ww += container[i];
		m.loadon[m.cnt++] = container[i];
		v[i] = 1;
		if (m.ww <= c1) {
			l t = load(m);
			bw = bw.ww > t.ww ? bw : t;
		}
		m.ww -= container[i];
		m.loadon[--m.cnt] = 0;
		v[i] = 0;
	}
	return bw;
}

int main() {
	int i, sum = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> container[i];
		sum += container[i];
	}
	cin >> c1 >> c2;
	memset(v, 0, sizeof(v));
	memset(load1, 0, sizeof(load1));
	memset(load2, 0, sizeof(load2));
	l temp;
	temp.ww = 0;
	temp.cnt = 0;
	memset(temp.loadon, 0, sizeof(temp.loadon));
	temp = load(temp);
	if (sum - temp.ww > c2)
		cout << "can't find a way to Loading" << endl;
	else {
		cout << "ok,can load it\na way is:\n";
		cout << "the first trip load:" << temp.loadon[temp.cnt - 1];
		for (i = temp.cnt - 2; i >= 0; i--)
			cout << " " << temp.loadon[i];
		cout << endl;
		int j, t[20], c = 0, m = 0;
		cout << "the second trip load:";
		for (i = 0; i < n; i++) {
			int f = 1;
			for (j = 0; j < temp.cnt; j++)
				if (container[i] == temp.loadon[j]) {
					f = 0;
					m++;
					break;
				}
			if (f || m > temp.cnt)
				t[c++] = container[i];
		}
		cout << t[0];
		for (i = 1; i < c; i++)
			cout << " " << t[i];
		cout << endl;
	}
	return 0;
}
