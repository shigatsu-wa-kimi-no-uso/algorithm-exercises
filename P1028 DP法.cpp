#include<iostream>
using namespace std;

int n;

//P1028 记忆化简单题

unsigned long long dp[1005];
unsigned long long sum[1005];

//dp[n]=n/2+sum[n/2];
//sum[n]=sum[n-1]+dp[n];

//dp[1]=0
//dp[2]=1
//dp[3]=1
//dp[4]=2+1=3
//dp[5]=2+1=3
//dp[6]=3+1=4



int main()
{
    cin>>n;  
    
    for(int i=1;i<=n;i++)
    {
        dp[i]=i/2+sum[i/2];
        sum[i]=sum[i-1]+dp[i];
    }
    
    cout<<dp[n]+1;
    return 0;
}
