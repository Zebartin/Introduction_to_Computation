/*
描述
	在N*N的迷宫内，“#”为墙，“.”为路，“s”为起点，“e”为终点，一共4个方向可以走。
	从左上角（(0,0)“s”）位置处走到右下角（(n-1,n-1)“e”）位置处，可以走通则输出YES，不可以走则输出NO。
关于输入
	输入的第一行为一个整数m，表示迷宫的数量。 
	其后每个迷宫数据的第一行为一个整数n（n≤16），表示迷宫的边长，接下来的n行每行n个字符，字符之间没有空格分隔。 
关于输出
	输出有m行，每行对应的迷宫能走，则输出YES，否则输出NO。
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
