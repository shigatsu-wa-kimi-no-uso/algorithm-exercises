#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//P1113杂务处理 bfs拓扑排序法

vector<int> e[10005];
queue<int> q;

int n;
int vis[10005];


struct NODE
{
    int ind;
    int t;
}v[10005];

inline void link(int x,int y)
{
    e[y].push_back(x);   // 创建从y指向x的边
    v[x].ind++;            //点x的入度+1
}

int dp[10005];


void bfstopo(int x)
{
    q.push(x);
    int curr;
    while(!q.empty())
    {
        curr=q.front();
        for(int val : e[curr])
        {    //curr指向val 在val没有被访问过时 dp[val]始终为v[val].t 
            //比较入度的时间，取最大值，保存作为val的时间值
            dp[val]=max(dp[val],dp[curr]+v[val].t);
            v[val].ind--;        //点val的入度减1
            if(v[val].ind==0)
                q.push(val);
        }
        q.pop();
    }
}


int main()
{
    cin>>n;
    int i,x,w,d;
    for(i=1;i<=n;i++)
    {
        cin>>x>>w;
        while(1)
        {
            cin>>d;
            if(!d)
                break;
            link(x,d);
        }
        dp[x]=w;
        v[x].t=w;       
    }
    bfstopo(1);
    int ans=0;
    for(i=1;i<=n;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}