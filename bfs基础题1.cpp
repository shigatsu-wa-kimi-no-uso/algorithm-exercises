#include <iostream>
#include<queue>
#include<cstring>				//ʹ��memset��Ҫ���ļ�
using namespace std;

//P1588 
//bfs

long long x, y;


struct INFO
{
	int x;
	int step;
};

queue<INFO> nx;
bool vis[300000];			

int bfs(INFO start)
{
	nx.push(start);
	INFO curr;
	INFO next;
	vis[start.x] = 1;
	while (!nx.empty())
	{
		curr = nx.front();
		if (curr.x == y)				
			return curr.step;
		next.step = curr.step + 1;
		next.x = curr.x*2;
		if (next.x < y * 2)				//̫�����û��������Ҫȥ��
		{
			if (vis[next.x] == 0)			//����Ҫ������©����Ҫ��¼ÿ������û�б����ʣ���ֹ�ظ�����
			{
				nx.push(next);
				vis[next.x] = 1;
			}
		}

		next.x = curr.x + 1;
		if (next.x <= y)
		{
			if (vis[next.x] == 0)
			{
				nx.push(next);
				vis[next.x] = 1;
			}
		}

		next.x = curr.x - 1;
		if (next.x>0)				//�������⣬С��0����������
		{
			if (vis[next.x] == 0)
			{
				nx.push(next);
				vis[next.x] = 1;
			}
		}
		nx.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> x >> y;
		INFO start = { x,0 };
		cout<<bfs(start)<<'\n';
		nx = queue<INFO>();
		memset(vis, 0, sizeof(vis));			//����©�����ݳ�ʼ��
	}
	return 0;
}

