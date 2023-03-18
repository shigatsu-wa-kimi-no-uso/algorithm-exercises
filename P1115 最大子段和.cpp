#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

//P1115 最大子段和

int n;

int a[200005];
long long sums[200005];
long long delta[200005];

int main()
{
    cin>>n;
    long long mins=0;    //初始最小前缀和为0
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sums[i]=a[i]+sums[i-1];    
        mins=min(mins,sums[i-1]);
        delta[i]=sums[i]-mins;
    }
    sort(delta+1,delta+n+1,less<int>());
    cout<<delta[n];
    
    
    return 0;
}