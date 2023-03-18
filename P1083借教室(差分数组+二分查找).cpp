#include<iostream>

using namespace std;

//P1083 [NOIP2012]
int r[(int)1E6 + 1];
int D[(int)1E6 + 1];	//�������
int need[(int)1E6 + 1];	//
int d[(int)1E6 + 1], s[(int)1E6 + 1], t[(int)1E6 + 1];
//Լ24MB

inline bool process(int x,int n)	//��������,����(�����������)
{
	int i;
	memset(D, 0, sizeof(D));	//��������ʼ��0
	for (i = 1; i <= x; i++)
	{
		D[s[i]] += d[i];
		D[t[i] + 1] -= d[i];	//��������޸�,ǰ׺��Ϊ���跿����
	}
	for (i = 1; i <= n; i++)
	{
		need[i] = D[i] + need[i - 1];	//ǰ׺�������Ҫ������
		if (need[i] > r[i]) return 0; //������,ֱ�ӷ���0 
	}	
	return 1;	//ȫ�����㷵��1
}




int main()
{
	ios::sync_with_stdio(false);
	int n, m, i;
	cin >> n >> m;			//n:����,m:������
	for (i = 1; i <= n; i++)
	{
		cin >> r[i];	//��i������Ϊr[i]
	}
	for (i = 1; i <= m; i++)
	{
		cin >> d[i] >> s[i] >> t[i];
	}
	if (process(m, n))	//���崦��,���Ƿ����
	{
		cout << 0;
	}
	else
	{
		int lb = 1, ub = m,mid;//���ڷ���������(��need��С)�붩����������,�ʿ����ö��ַ����ҳ���һ�쿪ʼ�����㶩��
		while (lb < ub)					//lb==ubʱ������Ҫ����,�����Ϊlb,��lb=ub-1ʱ,����mid=lb��������Ϊlb+1==ub(��ʱmidδ����,��Ҫ����lb����,����ͳһ�ٴθ���,���ս����Ϊlb==ubʱ��Ϊ�ҵ�),��������Ϊmid==lb
		{
			mid = (lb + ub) / 2;
			if (process(mid, n))   //midͨ��,��Ҫ����½�
			{
				lb = mid+1;
			}
			else
			{
				ub = mid;	//���򽵵��Ͻ�
			}
			if (lb == ub) break; //��ͳ�ҷ�,lb>ubʱ,Ϊ�Ҳ���,����һ�����ҵ� 
		}
		cout << "-1\n" << lb;
	}

	return 0;
}

