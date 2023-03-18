#include<iostream>
#include<algorithm>
using namespace std;

//P1866

int mod=1000000007;
int a[70];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,less<int>());
    unsigned long long ans=a[1]%mod;
    for(int i=2;i<=n;i++)
    {
        ans=ans*(a[i]-i+1)%mod;
        
    }
    cout<<ans;
    return 0;
}