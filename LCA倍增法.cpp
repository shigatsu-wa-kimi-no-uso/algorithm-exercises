#include<iostream>
#include<vector>
#include<cmath> 
using namespace std;

int fa[1000], depth[1000];
int dp[1000][10];
vector<int> g[1000];		//y=g[i][j]为节点i的第j个儿子为y

void link(int x, int y)	//建立xy的边 从x指向y
{
	g[x].push_back(y);
}

//dp[0][i]=0 根节点父亲为自身 根节点设为0 若不为0则需要手动设置dp[0][i]的值

void dfs(int x, int x_fa) //dfs遍历，初始化dp和depth
{
	int i;
	dp[x][0] = x_fa;		//x自己的父亲存储
	depth[x] = depth[x_fa] + 1;	//x深度
	for (i = 1; dp[x][i-1] ; ++i) //i初始值为1 易错, dp[x][i-1]当走2^(i-1)后节点为0(0为父亲或虚拟根节点)后面都是0没必要再遍历初始化 
	{
		dp[x][i] = dp[dp[x][i - 1]][i - 1]; //初始化dp表，根据性质，可追溯到上层，且未定义的点最终归为根节点的父亲即根节点
	}
	for (i = 0; i < g[x].size(); ++i) //x的儿子遍历循环
	{
		dfs(g[x][i], x);
	}
}


inline int lowbit(int x)	//lowbit求二进制为1的最低位对应的值
{
	return x & -x;	//结果为2的最低位所在位次方
}

int getLCA(int x, int y)
{
	if (depth[x] < depth[y]) swap(x, y);
	while (depth[x] != depth[y])
	{
		x = dp[x][(int)log2(lowbit(depth[x] - depth[y]))];
	}
	if (x == y) return x;
	for(register int i=9;i>=0;--i)		//【注意！！i初始值为事先估计好的深度的log2对数值 】 
	{
		if (dp[x][i] != dp[y][i])		//找到能跳的最大步，之后的步数一定在2^i以内,故i无需重置
		{
			x = dp[x][i];
			y = dp[y][i];
		}
	}
	return dp[x][0];
}

void dfsprint(int x, int x_fa) //dfs遍历，初始化dp和depth
{
	int i;
	depth[x] = depth[x_fa] + 1;	//x深度
	printf("fa:%d depth%d\n", x_fa, depth[x]);
	for (i = 0; i < g[x].size(); ++i) //x的儿子遍历循环
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
	dfs(0, 0);	//从父亲向下遍历
	//dfsprint(0, 0);
	//printdp();
	cout << getLCA(6, 8);

}
