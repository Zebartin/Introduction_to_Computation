/*
描述
	给定N组测试数据，每组测试数据由若干整数组成。用每组数据构成一个有序链表，并从表头输出这个链表。 
	要求：不允许用任何数组操作。
关于输入
	输入第一行代表测试数据的组数N。接下来的N行，每行包含若干整数。
关于输出
	从链表头输出链表的元素，每个数据之间用空格分隔，直到链表的末尾。
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
