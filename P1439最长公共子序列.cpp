#include<iostream>
using namespace std;

//P1439 最长公共子序列


int dp[2][100005];

//dp i j定义 a中前i个 b中前j个中最长公共子序列
//dp i j = dp i-1 j-1 


int a[100005];
int b[100005];

int n;




int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
       
    }
   /* for(int i=0;i<=n;i++)
    {
        cout<<i<<" ";
    }
    cout<<"\n";*/
    for(int i=1;i<=n;i++)
    {
        //cout<<i<<" ";
        for(int j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                dp[i%2][j]=max(dp[(i+1)%2][j-1]+1,dp[i%2][j]);
                
            }
            else
            {
                dp[i%2][j]=max(dp[(i+1)%2][j],dp[i%2][j-1]);
            }
            //cout<<dp[i][j]<<" ";
        }
      //  cout<<"\n";
    }
    cout<<dp[n%2][n];
    return 0;
}