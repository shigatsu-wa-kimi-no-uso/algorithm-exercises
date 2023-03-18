#include<iostream>
using namespace std;

int n,k;
int a[10000009];

struct MAXA
{
    int v;
    int st;
    int end;
}maxn[10000009];

int main()
{
    cin>>n>>k;
    
    long long ans=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(maxn[cnt].v<a[i])
        {
            maxn[cnt].end=i;
            cnt++;
            maxn[cnt].v=a[i];
            maxn[cnt].st=i;
        }
    }
    maxn[cnt+1].v=k;
    for(int i=0;i<=cnt;i++)
    {
        ans+=maxn[i].st*(maxn[i+1].v-maxn[i].v);
    }
    cout<<ans;
    return 0;
}