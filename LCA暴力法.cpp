#include<iostream>
#include<vector>
using namespace std;

vector<int> g[20];

inline void link(int x, int y)  //连接x--->y	 y=g[i][x]即为i指向x的第i条边
{
	g[x].push_back(y);
}

int depth[20] = { 0 }, father[20];
int lca(int x, int y) //求x和y的最近公共祖先
{
	while (father[x] != father[y])
	{
		depth[x] > depth[y] ? x = father[x] : y = father[y];
	}
	return father[x];
}

int main()
{
	link(1, 0);
	link(4, 0);
	link(5, 0);
	link(2, 1);
	link(3, 1);
	link(6, 5);
	link(7, 5);
	link(8, 5);
	link(9, 7);
	
	int i,curr;
	/*dfs*/
	for (i = 0; i < 10; i++)		//求每个点的深度和父亲  
	{
		curr = i;
		while (!g[curr].empty())	//根判断（根没有父亲）
		{
			father[curr] = g[curr][0];	//i的直系父亲是g[i][0]
			curr = g[curr][0];   //curr指向父亲，下面主要是看深度
			depth[i]++;				//i的深度+1
		}
	}
	cout << lca(6, 9);

}
