#include<iostream>
#define f(i,x,y) for(int i=x;i<=y;i++)
using namespace std;


//P1048 采药
//简单dp

int dp[105][1005];
int w[105];
int t[105];

int m,T;

int main()
{
    cin>>T>>m;
    f(i,1,m)
    {
        cin>>t[i]>>w[i];
    }
    f(i,1,m)
    {
        f(j,1,T)
        {
            if(j-t[i]>=0)
            {
                
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-t[i]]+w[i]);
            } 
            else
                dp[i][j]=dp[i-1][j];  
            
        }
        
    }
    cout<<dp[m][T];
    
    return 0;
}