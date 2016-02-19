/*
描述
	小英是药学专业大三的学生，暑假期间获得了去医院药房实习的机会。 
	在药房实习期间，小英扎实的专业基础获得了医生的一致好评，得知小英在计算概论中取得过好成绩后，
	主任又额外交给她一项任务，解密抗战时期被加密过的一些伤员的名单。 
	经过研究，小英发现了如下加密规律（括号中是例子） 
	1.  原文中所有的字符都被循环左移了三个单位（dec  -> abz） 
	2.  逆序存储（abcd -> dcba ） 
	3.  大小写反转（abXY -> ABxy） 
关于输入
	共n+1行 
	第一行是名单中名字的个数n(1<=n <= 1000） 
	随后是n行，每行是一个加密的字符串。（串长小于12）
关于输出
	n行 
	按照字典顺序输出解密后的字符串
例子输入
	5
	WDDFSSP
	SDSDSDDo
	SDKGGFSIa
	LLLHFGFOl
	GSOOWFASOq
例子输出
	Dlvijjngv
	Orijikooo
	Rggvgvgv
	Trvdizrrvj
	svviggz
*/
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
void fun(char &c) {
	if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		c+=3;
	if(c>'z')
		c-=26;
	else if(c>'Z'&&c<'a')
		c-=26;
	if(c>='A'&&c<='Z')
		c=c-'A'+'a';
	else
		c=c-'a'+'A';
}
struct compare {
	bool operator()(string s1,string s2) {
		return lexicographical_compare(s1.begin(),s1.end(),s2.begin(),s2.end());
	}
};
void print(string s) {
	cout<<s<<endl;
}
int main() {
	int n;
	string s;
	cin>>n;
	multiset<string,compare> ms;
	while(n--) {
		cin>>s;
		for_each(s.begin(),s.end(),fun);
		reverse(s.begin(),s.end());
		ms.insert(s);
	}
	for_each(ms.begin(),ms.end(),print);
	return 0;
}
