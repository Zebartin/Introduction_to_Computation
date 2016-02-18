/*
描述
	小朋友们在玩游戏：2k个小朋友围成一个圈，标号依次从1到2k，其中k个扮演好人，另k个扮演坏人。游戏规则如下：从第一个小孩开始报数，报到m时，第m个小孩被踢出，然后从下一个小孩开始，重复前面的过程，直到还剩下k个小孩，停止踢人。我们希望被踢出的都是坏人。已知前k个是好人，后k个是坏人，现在要求你对于每一个k，确定一个最小的正整数m，使得按游戏规则踢出的k个孩纸都是坏人。 
关于输入
	输入有多行，每行一个非负整数k，k不大于13。若输入为0，则标志着输入结束。 
关于输出
	对于每一个正整数k，输出最小的m
*/
#include<iostream>
using namespace std;
int main()
{
	int k, total, num, m;
	while (cin >> k)
	{
		if (k == 0)
			break;
		else
		{
			total = 2 * k;
			m = k;
			num = 1;
			while (total > k)
			{
				num = (num + m - 1) % total;
				if (num == 0)
					num = total;
				if (num > k)
					total--;
				else
				{
					total = 2 * k;
					num = 1;
					m++;
				}
			}
			cout << m << endl;
		}
	}
	return 0;
}
