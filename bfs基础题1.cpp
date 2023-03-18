#include <iostream>
#include<queue>
#include<cstring>				//使用memset需要此文件
using namespace std;

//P1588 
//bfs

long long x, y;


struct INFO
{
	int x;
	int step;
};

queue<INFO> nx;
bool vis[300000];			

int bfs(INFO start)
{
	nx.push(start);
	INFO curr;
	INFO next;
	vis[start.x] = 1;
	while (!nx.empty())
	{
		curr = nx.front();
		if (curr.x == y)				
			return curr.step;
		next.step = curr.step + 1;
		next.x = curr.x*2;
		if (next.x < y * 2)				//太大的数没有意义需要去除
		{
			if (vis[next.x] == 0)			//【重要】【易漏】需要记录每个点有没有被访问，防止重复访问
			{
				nx.push(next);
				vis[next.x] = 1;
			}
		}

		next.x = curr.x + 1;
		if (next.x <= y)
		{
			if (vis[next.x] == 0)
			{
				nx.push(next);
				vis[next.x] = 1;
			}
		}

		next.x = curr.x - 1;
		if (next.x>0)				//根据题意，小于0的数无意义
		{
			if (vis[next.x] == 0)
			{
				nx.push(next);
				vis[next.x] = 1;
			}
		}
		nx.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> x >> y;
		INFO start = { x,0 };
		cout<<bfs(start)<<'\n';
		nx = queue<INFO>();
		memset(vis, 0, sizeof(vis));			//【易漏】数据初始化
	}
	return 0;
}

