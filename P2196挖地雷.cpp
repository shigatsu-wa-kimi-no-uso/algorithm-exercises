#include<iostream>
#include<vector>
#include<queue>
#define f(i,x,y) for(int i=x;i<=y;i++)
using namespace std;


//P2196 挖地雷

vector<int> e[25];
queue<int> q;
int ind[25];
int w[25];
int dp[25];

int from[25];
int endp;

int n;

int topo()
{
    int now;
    int ans=0;
    while(!q.empty())
    {
        now=q.front();
        for(int v : e[now])
        {
            ind[v]--;
            if(dp[v]<dp[now]+w[v])
            {
                dp[v]=dp[now]+w[v];
                from[v]=now;    //记录是从now走到v的
            }
            if(ind[v]==0)
            {
                q.push(v);
            }
        }
        if(ans<dp[now])
        {
            ans=dp[now];
            endp=now;    //记录最后到的点是now        
        }
        q.pop();
    }
    return ans;
}


void printpath(int pos)
{
    if(from[pos])
        printpath(from[pos]);
    cout<<pos<<" ";
}

int main()
{
    cin>>n;
    f(i,1,n)
    {
        cin>>w[i];
    }
    int x;
    f(i,1,n-1)
    {
        f(j,i+1,n)
        {
            cin>>x;
            if(x!=0)
            {
                e[i].push_back(j);
                ind[j]++;
            }
        }
    }
    f(i,1,n)
    {
        if(ind[i]==0)
        {
            dp[i]=w[i];
            q.push(i);
        }
    }
    int ans=topo();
    printpath(endp);
    cout<<"\n";
    cout<<ans;
    
    return 0;
}