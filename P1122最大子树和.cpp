#include<iostream>
#include<vector>
using namespace std;

int n, m;

vector<int> e[16005];

int v[16005];



inline void link(int x, int y)
{
	e[x].push_back(y);
	e[y].push_back(x);
}



int dfs(int x,int fa,int depth)
{
	for (int i = 0; i < e[x].size(); i++)
	{
		if (e[x][i] == fa) continue;
		v[x]+=dfs(e[x][i],x,depth+1);
	}

	if (v[x] < 0 && depth!=0)
	{
		return 0;
	}
	else return v[x];

}

int main()
{
	cin >> n;
	int t = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		if (v[t] < v[i])
		{
			t = i;
		}
	}
	int x, y;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		link(x, y);
	}
	cout << dfs(t,t,0);
	return 0;

}

