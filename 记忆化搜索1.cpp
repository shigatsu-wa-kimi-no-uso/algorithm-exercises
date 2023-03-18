#include<iostream>
#include<queue>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define reg register int
using namespace std;



//P1434 
//���仯����

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
	cntp++;						//������ȣ�����ѩ������
	int b = 0;
	if (cnt[p.y][p.x])			//�������㱻������
	{
		cntp += cnt[p.y][p.x]-1;		//���ȼ��������֮ǰ�ĳ���
		cnt[start.y][start.x] =max( cntp, cnt[start.y][start.x]);	//ȡ�ϴ�ֵ�����������ѽ���ʱ���޸����ֵ����������
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
	if (b == 0)		//bΪ0˵�����ѽ�������Ҫ����ֵ
	{
		cnt[start.y][start.x] = max(cntp,cnt[start.y][start.x]);			//��¼ÿһ��ĳ���
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
