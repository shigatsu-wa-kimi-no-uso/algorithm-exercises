#include<iostream>
#include<algorithm>
using namespace std;


//P1091合唱队形
int a[300];

int t;

int dp[300];


int asc[300];    //asc[i]表示前i个中LIS最长长度
int desc[300];


int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a[i];
    }
    int len=1;
    dp[1]=a[1];
    asc[1]=1;
    for(int i=2;i<=t;i++)
    {
        if(a[i]>dp[len])
        {
            dp[++len]=a[i];
        }
        else
        {
            *lower_bound(dp+1,dp+len+1,a[i],less<int>())=a[i];
        }
        asc[i]=len;  
          
    }
    len=1;
    dp[1]=a[t];
    desc[t]=1;
    for(int i=t-1;i>0;i--)
    {
        if(a[i]>dp[len])
        {
            dp[++len]=a[i];
        }
        else
        {
            *lower_bound(dp+1,dp+len+1,a[i],less<int>())=a[i];
        }
        desc[i]=len;
    }    
    int num=0;
    for(int i=0;i<=t;i++)
    {
        num=max(num,asc[i]+desc[i+1]);
    }
    cout<<t-num;
    return 0;
}