#include<iostream>
#include<vector>
#include<cmath> 
using namespace std;

int fa[1000], depth[1000];
int dp[1000][10];
vector<int> g[1000];		//y=g[i][j]Ϊ�ڵ�i�ĵ�j������Ϊy

void link(int x, int y)	//����xy�ı� ��xָ��y
{
	g[x].push_back(y);
}

//dp[0][i]=0 ���ڵ㸸��Ϊ���� ���ڵ���Ϊ0 ����Ϊ0����Ҫ�ֶ�����dp[0][i]��ֵ

void dfs(int x, int x_fa) //dfs��������ʼ��dp��depth
{
	int i;
	dp[x][0] = x_fa;		//x�Լ��ĸ��״洢
	depth[x] = depth[x_fa] + 1;	//x���
	for (i = 1; dp[x][i-1] ; ++i) //i��ʼֵΪ1 �״�, dp[x][i-1]����2^(i-1)��ڵ�Ϊ0(0Ϊ���׻�������ڵ�)���涼��0û��Ҫ�ٱ�����ʼ�� 
	{
		dp[x][i] = dp[dp[x][i - 1]][i - 1]; //��ʼ��dp���������ʣ���׷�ݵ��ϲ㣬��δ����ĵ����չ�Ϊ���ڵ�ĸ��׼����ڵ�
	}
	for (i = 0; i < g[x].size(); ++i) //x�Ķ��ӱ���ѭ��
	{
		dfs(g[x][i], x);
	}
}


inline int lowbit(int x)	//lowbit�������Ϊ1�����λ��Ӧ��ֵ
{
	return x & -x;	//���Ϊ2�����λ����λ�η�
}

int getLCA(int x, int y)
{
	if (depth[x] < depth[y]) swap(x, y);
	while (depth[x] != depth[y])
	{
		x = dp[x][(int)log2(lowbit(depth[x] - depth[y]))];
	}
	if (x == y) return x;
	for(register int i=9;i>=0;--i)		//��ע�⣡��i��ʼֵΪ���ȹ��ƺõ���ȵ�log2����ֵ �� 
	{
		if (dp[x][i] != dp[y][i])		//�ҵ���������󲽣�֮��Ĳ���һ����2^i����,��i��������
		{
			x = dp[x][i];
			y = dp[y][i];
		}
	}
	return dp[x][0];
}

void dfsprint(int x, int x_fa) //dfs��������ʼ��dp��depth
{
	int i;
	depth[x] = depth[x_fa] + 1;	//x���
	printf("fa:%d depth%d\n", x_fa, depth[x]);
	for (i = 0; i < g[x].size(); ++i) //x�Ķ��ӱ���ѭ��
	{
		printf("->%d", g[x][i]);
		dfsprint(g[x][i], x);
	}
}

void printdp()
{
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("dp[%d][%d]=%d \n", i, j, dp[i][j]);
		}
	}
}

int main()
{
	link(0, 1);
	link(0, 4);
	link(0, 5);
	link(1, 2);
	link(1, 3);
	link(5, 6);
	link(5, 7);
	link(5, 8);
	link(7, 9);
	dfs(0, 0);	//�Ӹ������±���
	//dfsprint(0, 0);
	//printdp();
	cout << getLCA(6, 8);

}
