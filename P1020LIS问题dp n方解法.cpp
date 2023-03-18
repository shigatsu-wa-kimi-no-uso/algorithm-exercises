#include<iostream>
using namespace std;

int a[100005];
int n;

int dp[100005];

int dp2[100005];

int main()
{
    
    while(cin>>a[++n]);// 读到EOF就退出
    n--;    //读EOF时多加了一次
    int mx1=0,mx2=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=1;
        for(int j=1;j<i;j++)
        {
            if(a[j]>=a[i] && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
                
            }
        }
        mx1=max(dp[i],mx1);
    }
    
    for(int i=1;i<=n;i++)
    {
        dp2[i]=1;
        for(int j=1;j<i;j++)
        {
            if(a[j]<a[i] && dp2[i]<dp2[j]+1)
            {
                dp2[i]=dp2[j]+1;                
            }
        }
        mx2=max(dp2[i],mx2);
    }
    cout<<mx1<<"\n"<<mx2;
    
    
    return 0;
}