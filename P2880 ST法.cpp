#include<iostream>
#include<cmath>
using namespace std;


//P2880  ST法

int maxh[50050][50];
int minh[50050][50];



//maxh[i][j]  记录[i,i+2^j-1]上的最大值
//maxh[i][j]=max(maxh[i][j-1],maxh[i+2^(j-1)][j-1]

//1 2 4 8 16
//


int n,q;


int main()
{
    cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        cin>>maxh[i][0];
        minh[i][0]=maxh[i][0];
    }
    int d=log(n)/log(2)+1;
    for(int j=1; j<=d; j++)
    {
        for(int i=1; i<=n; i++)
        {
            int t=i+pow(2,j-1);
            if(t<=n)
            {
                maxh[i][j]=max(maxh[i][j-1],maxh[t][j-1]);
                minh[i][j]=min(minh[i][j-1],minh[t][j-1]);
            }                      
        }
    }
    int l,r;
    int dx;
    int m;
    for(int i=1;i<=q;i++)
    {
        cin>>l>>r;
        if(l==r) 
        {
            cout<<0<<"\n";
            continue;
        }
        m=log(r-l)/log(2);
        int t=pow(2,m);
        cout<<max(maxh[l][m],maxh[r-t+1][m])-min(minh[l][m],minh[r-t+1][m]);
        cout<<"\n";
    }       

    return 0;
}