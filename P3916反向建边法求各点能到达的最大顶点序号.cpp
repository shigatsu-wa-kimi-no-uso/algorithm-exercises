#include<iostream>
#include<vector>
using namespace std;

//P3916
//反向建边法求每个点能到达的最大节点序号
//即每个序号能够到达哪些点
//由于从大到小遍历 访问过则不再访问 访问过得点说明有比当前点大的点能够达到该点

int N,M;
vector<int> e[100005];
bool vis[100005];

int maxv[100005];
struct NODE
{
    int w;
}n[100000];

inline void link(int x,int y,int w)
{
    e[x].push_back(y);
    n[x].w=w;
}

void dfs(int x,int start)
{
    maxv[x]=start;
 //   cout<<x<<" "<<maxv[x]<<"\n";
    vis[x]=1;
    for(int val : e[x])
    {   
        if(!vis[val])
            dfs(val,start);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin>>N>>M;
    int x,y;
    int i;
    for(i=1;i<=M;i++)
    {
        cin>>x>>y;
        link(y,x,i);    //反向建边
    }
    for(i=N;i>0;i--)
    {
        if(!vis[i])
            dfs(i,i);    
    }
    for(i=1;i<=N;i++)
    {
        cout<<maxv[i]<<" ";
    }
    return 0;
}