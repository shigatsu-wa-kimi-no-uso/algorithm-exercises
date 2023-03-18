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
	bool flag;		//��ʩ�����
	int color;
	bool illegal;
	INFO() {}
	INFO(int x,int y,int cost,bool flag,bool flag2)
		:x(x),y(y),cost(cost),flag(flag),illegal(flag2){}
	INFO operator+(const INFO& right) const		//right ������ұߵĽṹ��������涨�ұ�Ϊnext��Ϣ�����Ϊcurr��Ϣ
	{
		
		INFO next(x + right.x, y + right.y, cost, flag,0);
	//	cout << y << " " << x << " to " << next.y << " " << next.x<<":";
		if (next.x<1 || next.y<1 || next.x>m || next.y>m)		//����
		{
		//	cout << "out of range\n";
			next.illegal = 1;
			return next;
		}

		if (map[y][x] != map[next.y][next.x] )	//��ͬɫ
		{
	//		cout << "different color "<<" this: "<<map[y][x]<< " next: " << map[next.y][next.x]<<'\n';
			if (map[next.y][next.x] != 0)
			{
				next.cost++;			//���Ľ��+1
				if (flag)			//�����ǰ���ڿ���ɫ��ʩ��������
				{	
					next.flag = 0;	//�����һ���ʩ������
				}
			}
			else if (map[next.y][next.x] == 0)	//�����һ����ɫ�뵱ǰ��ɫ��ͬ,��һ��Ϊ��ɫ
			{
				if (flag)		//�����ǰ��Ϊʩ������
				{	
					next.illegal = 1;		//��Ǵ˲������Ϸ�
				}
				else
				{
					next.flag = 1;			//�����һ��Ϊʩ������
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
		
			if (costinfo[next.y][next.x]!=0)	//������Ѽ����б�
			{
			//	cout << curr.y << " " << curr.x << " to " << next.y << " " << next.x << " optimized out:";
				if (costinfo[next.y][next.x] < next.cost)	//���ı��Ѽ���Ĵ�
				{
			//		cout<< " cost " << next.cost <<" : "<<costinfo[next.y][next.x]<<'\n';
					continue;
				}
				else if (costinfo[next.y][next.x] == next.cost && next.flag == flaginfo[next.y][next.x])	//������ͬ����
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
		if (curr.flag)					//�����ǰ����ʩ������
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
		map[y][x] = c + 1;		//������+1��2�����ɫ��1����죬��ʱ0Ϊ��ɫ
	}
	q.push(INFO(1, 1, 1, 0, 0));	//��ʼʱ������ʼ�㻨��1����������ã�bfs���޷�����Ѿ��߹������жϣ��γ���ѭ��
	costinfo[1][1] = 1;				
	if (m == 1 )		//�ӣ��жϵ�һ�����Ƿ���ȷ
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
