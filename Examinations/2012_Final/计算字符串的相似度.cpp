/*
描述
	在计算机程序中，往往会大量使用字符串。对于不同的字符串，我们总希望能够有办法判断其相似度。
	因此，我们定义了一套操作方法来把两个不同的字符串变得相同。 
	
	具体可选的操作方法有： 
	1. 修改一个字符，例如将"a"修改为"b"； 
	2. 增加一个字符，例如将"abdd"变为"aebdd" 
	3. 删除一个字符，例如将"travelling"变为"traveling" 
	
	例如，对于两个字符串"abcdefg"和"abcdef"两个字符串来说，我们可以通过“将前一个字符串减少一个g”
	或者“给后一个字符串增加一个g”这两种方式来使得它们相同，这两种方案，都仅需要一次操作。 
	
	将修改字符串操作需要的次数定义为两个字符串之间的距离，而相似度等于“距离+1”的倒数。例如，
	上例中"abcdefg"和"abcdef"的距离为1，则其相似度为1/2=0.5. 
	
	给定任意两个字符串(长度20以内)，写出一个程序来求出它们的相似度。 

关于输入
	第一行有一个整数n。表示测试数据的组数， 
	接下来共n行，每行两个字符串，用空格隔开。表示要计算距离的两个字符串 
	字符串长度不超过20。
关于输出
	针对每一组测试数据输出两个字符串的相似度，保留小数点后6位。
*/
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
char str1[21], str2[21];

int compare(char *p1, char *p2)
{
	if (!*p2)
		return 1 + strlen(str1) - (p1 - str1);
	if (!*p1)
		return 1 + strlen(str2) - (p2 - str2);
	if (*p1 == *p2)
		return compare(p1 + 1, p2 + 1);
	else
	{
		int s1 = 1 + compare(p1, p2 + 1);
		int s2 = 1 + compare(p1 + 1, p2 + 1);
		return s1 < s2 ? s1 : s2;
	}
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		cin >> str1 >> str2;
		if (strlen(str1) > strlen(str2))
		{
			char temp[21];
			strcpy(temp, str1);
			strcpy(str1, str2);
			strcpy(str2, temp);
		}
		cout << fixed << setprecision(6) << 1.0 / compare(str1, str2) << endl;
	}

	return 0;
}
