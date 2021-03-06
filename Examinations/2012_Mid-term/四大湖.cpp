/*
描述
	我国有4大淡水湖。 
	
	A说：洞庭湖最大，洪泽湖最小，鄱阳湖第三。 
	B说：洪泽湖最大，洞庭湖最小，鄱阳湖第二，太湖第三。 
	C说：洪泽湖最小，洞庭湖第三。 
	D说：鄱阳湖最大，太湖最小，洪泽湖第二，洞庭湖第三。 

	已知这4个湖的大小均不相等，4个人每人仅答对一个， 
	请编程按照鄱阳湖、洞庭湖、太湖、洪泽湖的顺序给出他们的大小排名。
关于输入
	无。
关于输出
	输出为4行，第1行为鄱阳湖的大小名次，从大到小名次分别表示为1、2、3、4；第2、3、4行分别为洞庭湖、太湖、洪泽湖的大小名次。 
*/
#include<iostream>
using namespace std;
int main()
{
	int p, d, t, h;
	int A, B, C, D;
	for (p = 1; p <= 4; p++)
		for (d = 1; d <= 4; d++)
			for (t = 1; t <= 4; t++)
				for (h = 1; h <= 4;h++)
					if ((p - d)*(p - t)*(p - h)*(d - t)*(d - t)*(d - h)*(t - h) != 0)
					{
						A = (d == 1) + (h == 4) + (p == 3);
						B = (h == 1) + (d == 4) + (p == 2) + (t == 3);
						C = (h == 4) + (d == 3);
						D = (p == 1) + (t == 4) + (h == 2) + (d == 3);
						if (A == 1 && B == 1 && C == 1 && D == 1)
						{
							cout << p << endl
								 << d << endl
								 << t << endl
								 << h << endl;
							break;
						}
					}
	return 0;
}
