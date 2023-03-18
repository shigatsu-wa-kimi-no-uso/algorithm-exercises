#include <iostream>
#include <queue>
#include<cstring>
#define reg register int
using namespace std;
int x, y, z;

//UVA532

char map[32][32][32];
bool vis[32][32][32];

struct POINT
{
	int x;
	int y;
	int z;
	int time;
	const POINT operator + (const POINT& dir) const
	{
		POINT tmp ;
		tmp.x = x + dir.x;
		tmp.y = y + dir.y;
		tmp.z = z + dir.z;
		tmp.time = time + dir.time;
		return tmp;
	}

}dir[6] = { {1,0,0,1},{0,1,0,1},{0,0,1,1},{-1,0,0,1},{0,-1,0,1},{0,0,-1,1} };

queue<POINT> pnt;


int bfs(POINT start)
{
	pnt.push(start);
	POINT curr;
	POINT next;
	while (!pnt.empty())
	{
		curr = pnt.front();
		for (reg i = 0; i < 6; i++)
		{
			next = curr + dir[i];
			if (map[next.z][next.y][next.x] == '.' && !vis[next.z][next.y][next.x])
			{
				pnt.push(next);
				vis[next.z][next.y][next.x] = 1;		//重要！控制是否已经访问，如果不加大幅影响效率
			}
			else if (map[next.z][next.y][next.x] == 'E')
			{
				return next.time;
			}
		}
		map[curr.z][curr.y][curr.x] = '@';
		pnt.pop();
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	POINT start;
	while (1)
	{
		cin >> z >> y >> x;
		if (z == 0 && y == 0 && x == 0)
		{
			return 0;
		}
		for (reg i = 1; i <= z; i++)
		{
			for (reg j = 1; j <= y; j++)
			{
				for (reg k = 1; k <= x; k++)
				{
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S')
					{
						start.z = i;
						start.y = j;
						start.x = k;
						start.time = 0;
					}
					
				}
			}
		}
		int ans = bfs(start);
		if (ans == -1)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << ans << " minute(s).\n";
		memset(map, 0, sizeof(map));
		memset(vis, 0, sizeof(vis));
		pnt = queue<POINT>();
	}
	return 0;
}

