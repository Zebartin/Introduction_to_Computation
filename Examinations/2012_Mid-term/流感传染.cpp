/*
����
	��һ���׸���Ⱥס������״���������ڣ�������Ϊn*n�ľ���ÿ�����Ϊһ�����䣬���������ס�ˣ�Ҳ���ܿ��š�
	�ڵ�һ�죬��Щ��������˵������У��Ժ�ÿ�죬�����е��˻�ʹ���ھӴ�Ⱦ�����У����Ѿ��ò��Ĳ��䣩��
	�շ��䲻�ᴫȾ���������m������е�������
��������
	��һ��һ������n��n������100����ʾ��n*n�����᷿�䡣 
	��������n�У�ÿ��n���ַ�����.����ʾ��һ��÷���ס�Ž������ˣ���#����ʾ�÷�����ţ�
	��@����ʾ��һ��÷���ס�ŵ����е��ˡ� 
	��������һ����һ������m��m������100. 
�������
	�����m�죬�����е�����
*/ 
#include<iostream>
using namespace std;
int main()
{
	int i, j, n, m, number = 0;
	char rooms[102][102],temp[102][102];
	int drow[4] = { -1,1,0,0 }, dcol[4] = { 0,0,-1,1 };
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			cin >> rooms[i][j];
			temp[i][j] = rooms[i][j];
		}
	cin >> m;
	for (int day = 0; day < m; day++)
	{
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				rooms[i][j] = temp[i][j];
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (rooms[i][j] == '@')
					for (int k = 0; k < 4; k++)
						if (rooms[i + drow[k]][j + dcol[k]] == '.')
							temp[i + drow[k]][j + dcol[k]] = '@';
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (rooms[i][j] == '@')
				number++;
	cout << number << endl;
	return 0;
}
