#include<iostream>
#include<vector>
using namespace std;

//P1064 金明的预算方案 依赖背包

vector<int> e[65];

int w[65];
int v[65];

void link(int x, int y)
{
	e[x].push_back(y);
}

int n, m;

int f[32005];

vector<int> ma;

int main()
{
	cin >> n >> m;
	int x;
	int g = 0;
	for (int i = 1; i <= m; i++)
	{
		cin >> v[i] >> w[i] >> x;
		if (x == 0) ma.push_back(i);
		else 
			link(x, i);
	}
	g = ma.size();
	for (int i = 0; i < g; i++)
	{
		for (int j = n; j > 0; j--)
		{
			int now = ma[i];
			if (j >= v[now])
			{
				f[j] = max(f[j], f[j - v[now]] + w[now] * v[now]);
			}
			int t = e[now].size();
			if (t == 1)
			{
				if (j >= v[now] + v[e[now][0]])
				{
					f[j] = max(f[j], f[j - v[now]-v[e[now][0]]] + w[now] * v[now]+w[e[now][0]]*v[e[now][0]]);
				}
			}
			else if (t == 2)
			{
				if (j >= v[now] + v[e[now][0]])
				{
					f[j] = max(f[j], f[j - v[now] - v[e[now][0]]] + w[now] * v[now] + w[e[now][0]] * v[e[now][0]]);
				}
				if (j >= v[now] + v[e[now][1]])
				{
					f[j] = max(f[j], f[j - v[now] - v[e[now][1]]] + w[now] * v[now] + w[e[now][1]] * v[e[now][1]]);
				}
				if (j >= v[now] + v[e[now][0]]+v[e[now][1]])
				{
					f[j] = max(f[j], f[j - v[now] - v[e[now][0]]-v[e[now][1]]] + w[now] * v[now] + w[e[now][0]] * v[e[now][0]]+ w[e[now][1]] * v[e[now][1]]);
				}
			}
		}
	}
	cout << f[n];
	return 0;
}
