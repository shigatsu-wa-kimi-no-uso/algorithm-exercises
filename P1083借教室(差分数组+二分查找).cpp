#include<iostream>

using namespace std;

//P1083 [NOIP2012]
int r[(int)1E6 + 1];
int D[(int)1E6 + 1];	//差分数组
int need[(int)1E6 + 1];	//
int d[(int)1E6 + 1], s[(int)1E6 + 1], t[(int)1E6 + 1];
//约24MB

inline bool process(int x,int n)	//处理订单数,天数(输入最大天数)
{
	int i;
	memset(D, 0, sizeof(D));	//差分数组初始化0
	for (i = 1; i <= x; i++)
	{
		D[s[i]] += d[i];
		D[t[i] + 1] -= d[i];	//差分数组修改,前缀和为所需房间数
	}
	for (i = 1; i <= n; i++)
	{
		need[i] = D[i] + need[i - 1];	//前缀和求出需要房间数
		if (need[i] > r[i]) return 0; //不满足,直接返回0 
	}	
	return 1;	//全部满足返回1
}




int main()
{
	ios::sync_with_stdio(false);
	int n, m, i;
	cin >> n >> m;			//n:天数,m:订单数
	for (i = 1; i <= n; i++)
	{
		cin >> r[i];	//第i天数量为r[i]
	}
	for (i = 1; i <= m; i++)
	{
		cin >> d[i] >> s[i] >> t[i];
	}
	if (process(m, n))	//整体处理,看是否符合
	{
		cout << 0;
	}
	else
	{
		int lb = 1, ub = m,mid;//由于房间需求数(即need大小)与订单数成正比,故可以用二分法查找出哪一天开始不满足订单
		while (lb < ub)					//lb==ub时不再需要查找,结果即为lb,当lb=ub-1时,由于mid=lb满足需求即为lb+1==ub(此时mid未更新,需要返回lb才行,或者统一再次更新,最终结果均为lb==ub时即为找到),不满足则为mid==lb
		{
			mid = (lb + ub) / 2;
			if (process(mid, n))   //mid通过,需要提高下界
			{
				lb = mid+1;
			}
			else
			{
				ub = mid;	//否则降低上界
			}
			if (lb == ub) break; //传统找法,lb>ub时,为找不到,此题一定能找到 
		}
		cout << "-1\n" << lb;
	}

	return 0;
}

