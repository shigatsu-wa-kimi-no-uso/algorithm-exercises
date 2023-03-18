#include<iostream>
#include<queue>
using namespace std;

int n, m, x, y;

int map[500][500];

struct POS
{
	int x, y;
	POS(){}
	POS(int x,int y)
		:x(x),y(y){}
	POS operator+(const POS& p) const
	{
		return POS(x + p.x, y + p.y);
	}
};

queue<POS> q;

POS dir[8] = { {1,-2},{1,2},{-1,-2},{-1,2},{2,1},{2,-1},{-2,-1},{-2,1} };

void bfs(int x,int y)
{
	q.push(POS(x, y));
	POS curr;
	POS next;
	map[x][y] = 0;
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			next = curr + dir[i];
			if (map[next.x][next.y] == -1)
			{
				q.push(next);
				map[next.x][next.y] = map[curr.x][curr.y] + 1;
			}
		}
	}
}

int main()
{

	cin >> n >> m >> x >> y;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			map[i][j] = -1;
		}
	}
	bfs(x, y);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			printf("%-5d", map[i][j]);
		}
		cout << "\n";
	}
	return 0;
}
