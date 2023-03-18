#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n, a, b;

int map[1000][1000];
bool blocked[1000][1000];

struct POS
{
	int x, y;
	POS() {}
	POS(int x, int y)
		:x(x), y(y) {}
	POS operator+(const POS& p) const
	{
		return POS(x + p.x, y + p.y);
	}
};

queue<POS> q;

POS dir[4] = { {1,0},{-1,0},{0,1},{0,-1} };

struct POS2
{
	int x, y, t;
	bool operator<(const POS2& p) const
	{
		return t < p.t;
	}
};

POS2 pnt[55555];

void update(int time)
{
	static int ord = 0;
	while (time == pnt[ord].t)
	{
		int x = pnt[ord].x;
		int y = pnt[ord].y;
		blocked[x][y] = 1;
		blocked[x+1][y] = 1;
		blocked[x-1][y] = 1;
		blocked[x][y+1] = 1;
		blocked[x][y-1] = 1;
		ord++;
	}
}

void bfs(int x,int y)
{
	POS curr;
	POS next;
	q.push(POS(x, y));
	map[x][y] = 0;
	int t=0;
	update(0);
	while (!q.empty())
	{
		curr=q.front();
		q.pop();
		t = map[curr.x][curr.y] + 1;
		update(t);
		for (int i = 0; i < 4; i++)
		{
			next = curr + dir[i];
			if (next.x>=0 && next.y>=0 && map[next.x][next.y]==-1 && !blocked[next.x][next.y])
			{
				q.push(next);
				map[next.x][next.y] = map[curr.x][curr.y] + 1;
			}
		}
	}
	if(pnt[n - 1].t > t)
	{
		while (pnt[n - 1].t >= t)
		{
			update(t);
			t++;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> pnt[i].x >> pnt[i].y >> pnt[i].t;
	}
	for (int i = 0; i < 980; i++)
	{
		for (int j = 0; j < 980; j++)
		{
			map[i][j] = -1;
		}
	}
	sort(pnt, pnt + n, less<POS2>());
	bfs(0, 0);
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < 980; i++)
	{
		for (int j = 0; j < 980; j++)
		{
			if (blocked[i][j] || map[i][j]==-1) continue;
			ans = min(map[i][j], ans);
		}
	}
	if (ans == 0x3f3f3f3f)
	{
		ans = -1;
	}
	cout << ans;
	return 0;
}
