#include<iostream>
#include<queue>
#define reg register int

using namespace std;

int m, n;
int map[1005][1005];
int costinfo[1005][1005];
bool flaginfo[1005][1005];

//P3956


struct INFO
{
	int x, y;
	int cost;
	bool flag;		//已施法标记
	int color;
	bool illegal;
	INFO() {}
	INFO(int x,int y,int cost,bool flag,bool flag2)
		:x(x),y(y),cost(cost),flag(flag),illegal(flag2){}
	INFO operator+(const INFO& right) const		//right 运算符右边的结构体变量，规定右边为next信息，左边为curr信息
	{
		
		INFO next(x + right.x, y + right.y, cost, flag,0);
	//	cout << y << " " << x << " to " << next.y << " " << next.x<<":";
		if (next.x<1 || next.y<1 || next.x>m || next.y>m)		//出界
		{
		//	cout << "out of range\n";
			next.illegal = 1;
			return next;
		}

		if (map[y][x] != map[next.y][next.x] )	//不同色
		{
	//		cout << "different color "<<" this: "<<map[y][x]<< " next: " << map[next.y][next.x]<<'\n';
			if (map[next.y][next.x] != 0)
			{
				next.cost++;			//消耗金币+1
				if (flag)			//如果当前所在块颜色是施法得来的
				{	
					next.flag = 0;	//标记下一点非施法得来
				}
			}
			else if (map[next.y][next.x] == 0)	//如果下一块颜色与当前颜色不同,下一块为无色
			{
				if (flag)		//如果当前点为施法得来
				{	
					next.illegal = 1;		//标记此操作不合法
				}
				else
				{
					next.flag = 1;			//标记下一点为施法得来
					next.color = map[y][x];
					next.cost += 2;				
				}
			}
		}
		else
		{
	//		cout << "same color "<<" this: " << map[y][x] << " next: " << map[next.y][next.x]<<'\n';
			if (flag)
			{
				next.flag = 0;
			}
		}
		return next;
	}

}dir[4] = { {1,0,0,0,0},{-1,0,0,0,0},{0,1,0,0,0},{0,-1,0,0,0} };

queue<INFO> q;

int bfs()
{
	INFO curr;
	INFO next;
	int ans = 0x3f3f3f3f;

	while (!q.empty())
	{
		curr = q.front();
		if (curr.flag)
			map[curr.y][curr.x] = curr.color;
	//	cout << "\ncurrent cost " << curr.cost << '\n';
		for (reg i = 0; i < 4; i++)
		{
			next = curr + dir[i];
			if (next.illegal)
			{
			//	cout << curr.y << " " << curr.x << " to " << next.y << " " << next.x << " illegal\n";
				continue;
			}
		
			if (costinfo[next.y][next.x]!=0)	//这个点已加入列表
			{
			//	cout << curr.y << " " << curr.x << " to " << next.y << " " << next.x << " optimized out:";
				if (costinfo[next.y][next.x] < next.cost)	//消耗比已加入的大
				{
			//		cout<< " cost " << next.cost <<" : "<<costinfo[next.y][next.x]<<'\n';
					continue;
				}
				else if (costinfo[next.y][next.x] == next.cost && next.flag == flaginfo[next.y][next.x])	//数据相同跳过
				{
			//		cout<< " same data\n";
					continue;
				}
		//		cout <<" preferred"<< " cost " << next.cost << " : " << costinfo[next.y][next.x] << " flag " << next.flag << " : " << flaginfo[next.y][next.x] << '\n';
			}
		//	cout << curr.y << " " << curr.x << " to " << next.y << " " << next.x << " succeed ";
			if (next.x == m && next.y == m)
			{
					ans = min(next.cost, ans);
			//		cout << "\nGETANS:  " << next.cost << '\n';
			//		cout << " cost " << next.cost << " thisflag: " << curr.flag << " nextflag: " << next.flag << "\n";
			}
			else
			{
			//	cout<<" cost " << next.cost <<" thisflag: "<<curr.flag <<" nextflag: "<<next.flag<<"\n";

				costinfo[next.y][next.x] = next.cost;
				flaginfo[next.y][next.x] = next.flag;
				q.push(next);
			}	
		}
		if (curr.flag)					//如果当前点是施法得来
			map[curr.y][curr.x] = 0;
		q.pop();
	}
	return ans;
}


int main()
{
	ios::sync_with_stdio(false);
	cin >> m >> n;
	int x, y, c;
	for (reg i = 1; i <= n; i++)
	{
		cin >> y >> x >> c;
		map[y][x] = c + 1;		//把数据+1，2代表黄色，1代表红，此时0为无色
	}
	q.push(INFO(1, 1, 1, 0, 0));	//初始时设置起始点花费1，如果不设置，bfs内无法激活“已经走过”的判断，形成死循环
	costinfo[1][1] = 1;				
	if (m == 1 )		//坑，判断第一个点是否正确
	{
		cout << 0;
		return 0;
	}

	int ans = bfs();
	if (ans == 0x3f3f3f3f)
	{
		cout << -1;
	}
	else
	{
		cout << ans - 1;
	}
	return 0;

}
