#include<iostream>
using namespace std;

const int mod=1E6+7;

//P1077 摆花 记忆化搜索

int a[105];

int dp[105][105];

int m,n;

bool searched[105][105];    //标记已经搜索 因为用dp可能出现取模0的情况

int dfs(int id,int t)
{    
    if(searched[id][t])
        return dp[id][t];
    for(int j=0; j<=a[id]; j++)
    {       
        if(t-j>0)
        {
   //       cout<<"now "<<id<<" "<<j<<"\n";
            if(id+1<=n)
            {
                  
           //         int g=dfs(id+1,t-j);
               //   cout<<"+"<<g<<"\n";            
               dp[id][t]=(dp[id][t]+dfs(id+1,t-j))%mod;               
                
            }
        }
        else if(t-j==0)
        {           
        //   cout<<id<<" "<<j<<"over\n";
     //       cout<<id<<" "<<t<<" ret"<<dp[id][t]+1<<"\n"
            searched[id][t]=1;
            dp[id][t]=(dp[id][t]+1)%mod;      
            return dp[id][t];
        }
    }
    searched[id][t]=1;
 //   cout<<id<<" "<<t<<" "<<dp[id][t]<<"\n";
    return dp[id][t];

}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    
    
    cout<<dfs(1,m);
    //for(int i=1;i<=)
    return 0;
}