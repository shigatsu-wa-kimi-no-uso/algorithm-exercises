#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define f(x,j) for(int i=x;i<=j;i++)
#define feach(x) for(int val :e[x])
using namespace std;


//P4017 最大食物链计数

const int mod=80112002;
int n,m;
vector<int> e[5010];
queue<int> q;
int ans;
int cnt;

struct NODE
{
    int w;
    int ind;
    int outd;
}v[5010];

int dp[5010];

void link(int x,int y)
{
    e[x].push_back(y);
    v[y].ind++;
    v[x].outd++;
}


void topobfs()
{
    int cur;
    while(!q.empty())
    {
        cur=q.front();
        feach(cur)
        {
            v[val].ind--;
            dp[val]=(dp[val]+dp[cur])%mod;
            if(v[val].ind==0)
                q.push(val);          
        }
        if(v[cur].outd==0)
        {
          //  cout<<i<<" ";
            ans=(ans+dp[cur])%mod;
        }
        q.pop();
    }
}




int main()
{
    cin>>n>>m;
    int x,y;
    f(1,m)
    {
        cin>>x>>y;    
        link(x,y);
    }
    
    f(1,n)
    {
        if(v[i].ind==0)
        {
            q.push(i);
            dp[i]=1;
            
        }
    }
    topobfs();
    
    
        
    
   // cout<<rt<<"\n";
    cout<<ans;
    return 0;
}