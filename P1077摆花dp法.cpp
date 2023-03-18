#include<iostream>
using namespace std;

const int mod=1E6+7;

//P1077 摆花 dp法

int a[105];

int dp[105][105];

int m,n;

//dp[i][j]为 固定在前i种花中选择j种时的方案数
//

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }   
    
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    
    for(int i=1;i<=n;i++)    //
    {
        for(int j=1;j<=m;j++)
        {    
            for(int k=0;k<=min(j,a[i]);k++)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j-k])%mod;
            }
        }
    }
    
    
    cout<<dp[n][m];
   
    return 0;
}