#include<iostream>
#include<queue>
#include<vector>
#define f(s,r) for(int i=s;i<=r;i++)
#define feach(x) for(EDGE val : e[x])
using namespace std;


//P1807最长路径拓扑排序法
int n,m;
long long dp[1550];
bool flag;

struct EDGE
{
    int to;
    long long w;
};

queue<int> q;
vector<EDGE> e[1550];

struct NODE
{
    int ind;
    int outd;
}v[1550];


inline void link(int x,int y,int w)
{
    EDGE tmp={y,w};
    e[x].push_back(tmp);   
    v[y].ind++;
    v[x].outd++;    
}

void wasteindegree()
{
    int cur;
    while(!q.empty())
    {
        cur=q.front();
        feach(cur)
        {
            v[val.to].ind--;
            if(v[val.to].ind==0)
                q.push(val.to);            
        }
        q.pop();
    }
}


void topo()
{
    int cur;
    while(!q.empty())
    {
        cur=q.front();
        feach(cur)
        {
            v[val.to].ind--;
            dp[val.to]=max(dp[cur]+val.w,dp[val.to]);
            if(v[val.to].ind==0)
                q.push(val.to);            
        }
        q.pop();
        if(cur==n)
            flag=1;
    }
}


int main()
{
    cin>>n>>m;
    int x,y,w;
    f(1,m)
    {
        cin>>x>>y>>w;
        link(x,y,w);
    }
    
    f(2,n)
    {
        if(v[i].ind==0)
            q.push(i);
    }
    wasteindegree();    
    //在从1拓扑前 把其他可能的零入度点先遍历 
    //防止由于没有被遍历导致的入度无法为0的问题
    q.push(1);
    topo();    
    if(flag)
        cout<<dp[n];
    else
        cout<<-1;
    
    return 0;
}