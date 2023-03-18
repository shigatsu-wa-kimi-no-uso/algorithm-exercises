#include<iostream>
#include<bitset>
using namespace std;

//À¶ÇÅ±­2021 íÀÂë³ÆÖØ 

int n;
int w[105];

bool b[100005];

int maxw;

bool vis[101][100001];

void dfs(int p,int wei)
{
	if (vis[p][wei]) return;
	vis[p][wei] = 1;
	if (wei > 0)
	{
		b[wei] = 1;
		maxw = max(wei, maxw);
	}

	for (int i = p + 1; i <= n; i++)
	{
		dfs(i, wei + w[i]);
		dfs(i, wei - w[i]);
	}
}

int main() 
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}

	dfs(0, 0);
	int ans = 0;
	for (int i = 1; i <= maxw; i++)
	{
		if (b[i])
			ans++;
	}
	cout << ans;
	return 0;
}
