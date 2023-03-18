#include<iostream>
#define INF 0x3f3f3f3f
using namespace std;

//P3371 最短路 floyd

int dis[10005][10005];

int n,m,s;

void floyd()
{
   for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i==k || dis[i][k]>=INF) continue;
            for(int j=1;j<=n;j++)  
            {
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
            }
        }
    }
}


int main()
{
   
    int x,y,w;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            dis[i][j]=INF;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y>>w;
        dis[x][y]=min(dis[x][y],w);
    }
    floyd();
 
    for(int i=1;i<=n;i++)
    {
        if(dis[s][i]>=INF) cout<<0x7fffffff<<" ";
        else
        cout<<dis[s][i]<<" ";
    }
    
    return 0;
}