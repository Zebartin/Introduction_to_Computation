/*
����
	��N*N���Թ��ڣ���#��Ϊǽ����.��Ϊ·����s��Ϊ��㣬��e��Ϊ�յ㣬һ��4����������ߡ�
	�����Ͻǣ�(0,0)��s����λ�ô��ߵ����½ǣ�(n-1,n-1)��e����λ�ô���������ͨ�����YES���������������NO��
��������
	����ĵ�һ��Ϊһ������m����ʾ�Թ��������� 
	���ÿ���Թ����ݵĵ�һ��Ϊһ������n��n��16������ʾ�Թ��ı߳�����������n��ÿ��n���ַ����ַ�֮��û�пո�ָ��� 
�������
	�����m�У�ÿ�ж�Ӧ���Թ����ߣ������YES���������NO��
*/
#include<iostream>
using namespace std;
int n, a, b, dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 };
char maze[18][18];
void inputMaze();
void findS();
bool findWay(int, int);
int main()
{
	int i, m;
	cin >> m;
	for (i = 0; i < m; i++)
	{
		inputMaze();
		findS();
		if (findWay(a, b))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
void inputMaze()
{
	int i, j;
	cin >> n;
	for (i = 0; i < 18 * 18; i++)
		maze[i / 18][i % 18] = '#';
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			cin >> maze[i][j];
}
void findS()
{
	int i, j;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (maze[i][j] == 's')
			{
				a = i;
				b = j;
			}
}
bool findWay(int a, int b)
{
	maze[a][b] = '#';
	int i;
	for (i = 0; i < 4; i++)
		switch (maze[a + dy[i]][b + dx[i]])
		{
			case '#': continue;
			case 'e': return true;
			case '.': 
			{
				if (findWay(a + dy[i], b + dx[i]))
					return true;
				break;
			}
		}
	return false;
}
