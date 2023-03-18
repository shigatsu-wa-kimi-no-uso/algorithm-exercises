#include<iostream>
#include<queue>
#define reg register int
using namespace std;

int h, w, d, r;
char map[1005][1005];
//P3818

struct POINT
{
	int x, y;
	int time;
	bool flag;
	POINT(){}
	POINT(int x,int y,int time,bool flag)
		:x(x),y(y),time(time),flag(flag){}
	POINT operator+(const POINT right) const
	{
		return POINT(x + right.x, y + right.y, time + right.time, flag + right.flag);
	}
}op[4] = { {1,0,1,0},{-1,0,1,0},{0,1,1,0},{0,-1,1,0 }};

bool vis[1005][1005];		//没喝药访问
bool jump[1005][1005];			//喝药跳跃访问
bool noflagvis[1005][1005];		//喝药后访问
int times[1005][1005];

POINT sp;

queue<POINT> q;

int bfs()
{
	POINT curr;
	POINT next;
	while (!q.empty())
	{
		curr = q.front();
	//	cout << curr.x << " " << curr.y << " flag:" << curr.flag << " time:" << curr.time << '\n';
		if (curr.flag)
		{
			for (int i = 0; i < 4; i++)
			{
				next = curr + op[i];
				if (map[next.x][next.y] == '.' && vis[next.x][next.y] == 0)		
				{
					times[next.x][next.y] = next.time;
					//cout << curr.x << " " << curr.y << " to " << next.x << " " << next.y << '\n';
					if (next.x == h && next.y == w)
					{
					//	cout << "getans\n";
						return next.time;
					}
					q.push(next);
					vis[next.x][next.y] = 1;
				}
				//else
					//cout << curr.x << " " << curr.y << " to " << next.x << " " << next.y << " visited or blocked\n";
			}
			next = curr + sp;
			next.flag = 0;
			if (map[next.x][next.y] == '.' && jump[next.x][next.y] == 0)	
			{
				//cout << curr.x << " " << curr.y << " jump to " << next.x << " " << next.y << "\n";
				if (next.x == h && next.y == w)
				{
					return next.time;
				}
				if (times[next.x][next.y] == 0 || next.time < times[next.x][next.y])	//喝药用时比没喝药到达此点长，自动略过
				{
					q.push(next);
					jump[next.x][next.y] = 1;		//跳跃到达取1
				}
			}
		//	else
			//	cout << curr.x << " " << curr.y << " jump to " << next.x << " " << next.y << " visited or blocked\n";
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				next = curr + op[i];
				if (map[next.x][next.y] == '.' && noflagvis[next.x][next.y] == 0)		//3代表跳到过也正常走到过
				{
				//	cout << curr.x << " " << curr.y << " to " << next.x << " " << next.y << '\n';
					if (next.x == h && next.y == w)
					{
				//		cout << "getans\n";
						return next.time;
					}
					q.push(next);
					noflagvis[next.x][next.y] = 1;
				}
			//	else
				//	cout << curr.x << " " << curr.y << " to " << next.x << " " << next.y << " visited or blocked\n";
			}
		}
		q.pop();
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> h >> w >> d >> r;
	for (reg i = 1; i <= h; i++)
	{
		for (reg j = 1; j <= w; j++)
		{
			cin >> map[i][j];
		}
	}
	sp = POINT(d, r, 1, 0);
	vis[1][1] = 3;
	q.push(POINT(1, 1, 0, 1));
	cout << bfs();
	return 0;

}
