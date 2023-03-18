#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

//P1273 有线电视网

int n, m;

int c[3005];

int w[3005];

vector<int> e[3005];

int f[3005][3005];	//第i节点选j个用户

inline void link(int x, int y)
{
	e[x].push_back(y);
}


int dfs(int now)
{
	if (e[now].size() == 0)
	{
		f[now][1] = c[now];
		return 1;
	}

	int sum=0;
	int sz;
	for (int i = 0; i < e[now].size(); i++)	//该节点连接几个儿子 即有几组
	{
		sz = dfs(e[now][i]);	//该组元素数 即子树大小
		sum += sz;
		for (int j = sum; j > 0; j--)	//更新状态	j为当前节点下当前选定儿子情况下总元素数，即背包容量
		{
			for (int k = 1; k <= sz; k++)	//对组中元素遍历 选i个
			{
				if (j - k >= 0)
					f[now][j] = max(f[now][j], f[now][j - k] + f[e[now][i]][k] -  w[e[now][i]]);
			}
		}
	}
	return sum;
}

int main()
{
	cin >> n >> m;
	memset(f, ~0x3f, sizeof(f));
	int k, x, y;
	for (int i = 1; i <= n-m; i++)
	{
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			cin >> x >> y;
			link(i, x);
			w[x] = y;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		f[i][0] = 0;
	}
	for (int i = n - m + 1; i <= n; i++)
	{
		cin >> y;
		c[i] = y;
	}
	int c = 0;
	dfs(1);
	for (int i = m; i > 0; i--)
	{
		if (f[1][i] >= 0)
		{
			cout << i;
			break;
		}
	}
	return 0;
}
