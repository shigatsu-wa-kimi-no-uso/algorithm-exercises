#include<iostream>
using namespace std;


//P2004领地选择

int sum[1005][1005];

int main()
{
    int n,m,c;
    cin>>n>>m>>c;
    int v;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>v;
            sum[i][j]=v+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    int x,y;
    int ans=0x80000000;
    for(int i=c;i<=n;i++)
    {
        for(int j=c;j<=n;j++)
        {
            if(ans<sum[i][j]-sum[i-c][j]-sum[i][j-c]+sum[i-c][j-c])
            {
                ans=sum[i][j]-sum[i-c][j]-sum[i][j-c]+sum[i-c][j-c];
                x=i-c+1;
                y=j-c+1;
            }
        }
    }
    cout<<x<<" "<<y;
    return 0;
}