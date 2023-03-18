#include<iostream>
#include<vector>
using namespace std;

//P1352 没有上司的舞会(树形DP)
int r[6001];
vector<int> son[6001];
int dp[6001][2];
int fa[6001];	//记录节点父亲，根节点父亲为0
//定义dp[i][0]为 职员i不参加时以i为上司的后续职员快乐指数最大值,dp[i][1]为去时..
// 关系式:
// dp[fa][0]=0+max(dp[son0][0],dp[son0][1])+max(dp[son1][0],dp[son1][1])+....
// dp[fa][1]=r[x]+dp[son0][0]+dp[son1][0]+....
//初始化: 
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
		dfs_dp(son[x][i]);				//对于每个节点，先深搜其儿子,再进行dp数组填充
	}
	dp[x][1] = r[x];	//节点x去，初始值1
	dp[x][0] = 0;	//节点x不去，初始值0
	for (i = 0; i < son[x].size(); i++)	//dp数组填充,状态转移方程
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
