#include<iostream>
#include<cmath>
using namespace std;

//P3865 ST表标准模板

int n,m;
int maxn[1000000][25];
//maxn[i][j]
//为[i,i+2^j-1]上的最大值
//maxn[i][j]=max(maxn[i][j-1],maxn[i+2^(j-1)][j-1])

int pows[40];


int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>maxn[i][0];
    }
    int logn=log2(n);
    for(int i=0;i<=logn;i++)
    {
        pows[i]=pow(2,i);
    }
    for(int j=1;j<=logn;j++)
    {
        for(int i=1;i<=n-pows[j-1];i++)
        {
            int lft=i+pows[j-1];
            maxn[i][j]=max(maxn[i][j-1],maxn[lft][j-1]);     
        }       
    }
    
    int x,y,l;    
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        l=log2(y-x+1);    //易错
        int lft=y-pows[l]+1;
        if(lft<1) lft=1;
        printf("%d\n",max(maxn[x][l],maxn[lft][l]));
    }
    
    return 0;
}