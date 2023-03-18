#include<iostream>
#include<queue>
#include<utility>
#include<cmath>

using namespace std;

int a[(int)2E6 + 1];

struct elem
{
	int val;
	int index;
};

deque<elem> intvl;	//��������,��֤��Сֵ��ǰ,���ֵ�ں�

//P1440

int main()
{
	int n, m,i,j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cout << "0\n";
	for (i = 2; i <= n; i++)//���� [i-m,i-1]
	{
		if (!intvl.empty())		//������в�Ϊ��
		{
			if (intvl.front().index < i - m ) //��������У����Ƚ�����Ǹ��±��Ѿ�����������߽�͵���
				intvl.pop_front();
		}
		while ( !intvl.empty() && a[i - 1] < intvl.back().val) //a[i]����,��֤����ȷ��λ��,�Ա�֤������
		{
			intvl.pop_back();		//�ѱ�a[i]���Ԫ�ص�����
		}
		intvl.push_back({ a[i-1],i-1 });
		cout << intvl.front().val<<"\n";
	}
	return 0;


}
