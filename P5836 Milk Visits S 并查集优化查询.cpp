#include<iostream>
using namespace std;

//P5836 Milk Visits S
//并查集优化查询路径上的值 

int n, m;

char node[100005];

int fa[100005];

int x,y;
char t;

int getfa(int x)
{
	if (fa[x] == x) return x;
	else return fa[x]=getfa(fa[x]);
}

void merge(int x, int y)
{
	fa[getfa(y)] = getfa(x);
}

int main(int argc, char** argv)
{
	cin >> n >> m;
	cin >> (node + 1);
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}

	for (int i = 1; i <= n-1; i++)
	{
		cin >> x >> y;
		if(node[x]==node[y])	//两节点值相同，合并
			//之前拥有相同的值的节点已经合并，可以保证原始的树上一条路径上值相同时被合并为父亲和儿子两个节点
			merge(x, y);
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		cin >> t;
		if (getfa(x) ==getfa(y) && t != node[x]) cout << 0;
		else cout << 1;
		//点已经合并，两个点的父亲相同说明原始树上这条路径上的值都相同
		// 又因为其中一个点上的值不等于查询值t 所以在原始树上这条路径上没有与t相等的点
		//否则说明有
	}

	return 0;
}

