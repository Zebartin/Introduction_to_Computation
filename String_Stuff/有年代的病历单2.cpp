/*
����
	СӢ��ҩѧרҵ������ѧ��������ڼ�����ȥҽԺҩ��ʵϰ�Ļ��ᡣ 
	��ҩ��ʵϰ�ڼ䣬СӢ��ʵ��רҵ���������ҽ����һ�º�������֪СӢ�ڼ��������ȡ�ù��óɼ���
	�����ֶ��⽻����һ�����񣬽��ܿ�սʱ�ڱ����ܹ���һЩ��Ա�������� 
	�����о���СӢ���������¼��ܹ��ɣ������������ӣ� 
	1.  ԭ�������е��ַ�����ѭ��������������λ��dec  -> abz�� 
	2.  ����洢��abcd -> dcba �� 
	3.  ��Сд��ת��abXY -> ABxy�� 
��������
	��n+1�� 
	��һ�������������ֵĸ���n(1<=n <= 1000�� 
	�����n�У�ÿ����һ�����ܵ��ַ�����������С��12��
�������
	n�� 
	�����ֵ�˳��������ܺ���ַ���
��������
	5
	WDDFSSP
	SDSDSDDo
	SDKGGFSIa
	LLLHFGFOl
	GSOOWFASOq
�������
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
