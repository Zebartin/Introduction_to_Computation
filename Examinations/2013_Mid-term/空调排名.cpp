/*
描述
	夏日炎炎，空调走俏。5家空调厂商的产品在一次质量评比过程中分别获得前5名。评奖前大家就知道E厂商的产品不是第2名和第3名。 
	A厂的代表猜测：E厂产品第一名。 
	B厂的代表猜测：我厂可能获得第二名。 
	C厂的代表猜测：A厂产品质量最差。 
	D厂的代表猜测：C厂产品不是最好的。 
	E厂的代表猜测：D厂产品会获得第一名。 
	评比结果公布后，发现只有获得第一名和第二名的两个厂的代表猜测正确。请给出A，B，C，D，E各是第几名？
关于输入
	无。
关于输出
	输出只有一行，要求按照A，B，C，D，E顺序输出其名次，名次之间一个空格隔开。 
*/
#include<iostream>
using namespace std;
int main()
{
	int rank[5], word[5];
	for (rank[0] = 1; rank[0] <= 5; rank[0]++)
		for (rank[1] = 1; rank[1] <= 5; rank[1]++)
			for (rank[2] = 1; rank[2] <= 5; rank[2]++)
				for (rank[3] = 1; rank[3] <= 5; rank[3]++)
					if (rank[0] != rank[1] && rank[0] != rank[2] && rank[0] != rank[3] && rank[1] != rank[2] && rank[1] != rank[3] && rank[2] != rank[3])
					{
						rank[4] = 15 - rank[0] - rank[1] - rank[2] - rank[3];
						if (rank[4] != 2 && rank[4] != 3)
						{
							word[0] = (rank[4] == 1);
							word[1] = (rank[1] == 2);
							word[2] = (rank[0] == 5);
							word[3] = (rank[2] != 1);
							word[4] = (rank[3] == 1);
							int i, flag = 1;
							for (i = 0; i < 5 && flag; i++)
							{
								switch (rank[i])
								{
								case 1:
								case 2:
									if (word[i] != 1)
										flag = 0;
									break;
								case 3:
								case 4:
								case 5:
									if (word[i] != 0)
										flag = 0;
									break;
								}
							}
							if (flag)
							{
								cout << rank[0];
								for (i = 1; i < 5; i++)
									cout << " " << rank[i];
								cout << endl;
							}
						}
				}
	return 0;
}
