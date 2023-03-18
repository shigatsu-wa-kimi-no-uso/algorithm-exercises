#include<iostream>
#include<algorithm>
using namespace std;

//P1803 线段覆盖典型问题

int n;
struct T
{
    int a;
    int b;
    bool operator<(const T &right) const
    {
        return b<right.b;
    }
}t[1000006];


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i].a>>t[i].b;
    }
    sort(t+1,t+n+1,less<T>());
    int bound=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(t[i].a>=bound)
        {
            ans++;
            bound=t[i].b;
        }
    }
    cout<<ans;
    
    
    return 0;
}