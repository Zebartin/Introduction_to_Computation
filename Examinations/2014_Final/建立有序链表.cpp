/*
����
	����N��������ݣ�ÿ���������������������ɡ���ÿ�����ݹ���һ�������������ӱ�ͷ���������� 
	Ҫ�󣺲��������κ����������
��������
	�����һ�д���������ݵ�����N����������N�У�ÿ�а�������������
�������
	������ͷ��������Ԫ�أ�ÿ������֮���ÿո�ָ���ֱ�������ĩβ��
*/
#include<iostream>
using namespace std;

struct listcode
{
	int num;
	listcode *next;
};
int main()
{
	int N, num;
	cin >> N;
	listcode *temp = NULL, *ahead = NULL, *head = NULL;
	while (N--)
	{
		cin.get();
		while (cin.peek() != '\n')
		{
			cin >> num;
			temp = new listcode;
			temp->num = num;
			if (head)
				ahead->next = temp;
			else
				head = temp;
			ahead = temp;
		}
		temp->next = NULL;
		int t;
		listcode *tail = NULL;
		while (head != tail)
		{
			ahead = head;
			temp = ahead->next;
			while (temp != tail)
			{
				if (ahead->num > temp->num)
				{
					t = ahead->num;
					ahead->num = temp->num;
					temp->num = t;
				}
				ahead = temp;
				temp = temp->next;
			}
			tail = ahead;
		}
		cout << head->num;
		head = head->next;
		while (head)
		{
			cout << " " << head->num;
			head = head->next;
		}
		cout << endl;
	}
	return 0;
}
