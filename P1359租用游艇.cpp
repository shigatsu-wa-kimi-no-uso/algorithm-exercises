#include<iostream>
using namespace std;


//P1359 租用游艇

int dis[205][205];

int dp[205][205];

int n;

int main()
{
    cin>>n;
  
    for(int i=1;i<n;i++)
    {   
        for(int j=1;j<i;j++) dis[i][j]=0x3f3f3f3f;
        for(int j=i+1;j<=n;j++)
        {
            cin>>dis[i][j];
        }
    }
    
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i==k || dis[i][k]>=0x3f3f3f3f) continue;
            
            for(int j=1;j<=n;j++)
            {
             
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    
    cout<<dis[1][n];
    
    return 0;
}