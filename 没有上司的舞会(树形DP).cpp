#include<iostream>
#include<vector>
using namespace std;

//P1352 û����˾�����(����DP)
int r[6001];
vector<int> son[6001];
int dp[6001][2];
int fa[6001];	//��¼�ڵ㸸�ף����ڵ㸸��Ϊ0
//����dp[i][0]Ϊ ְԱi���μ�ʱ��iΪ��˾�ĺ���ְԱ����ָ�����ֵ,dp[i][1]Ϊȥʱ..
// ��ϵʽ:
// dp[fa][0]=0+max(dp[son0][0],dp[son0][1])+max(dp[son1][0],dp[son1][1])+....
// dp[fa][1]=r[x]+dp[son0][0]+dp[son1][0]+....
//��ʼ��: 
//dp[x][1]=r[x]+...,dp[x][0]=0+...
// 
inline void link(int x, int y)
{
	son[x].push_back(y);
	fa[y] = x;
}

inline int getroot(int x)
{
	if (fa[x])
		getroot(fa[x]);
	else return x;
}

inline void dfs_dp(int x)
{
	int i;
	for (i = 0; i < son[x].size(); i++)
	{
		dfs_dp(son[x][i]);				//����ÿ���ڵ㣬�����������,�ٽ���dp�������
	}
	dp[x][1] = r[x];	//�ڵ�xȥ����ʼֵ1
	dp[x][0] = 0;	//�ڵ�x��ȥ����ʼֵ0
	for (i = 0; i < son[x].size(); i++)	//dp�������,״̬ת�Ʒ���
	{
		dp[x][1] += dp[son[x][i]][0];		
		dp[x][0] += max(dp[son[x][i]][1], dp[son[x][i]][0]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int n, x, y,i;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> r[i];
	}
	for (i = 1; i < n; i++)
	{
		cin >> x >> y;
		link(y, x);
	}
	int root = getroot(1);
	dfs_dp(root);
	cout << max(dp[root][1], dp[root][0]);
	return 0;
}
