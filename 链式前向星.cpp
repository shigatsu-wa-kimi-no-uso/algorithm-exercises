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
	edge[++cnt].to = y;			//��cntָ��y
	edge[cnt].next = head[x];    //��cntָ��Ľڵ�ĸ���������һ��ָ������ӵı�head[x]��head[x]һ��Ϊ����x����һ���ߣ���Ϊ����x���ӵĵ�һ����ʱ��head[x]δ����ʼ����Ϊ0
	head[x] = cnt;				//����x��һ����Ϊ��cnt
}


void dfs(int x, int x_fa)
{
	for (register int i = head[x] /*����x�������һ�������*/; i/*û�и���ı�ʱΪ0*/; i = edge[x].next /*���׵���һ����*/)
	{
		dfs(i, x);
	}
}

int main()
{
	return 0;
}


