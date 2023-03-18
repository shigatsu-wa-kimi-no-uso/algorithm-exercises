#include<iostream>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
using namespace std;

//P3371 最短路 dijkstra




struct EDGE
{
    int to;
    int len;
    EDGE() {}
    EDGE(int to,int len)
        :to(to),len(len) {}
};

struct NODE
{
    int lentos;
    int id;
    NODE() {}
    NODE(int id,int lentos)
        :lentos(lentos),id(id) {}
    bool operator<(const NODE &right) const
    {
        return lentos<right.lentos;
    }

    bool operator>(const NODE &right) const
    {
        return lentos>right.lentos;
    }
};


int ind[500005];
vector<EDGE> v[500005];     //v[i][x]记录从i到v[i][x].to的边的权值

priority_queue<NODE,vector<NODE>,greater<NODE>> q;
//特别记录从要求最短路源点s到其他点的边信息的小根堆

int dis[500005];
//dis[i]特别记录源点到i的长度信息

int n,m,s;

void link(int x,int y,int w)
{
    v[x].push_back(EDGE(y,w));
    ind[y]++;
}

/*
8 13 0
0 1 4
0 2 3
0 3 1
2 3 5
1 3 3
1 4 8
3 4 3
3 5 12
2 6 12
6 7 2
5 7 1
4 5 3
4 7 5*/
bool vis[500001];

void dijkstra()
{
    int now;
    int lentos;
    while(!q.empty())
    {
        now=q.top().id;    //当前的点
        q.pop();
        if(vis[now]) continue;
        vis[now]=1;
    //   cout<<"now:"<<now<<"\n";
      //  lentos=q.top().lentos;    //这个点到源点的长度
        for(int i=0; i<v[now].size(); i++)  //与这个点连接的有向边
        {
            int to=v[now][i].to;
         //   ind[to]--;
            int len=v[now][i].len;
            
          //  if(ind[to]==0)
            if(dis[now]+len<dis[to])
            {
                dis[to]=min(dis[now]+len,dis[to]);
                cout<<s<<" to "<<to<<" "<<dis[to]<<"\n";
                q.push(NODE(to,dis[to]));
            }
        }
        
    }
}

int main()
{
    int x,y,w;
    cin>>n>>m>>s;

    for(int i=1; i<=n; i++)
    {
        dis[i]=INF;
    }

    for(int i=1; i<=m; i++)
    {
        cin>>x>>y>>w;
        link(x,y,w);
    }
    dis[s]=0;
    q.push(NODE(s,0));

    dijkstra();

    for(int i=1; i<=n; i++)
    {
        if(dis[i]>=INF) cout<<0x7fffffff<<" ";
        else
            cout<<dis[i]<<" ";
    }

    return 0;
}