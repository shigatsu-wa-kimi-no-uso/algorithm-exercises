#include<iostream>
using namespace std;


//P1091合唱队形
int a[300];

int t;

int dp[300];    //dp[i]表示以a[i]结尾的LIS/LDS长度

int asc[300];    //asc[i]表示前i个中LIS最长长度
int desc[300];


int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a[i];
    }
    
    for(int i=1;i<=t;i++)
    {
        dp[i]=1;
        for(int j=1;j<i;j++)
        {          
            if(a[i]>a[j])
            {
                dp[i]=max(dp[j]+1,dp[i]);
            }
        } 
        asc[i]=max(asc[i-1],dp[i]);     
    }
    
    for(int i=t;i>0;i--)
    {
        dp[i]=1;
        for(int j=t;j>i;j--)
        {
            if(a[i]>a[j])
            {
                dp[i]=max(dp[j]+1,dp[i]);
            }
        }  
        desc[i]=max(desc[i-1],dp[i]);  
    }    
    int num=0;
    for(int i=0;i<=t;i++)
    {
        num=max(num,asc[i]+desc[i+1]);
    }
    cout<<t-num;
    return 0;
}