#include<iostream>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define reg register int
using namespace std;



//P1434 
//记忆化搜索

int r, c;

struct point
{
	short h;
	char x;
	char y;
}map[103][103];

int dx[4] = { -1,0,1 ,0 };
int dy[4] = { 0,1,0,-1 };
int cnt[103][103];

queue<point> chk;

void dfs(point start,point p,int cntp)
{
	cntp++;						//搜索深度，代表滑雪道长度
	int b = 0;
	if (cnt[p.y][p.x])			//如果这个点被搜索过
	{
		cntp += cnt[p.y][p.x]-1;		//长度加上这个点之前的长度
		cnt[start.y][start.x] =max( cntp, cnt[start.y][start.x]);	//取较大值，其他点深搜结束时会修改这个值，保留最大的
		return;
	}

	for (reg i = 0; i <= 3; i++)
	{
		int x = p.x + dx[i];
		int y = p.y + dy[i];
		
		if (x > 0 && y > 0 && x <= c && y <= r && map[y][x].h < p.h)
		{
			dfs(start,map[y][x], cntp);
			b++;
		}
	}
	if (b == 0)		//b为0说明深搜结束，需要起点的值
	{
		cnt[start.y][start.x] = max(cntp,cnt[start.y][start.x]);			//记录每一点的长度
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin >> r >> c;
	int maxh = 0, maxx[103] = { 0 }, maxy[103] = { 0 };
	int n = 0;
	for (reg i = 1; i <= r; i++)
	{
		for (reg j = 1; j <= c; j++)
		{
			cin >> map[i][j].h;
			map[i][j].x = j;
			map[i][j].y = i;
		}
	}
	int ans = 0;
	for (reg i = 1; i <= r; i++)
	{
		for (reg j = 1; j <= c; j++)
		{
			dfs(map[i][j],map[i][j], 0);
			ans = max(ans, cnt[i][j]);
		}
	}

	cout << ans;
	return 0;

}
