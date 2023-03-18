#include<iostream>
using namespace std;

//P3397


int dif[1005][1005];
int sum[1005][1005];

int n,m;


int main()
{
    cin>>n>>m;
    int x1,y1,x2,y2;
    for(int i=1;i<=m;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        dif[x1][y1]++;
        dif[x2+1][y2+1]++;
        dif[x1][y2+1]--;
        dif[x2+1][y1]--;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {            
            sum[i][j]=dif[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
            cout<<sum[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    
    return 0;
}