#include<iostream>
#include<vector>
using namespace std;

//P2014 Ñ¡¿Î 

int n, m;

int w[305];

vector<int> e[305];

int f[305][305];

int dfs(int now)
{
	int sz;
	int sum = 0;
	f[now][1] = w[now];
	for (int v : e[now])
	{
		sz = dfs(v);
		sum += sz;
		for (int i = min(sum, m)+1; i > 1; i--)	//f[now][1]??now?? ?????
		{
			for (int j = 1; j <= sz; j++)
			{
				if (i-1 >= j)
					f[now][i] = max(f[now][i], f[now][i - j] + f[v][j]);
			}
		}
	}
	return sum + 1;
}

int main()
{
	cin >> n >> m;
	int x, y;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y;
		e[x].push_back(i);
		w[i] = y;
	}
	dfs(0);
	/*
	for (int i = 0; i <= n; i++)
	{
		for (int j = 1; j <= m + 1; j++)
		{
			cout << f[i][j] << " ";
		}
		cout << "\n";
	}*/

	cout << f[0][m + 1];
	return 0;
}
