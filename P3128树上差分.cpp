#include<iostream>
#include<vector>
#include<cmath>
#define maxn 500001
using namespace std;



//P3128 


struct Node
{
	int to, next;
}edge[maxn<<2];

int head[maxn],cnt;


int N, K;
vector<int> son[maxn];
int depth[maxn];
int dp[maxn][19];	//dp[n][x]=dp[ dp[n][x-1] ][x-1]
int D[maxn];
int ans;
//不超过50MB

inline int read() //快读
{
	int s = 0;
	char c = getchar();
	while (c < '0' || c>'9') 
		c = getchar();
	while (c >= '0' && c <= '9')
	{
		s = s * 10 + c - '0';
		c = getchar();
	}
	return s;
}

inline void link(int x, int y)
{
	edge[++cnt].to = y;			//边cnt指向y
	edge[cnt].next = head[x];    //边cnt的邻边为边head[x]
	head[x] = cnt;				//头x在edge链表中的偏移量
}

void dfs_init(int x, int x_fa)
{
	depth[x] = depth[x_fa] + 1;
	dp[x][0] = x_fa;
	for (register int i = 1; dp[x][i - 1]; ++i)
	{
		dp[x][i] = dp[dp[x][i - 1]][i - 1];
	}

	for (register int i = head[x]; i; i=edge[i].next)
	{
		if (edge[i].to != x_fa) 
			dfs_init(edge[i].to, x);
	}
}


inline int lowbit(int x)
{
	return x & (-x);
}

int getLCA(int x, int y)
{
	if (depth[x] < depth[y]) swap(x, y);
	while (depth[x] != depth[y])
	{
		x = dp[x][(int)log2(lowbit(depth[x] - depth[y]))];
	}
	if (x == y) return x;
	for(register int i=18;i>=0;--i)
	{
		if (dp[x][i] != dp[y][i])		//找到能跳的最大步，之后的步数一定在2^i以内,故i无需重置
		{
			x = dp[x][i];
			y = dp[y][i];
		}
	}
	return dp[x][0];
}


void dfs_calc(int x, int x_fa)
{

	for (register int i = head[x]; i; i=edge[i].next)
	{
		if (edge[i].to == x_fa) continue;
		dfs_calc(edge[i].to, x);
		D[x] += D[edge[i].to];
	}
	ans = max(ans, D[x]);
}

int main()
{
	ios::sync_with_stdio(false);
	N = read();
	K = read();
	int x, y;
	for (register int i = 1; i < N; ++i)
	{
		x = read();
		y = read();
		link(x, y);
		link(y, x);
	}
	dfs_init(1, 0);		//假设一个根节点为0,这个节点只有一个儿子1
	int lca;
	for (register int i = 1; i <= K; ++i)
	{
		x = read();
		y = read();
		++D[x];
		++D[y];
		lca = getLCA(x, y);
		--D[lca];
		--D[dp[lca][0]];
	}
	dfs_calc(1, 0); 
	cout << ans;
	return 0;
}
