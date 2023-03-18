#include<iostream>
using namespace std;

//P2440 二分答案题1

int a[100005];

long long b;

int n,k;
int ml;

int main()
{
    cin>>n>>k;
    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ml=max(a[i],ml);
    }
    
    long long l=0,r=ml,mid;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(mid==0)
        {
            break;
        }
        b=0;
        for(int i=1;i<=n;i++)
        {
            b+=a[i]/mid;
        }
     //   getchar();
     //   cout<<l<<"l "<<r<<"r\n";
      //  cout<<b<<" "<<mid<<"\n";
        if(b>k)
        {
            l=mid+1;
        }
        else if(b<k)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    if(l==0) cout<<0;
    else cout<<l-1;
    
    return 0;
}