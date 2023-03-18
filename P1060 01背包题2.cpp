#include<iostream>
using namespace std;

//P1060 

int v[30],w[30];


int dp[30][30005];

int m,n;

int main()
{
    cin>>m>>n;
    
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j-v[i]>=0)
            {
                dp[i][j]=max(dp[i-1][j-v[i]]+v[i]*w[i],dp[i-1][j]);
            }
            else dp[i][j]=dp[i-1][j];
        }    
    }
    
    cout<<dp[n][m];
    return 0;
}
