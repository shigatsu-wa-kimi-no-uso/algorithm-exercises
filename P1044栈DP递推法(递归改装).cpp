#include<iostream>
using namespace std;

//P1044 栈
//dfs递归改装
//DP递推法

unsigned long long dp[25][25];

//dp[i][j]定义栈中有i个元素，且还有j个元素未进过栈的输出情况数
//由于状态(i,j)有pop操作使(i,j)->(i-1,j)
//和push操作(i,j)->(i+1,j-1)
//故dp[i][j]=dp[i-1][j]+dp[i+1][j-1]
//为方便，交换ij所代表的含义，于是上式变为
//dp[i][j]=dp[i][j-1]+dp[i-1][j+1](i为剩余数，j为栈内数量)
//剩余0时，情况数为1，边界dp值dp[0][x]=1
//栈空时，只有push情况，故需要使dp[x][0]=dp[x-1][1]

int main()
{
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        dp[0][i]=1;       
    }
    
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=dp[i-1][1];
        for(int j=1;j<=n;j++)
        {                    
            dp[i][j]=dp[i][j-1]+dp[i-1][j+1];
        }
    }
    cout<<dp[n][0];
    return 0;
}