/*
����
	���������������������ڣ��ֱ�Ϊ������������������ڣ����ǵ����ڳ���Ϊ23�졢28���33�졣ÿһ����������һ���Ǹ߷塣�ڸ߷����죬�˻�����Ӧ�ķ�����ֳ�ɫ�����磬�������ڵĸ߷壬�˻�˼ά���ݣ��������׸߶ȼ��С���Ϊ�������ڵ��ܳ���ͬ������ͨ���������ڵĸ߷岻������ͬһ�졣����ÿ���ˣ�������֪����ʱ�����߷�����ͬһ�졣����ÿ�����ڣ����ǻ�����ӵ�ǰ��ݵĵ�һ�쿪ʼ�������ָ߷����������һ���ǵ�һ�θ߷���ֵ�ʱ�䣩����������Ǹ���һ���ӵ����һ�쿪ʼ��������������Ӹ���ʱ�俪ʼ������������ʱ�䣩��һ�������߷�����ͬһ���ʱ�䣨�����ʱ��������������磺����ʱ��Ϊ10���´γ��������߷�ͬ���ʱ����12�������2��ע�����ﲻ��3����
��������
	�����ĸ�������p, e, i��d�� p, e, i�ֱ��ʾ��������к������߷���ֵ�ʱ�䣨ʱ��ӵ���ĵ�һ�쿪ʼ���㣩��d �Ǹ�����ʱ�䣬����С��p, e, �� i�� ���и���ʱ���ǷǸ��Ĳ���С��365, �����ʱ��С��21252 ��
�������
	�Ӹ���ʱ������һ�������߷�ͬ���ʱ�䣨�������ʱ�����������
��������
	0 0 0 0
	
	0 0 0 100
	
	5 20 34 325
	
	4 5 6 7
	
	283 102 23 320
	
	203 301 203 40
	
	-1 -1 -1 -1
�������
	Case 1: the next triple peak occurs in 21252 days.
	
	Case 2: the next triple peak occurs in 21152 days.
	
	Case 3: the next triple peak occurs in 19575 days.
	
	Case 4: the next triple peak occurs in 16994 days.
	
	Case 5: the next triple peak occurs in 8910 days.
	
	Case 6: the next triple peak occurs in 10789 days.
*/
#include<iostream>
using namespace std;
int main()
{
	int p, e, i, j, d, peak, cnt = 1;
	int time1 = 23, time2 = 28, time3 = 33;
	int days = time1 * time2 * time3;
	while (cin >> p >> e >> i >> d)
	{
		if (p == -1)
			break;
		j = 0;
		while (true)
		{
			peak = j++ * time1 + p;
			if ((peak - e) % time2 == 0)
				if ((peak - i) % time3 == 0)
					break;
		}
		while (peak >= days)
			peak -= days;
		if (peak <= d)
			peak += days;
		cout << "Case " << cnt++ << ": the next triple peak occurs in " << peak - d << " days." << endl;
	}
	return 0;
}
