#include<iostream>
#include<vector>
using namespace std;

vector<int> g[11];
int length[10];
int far1[2], far2[2];	//记录直径两端节点号和长度

void link(int x, int y,int w)
{
	g[x].push_back(y);
	g[y].push_back(x);

}


void bfs(int x,int x_fa)
{
	length[x] = length[x_fa] + 1;
	int i;
	for (i = 0; i < g[x].size(); i++)
	{
		if (g[x][i] != x_fa) bfs(g[x][i], x);
	}
}

//两次遍历求树的直径  （第一次遍历得树的较远点,第二次从这个点出发找到离它最远的点的其中一个）
void getd()
{
	bfs(2, 2);	//深搜目的找到最远节点，由于是双向箭头 因此屏蔽了父亲，故初始参数父亲需要与自己相同
	int i;
	for (i = 1; i < 10; i++)
	{
		far1[1] > length[i] || (far1[0] = i,far1[1]=length[i]);
	}
	memset(length, 0, sizeof(length));
	bfs(far1[0], far1[0]);
	for (i = 1; i < 10; i++)
	{
		far2[1] > length[i] || (far2[0] = i, far2[1] = length[i]);
	}
	cout << far1[0] << " " << far2[0] << " "<<far2[1];

}


int main()
{
	int n,i,x,y;
	//to be filled

	return 0;
}

