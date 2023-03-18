#include<iostream>
using namespace std;

//P2678 二分答案题3


int l,m,n;
int seg[50005];
int a[50005];



//2 11 14 17 21 25

int main()
{
    cin>>l>>n>>m;
    int i;
    int maxs=0;
    for( i=1; i<=n; i++)
    {
        cin>>a[i];
        seg[i]=a[i]-a[i-1];
        maxs=max(seg[i],maxs);
    }
    seg[i]=l-a[i-1];
    maxs=max(seg[i],maxs);
    long long mid,l=1,r=maxs;
    int cnt=0;
    long long len=0;
    while(l<=r)
    {
        mid=l+(r-l)/2;
     // cout<<mid<<"\n";
        for(int i=1; i<=n+1;i++)
        {
            if(len==0)
            {
                if(seg[i]<mid)
                {
                    len=seg[i];
               //     cout<<i<<" "<<seg[i]<<"\n";
                    cnt++;
                }
            }
            else 
            {
                len+=seg[i];
                if(len<mid)
                {
                    cnt++;                    
                  //  cout<<i<<" "<<seg[i]<<"\n";
                }
                else len=0;
            }
        }
     //   cout<<"c"<<cnt<<"\n";
        if(cnt>m)
        {
            r=mid-1;
        }
        else if(cnt<=m)
        {
            l=mid+1;
        }
        len=0;
        cnt=0;
    }
    cout<<l-1;
    return 0;
}