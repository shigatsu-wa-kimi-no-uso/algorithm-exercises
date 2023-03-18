#include<iostream>
#define f(i,k,j) for(int i=k;i<=j;i++)

using namespace std;


//P1802
long long dp[1005][1005];

int n,x;

int l[1005];
int w[1005];
int c[1005];

int main()
{
    cin>>n>>x;
    f(i,1,n)
    {
        cin>>l[i]>>w[i]>>c[i];
    }
    
    f(i,1,n)
    {
        f(j,0,x)
        {
            if(j>=c[i])
            {
                dp[i][j]=max(dp[i-1][j]+l[i],dp[i-1][j-c[i]]+w[i]);
            }
            else
            {               
                dp[i][j]=dp[i-1][j]+l[i];
            }
        }
    }
    cout<<dp[n][x]*5;
    
    
    return 0;
}