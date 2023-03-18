#include<iostream>
#include<vector>
#include<cstring>
#define f(x,y) for(int i=x;i<=y;i++)
using namespace std;

//P2853奶牛聚会

vector<short> e[1005];
int k,n,m;
int cnt;

void link(int x,int y)
{
    e[x].push_back(y);
}

bool vis[1005];
int ans=0;
bool exist[1005];
short pos[1005];
short pass[1005];
int maxl;

void dfs(int x)
{   
    pass[x]++;
    for(short v : e[x])
    {
        if(!vis[v])
        {
            vis[v]=1;
            dfs(v);
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin>>k>>n>>m;
    int p;
    f(1,k)
    {
        cin>>p;
        if(!exist[p])
        {
            pos[cnt++]=p;
            exist[p]=1;
        }
    }
    int x,y;
    f(1,m)
    {
        cin>>x>>y;   
        link(x,y);
    }
    f(0,cnt-1)
    {       
        vis[pos[i]]=1;
        dfs(pos[i]);
        memset(vis,0,sizeof(vis));
    }
    f(1,n)
    {
        if( pass[i]==cnt)
            ans++;
    }
    cout<<ans;
   

    return 0;
}