#include<iostream>
#include<cstring>
using namespace std;


//P1719最大子矩阵和矩阵降维法&dp
int a[150][150];
int n;
int sum[150];
int segsum;
int ans;

void work(int r)
{
    for(int st=r; st<=n; st++)    //控制起始行
    {
        for(int k=1; k<=n; k++)
        {
            sum[k]+=a[st][k];    //矩阵压缩
        }
        
        for(int i=1; i<=n; i++)
        {
            segsum=max(sum[i],segsum+sum[i]);
            ans=max(ans,segsum);
        }
        segsum=0;
    }
}


int main()
{

    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        work(i);
        memset(sum,0,sizeof(sum));
    }

    cout<<ans;
    return 0;
}