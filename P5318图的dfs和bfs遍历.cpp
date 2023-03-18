#include<iostream>
#include<set>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m;
queue<int> q;

//P5318 图的dfs和bfs

vector<int> edge[100005];    //如果要向边添加权值，考虑使用struct作为vector变量

int cnt;
struct EDGE
{
    int w;            //边的权值
    int to;           //这条边的指向 
    int next;        //这条边的下一条邻边
}ed[1000006];



struct NODE
{
    int first;        //这个节点的第一条边
    int w;            //点的权值
}v[100005];

bool vis[100005];

//vector连接法
void linkv(int x,int y)
{
    edge[x].push_back(y);    //顶点x有一条边指向y
}


//经典数组连接法
void link(int x,int y)
{
    ed[++cnt].to=y;
    ed[cnt].next=v[x].first;    //设这条边的邻边为当前节点的first边
    v[x].first=cnt;    //保持当前节点的first边为当前序号
}


/*
8 9
1 2 
1 4
2 6
1 3
2 5 
3 7 
4 7 
7 8 
4 8
*/


void dfs(int x)
{
    //TODO 访问此节点时要做的事
    cout<<v[x].w<<" ";
    vis[x]=1;
    for(int val : edge[x])
    {
        if(!vis[val])
        {
            dfs(val);  
        }
    }
}

void bfs(int x)
{
    q.push(x);
    int curr;
    vis[x]=1;    //易错点
    while(!q.empty())
    {
        curr=q.front();
        //TODO 访问此节点时要做的事
        cout<<v[curr].w<<" ";
        for(int val : edge[curr])
        {
            if(!vis[val])
            {
                q.push(val);
                vis[val]=1;
            }
        }
        q.pop();
    }
}



int main()
{
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        v[x].w=x;
        v[y].w=y;
        linkv(x,y);  
    }
    int dad=getfa(1);
    for(int i=1;i<=n;i++)
    {
        sort(edge[i].begin(),edge[i].end(),less<int>());
    }
    dfs(1);
    memset(vis,0,sizeof(vis));
    cout<<"\n";
    bfs(1);
    
    
    return 0;
}