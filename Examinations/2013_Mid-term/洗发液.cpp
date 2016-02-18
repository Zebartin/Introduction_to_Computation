/*
描述
    王师傅这个人特别喜欢成双成对的事物, 他为发廊购入洗发液时, 每种类型的洗发液也都会购入两瓶. 
    近来几天日子很不太平, 发廊中出了一个叛徒, 他偷走了一瓶洗发液, 而且已经连夜逃到了科特迪瓦! 店里的洗发液乱成一团, 王师傅甚至不知道叛徒偷了哪瓶, 他快被强迫症压垮了, 伤心绝望痛, 甚至想要退出洗剪吹界! 
    请帮王师傅找到叛徒偷了哪种洗发液吧! 洗剪吹的未来就在你身上了!
关于输入
	第1行输入1个整型n(1<=n<=200), 代表洗发液的种类 
	第2行输入2n-1个整型, 代表留在发廊中的每瓶洗发液的种类, 洗发液的编号为1,2,..,n之间
关于输出
	1个整型, 代表被**叛徒**偷走的洗发液类型
*/
#include<iostream>
using namespace std;
int main()
{
	int a[201] = { 0 };
	int shampoo, n, i;
	cin >> n;
	for (i = 1; i < 2 * n; i++)
	{
		cin >> shampoo;
		a[shampoo] = !a[shampoo];
	}
	for (i = 1; i <= n;i++)
		if (a[i] != 0)
		{
			cout << i << endl;
			break;
		}
	return 0;
}
