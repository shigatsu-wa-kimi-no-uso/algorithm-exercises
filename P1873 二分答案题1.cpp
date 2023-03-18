#include<iostream>
#include<algorithm>
using namespace std;

//P1873 二分答案题1

int n,m;

long long a[10000006];


int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,less<int>());
   
   
    long long h=0;
    int l=0,r=a[n];
    int mid;
    while(l<=r)
    {
        mid=l+(r-l)/2;
      //  cout<<mid<<"mid\n";
        long long *v=lower_bound(a+1,a+n+1,mid);
        for(int i=v-a;i<=n;i++)
        {
            h+=a[i]-mid;
        }
        if(h<m) r=mid-1;
        else l=mid+1;
        h=0;
    }
    cout<<l-1;
    return 0;
}