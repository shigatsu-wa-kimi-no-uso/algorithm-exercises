#include<iostream>
#include<queue>
#include<cstring>
#define reg register int

using namespace std;

//UVA11624

int n;
int r, c;
char map[1005][1005];
bool pushedj[1005][1005];
bool pushedf[1005][1005];
int ans;
int ntime;
int cnt;


struct POS
{
	int x, y;
	int time;
	POS(){}
	POS(int x,int y,int time)
		:x(x),y(y),time(time){}
	POS operator+(const POS obj) const
	{
		return POS(obj.x + x, obj.y + y, obj.time + time);
	}
}dir[4]{ {1,0,1},{-1,0,1},{0,1,1},{0,-1,1} };

queue<POS> qj;
queue<POS> qf;

void updatefire()
{
	static POS currf;
	static POS nextf;
	while (!qf.empty())
	{
		currf = qf.front();
		if(currf.time != ntime )	//火势更新完毕后，时间不对自动跳出
		{
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			nextf = currf + dir[i];
			if ((map[nextf.y][nextf.x] == '.' || map[nextf.y][nextf.x] == 'J') && pushedf[nextf.y][nextf.x] == 0)
			{
				qf.push(nextf);
				pushedf[nextf.y][nextf.x] = 1;
				map[nextf.y][nextf.x] = 'F';
			}
		}
		qf.pop();
	}
}

int bfs()
{
	POS currj = qj.front();
	POS nextj;
	updatefire();	//先烧，更新第一分钟的火势
	if (currj.y == r || currj.y == 1 || currj.x == c || currj.x == 1)		//判断第一个点 重要
	{
		return currj.time;
	}
	while (!qj.empty())
	{
		currj = qj.front();
		if (ntime != currj.time)	//更新时间，同时更新火势
		{
			ntime = currj.time;
			/*
			cout << '\n';
			for (reg j = 1; j <= r; j++)
			{
				
				for (reg k = 1; k <= c; k++)
				{
					cout<< map[j][k];
				}
				cout << '\n';
			}
			*/
			updatefire();		//更新ntime+1时的火势
		}
		for (int i = 0; i < 4; i++)
		{
			nextj = currj + dir[i];
	//		cout << nextj.y << " " << nextj.x << " " << map[nextj.y][nextj.x]<<"\n";
			if (map[nextj.y][nextj.x] == '.' && pushedj[nextj.y][nextj.x] == 0)
			{
				if (nextj.y == r || nextj.y == 1 || nextj.x == c || nextj.x == 1)
				{
		//			cout << nextj.y << " " << nextj.x << " " << map[nextj.y][nextj.x];
					return nextj.time;
				}
		//		cout << "push:\n";
		//		cout << nextj.y << " " << nextj.x << " " << map[nextj.y][nextj.x] << '\n';
				qj.push(nextj);
				pushedj[nextj.y][nextj.x] = 1;
			}
			
		}
		qj.pop();
	}
	return -1;
}




int main()
{
	ios::sync_with_stdio(false);
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> r >> c;
		for (reg j = 1; j <= r; j++)
		{
			for (reg k = 1; k <= c; k++)
			{
				cin >> map[j][k];
				pushedj[j][k] = 0;
				pushedf[j][k] = 0;
				if (map[j][k] == 'J')
					qj.push(POS(k, j, 0));
				else if (map[j][k] == 'F')
					qf.push(POS(k,j,0));
			}
		}
		int ans = bfs();
		if (ans == -1)
		{
			cout << "IMPOSSIBLE\n";
		}
		else cout << ans + 1 << '\n';
		ntime = 0;
		cnt = 0;
		qj = queue<POS>();
		qf = queue<POS>();
	}
	return 0;

}


