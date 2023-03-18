#include<iostream>
#include<stdio.h>

using namespace std;

struct Node
{
	int to, next;
}edge[100];

int head[100],cnt;


inline void link(int x, int y)
{
	edge[++cnt].to = y;			//边cnt指向y
	edge[cnt].next = head[x];    //边cnt指向的节点的父亲有另外一条指向其儿子的边head[x]，head[x]一定为父亲x的上一条边，当为父亲x连接的第一条边时，head[x]未被初始化，为0
	head[x] = cnt;				//父亲x有一条边为边cnt
}


void dfs(int x, int x_fa)
{
	for (register int i = head[x] /*父亲x最后连的一条边序号*/; i/*没有更多的边时为0*/; i = edge[x].next /*父亲的下一条边*/)
	{
		dfs(i, x);
	}
}

int main()
{
	return 0;
}


