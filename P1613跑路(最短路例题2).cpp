#include<iostream>
#include<limits.h>
using namespace std;

//P1613跑路

int n,m;

bool g[55][55][64];

int dis[55][55];

/*dis[i][j]表示i到j的路径/边的长度
g[i][j][k]表示，i到j是否存在一条长度为2^k的路径
如果有，为true，没有就是false*/

void floyd()
{
    for(int k=1; k<=n; k++)
    {
        //注意点：枚举中间点的循环放在最前面
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
   
}

int main()
{
    cin>>n>>m;
    int x,y;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dis[i][j]=50;
        }
    }
    for(int i=1; i<=m; i++)
    {
        cin>>x>>y;
        g[x][y][0]=1;
        dis[x][y]=1;
    }
    for(int k=1; k<=64; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int t=1; t<=n; t++)
            {
                for(int j=1; j<=n; j++)
                {
                    //枚举三个点
                    if(g[i][t][k-1] && g[t][j][k-1])
                    {   /*如果i到t存在一条2^k-1长度的路径
                        并且t到j存在一条2^k-1长度的路径
                        就说明i到t，t到j都可以一秒到达，
                        路程*2刚好是2的幂，也可以一秒到达*/
                        g[i][j][k]=1;
                        //标记从i到j存在一条长度为2^k的路径
                        dis[i][j]=1;
                        //i到j距离可以一秒到达
                    }
                }
            }
        }
    }
    floyd();

    cout<<dis[1][n];

    return 0;
}