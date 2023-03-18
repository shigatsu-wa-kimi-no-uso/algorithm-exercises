#include<iostream>
#include<queue>
using namespace std;

int n, a, b;

int id[222];
int vis[222];
queue<int> q;

void bfs(int x)
{
	q.push(x);
	int curr;
	int next;
	vis[x] = 0;
	while (!q.empty())
	{
		curr=q.front();
		q.pop();
		next = curr - id[curr];
		if (next > 0 && vis[next]==-1)
		{
			q.push(next);
			vis[next] = vis[curr] + 1;
		}
		next = curr + id[curr];
		if (next <= n && vis[next] == -1)
		{
			q.push(next);
			vis[next] = vis[curr] + 1;
		}
	}
}

int main()
{
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
	{
		cin >> id[i];
		vis[i] = -1;
	}
	bfs(a);
	cout << vis[b];
	return 0;
}
