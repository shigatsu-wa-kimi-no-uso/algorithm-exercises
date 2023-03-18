#include<iostream>
using namespace std;

//P3817  贪心简单题
int a[100009];


int main()
{
    ios::sync_with_stdio(false);
    int n,x;
    unsigned long long ans=0;
    cin>>n>>x;
    int d;
    cin>>a[1];
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]+a[i-1]>x)
        {
            d=a[i]+a[i-1]-x;
            ans+=d;
            if(a[i]>=d)
            {
                a[i]-=d;
            }
            else
            {
                a[i]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}