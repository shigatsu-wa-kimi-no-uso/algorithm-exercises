#include<iostream>
using namespace std;


//P1719最大子矩阵和
int a[150][150];
int sum[150][150];



int main()
{
    int n;
    cin>>n; 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }  
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum[i][j]=a[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
        }
    }
    
    int ans=0;    
    for(int k=1;k<=n;k++)
    {
        for(int l=1;l<=n;l++)
        {
            for(int i=0;i<k;i++)
            {
                for(int j=0;j<l;j++)
                {
                    ans=max(ans,sum[k][l]+sum[i][j]-sum[k][j]-sum[i][l]);
                }            
            }            
        } 
    }
    cout<<ans;
    return 0;
}