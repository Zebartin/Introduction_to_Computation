/*
����
	�������ף��յ����Ρ�5�ҿյ����̵Ĳ�Ʒ��һ���������ȹ����зֱ���ǰ5��������ǰ��Ҿ�֪��E���̵Ĳ�Ʒ���ǵ�2���͵�3���� 
	A���Ĵ���²⣺E����Ʒ��һ���� 
	B���Ĵ���²⣺�ҳ����ܻ�õڶ����� 
	C���Ĵ���²⣺A����Ʒ������ 
	D���Ĵ���²⣺C����Ʒ������õġ� 
	E���Ĵ���²⣺D����Ʒ���õ�һ���� 
	���Ƚ�������󣬷���ֻ�л�õ�һ���͵ڶ������������Ĵ���²���ȷ�������A��B��C��D��E���ǵڼ�����
��������
	�ޡ�
�������
	���ֻ��һ�У�Ҫ����A��B��C��D��E˳����������Σ�����֮��һ���ո������ 
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
