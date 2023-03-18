#include<iostream>
#define f(i,j,k) for(int i=j;i<=k;i++)
using namespace std;


//P1616 疯狂的采药

int w[10010];
int t[10010];

long long dp[2][(int)1E7+5];
int T,m;



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
                if(i%2)
                    dp[1][j]=max(dp[0][j],dp[1][j-t[i]]+w[i]);
                else
                {
                    dp[0][j]=max(dp[1][j],dp[0][j-t[i]]+w[i]);
                }
            }
            else
            {
                if(i%2)
                {
                    dp[1][j]=dp[0][j];
                }
                else
                {
                    dp[0][j]=dp[1][j];
                }
            }    
        }
           
    }
    if(m%2)
        cout<<dp[1][T];
    else
        cout<<dp[0][T];
    return 0;
}