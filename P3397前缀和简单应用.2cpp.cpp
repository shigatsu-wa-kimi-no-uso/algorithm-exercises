#include<iostream>
using namespace std;

//P3397


int dif[1005][1005];

int n,m;


int main()
{
    cin>>n>>m;
    int x1,y1,x2,y2;
    for(int i=1;i<=m;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        for(int j=x1;j<=x2;j++)
        {
            dif[j][y1]++;
            dif[j][y2+1]--;
        }  
    }
    int pre;
    for(int i=1;i<=n;i++)
    {
        pre=0;
        for(int j=1;j<=n;j++)
        {
            cout<<pre+dif[i][j]<<" ";
            pre+=dif[i][j];
        }
        cout<<"\n";
    }
    
    
    return 0;
}