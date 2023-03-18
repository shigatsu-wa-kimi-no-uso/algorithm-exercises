#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//P1629 邮递员送信

int dis[1005<<1];

int n, m;

struct EDGE
{
	int to;
	int l;
	EDGE(int to,int l)
		:to(to),l(l){}
};

struct NODE
{
	int id;
	int dis;
	NODE(int id,int dis)
		:id(id),dis(dis){}
	NODE(){}
	bool operator>(const NODE& rgt) const
	{
		return dis > rgt.dis;
	}
};

priority_queue<NODE,vector<NODE>,greater<NODE>> q;	//存储节点号

vector<EDGE> e[1005<<1];

void link(int x, int y, int z)
{
	e[x].push_back(EDGE(y,z));
}


void dijkstra(int s)
{
	for (int i = 1; i <= n*2; i++)
	{
		dis[i] = 0x3fffffff;
	}
	dis[s] = 0;
	q.push(NODE(s, 0));
	NODE now;
	while (!q.empty())
	{
		now = q.top();
		q.pop();
		if (dis[now.id]<now.dis) continue;
		
		for (EDGE v : e[now.id])
		{
			if (dis[v.to] > dis[now.id] + v.l)
			{
			//	cout << dis[v.to] << "\n";
				dis[v.to] = dis[now.id] + v.l;
				q.push(NODE(v.to,dis[v.to]));
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	int x, y, z;

	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y>> z;
		link(x, y, z);	
		link(y + n, x + n, z);	//建立反向图，用来求返回原点时的最短路
	}
	dijkstra(1);
	int ans = 0;
	for (int i = 2; i <= n; i++)
	{
		ans += dis[i];
	}
	dijkstra(1 + n);
	for (int i = n + 2; i <= n + n; i++)
	{
		ans += dis[i];
	}
	cout << ans;
	return 0;
}

