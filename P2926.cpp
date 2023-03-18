#include<iostream>
#include<algorithm>
using namespace std;


//P2926 

int n;

int d[1000005];    //标号索引

long long ans[1000005];

int f[1000005];    //去重排序后的数字

int cnt[1000005];    //数字计数

int maxn;

int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    int n2=0;
    for(int i=1; i<=n; i++)
    {
        cin>>d[i];
        cnt[d[i]]++;
        if(cnt[d[i]]==1)
        {       
            f[n2++]=d[i];    
            maxn=max(d[i],maxn);        
        }
    }
    
    sort(f,f+n2,less<int>());
    for(int i=0; i<n2; i++)
    {
        for(int mul=1;mul<=maxn/f[i];mul++)
        {
            if(cnt[f[i]*mul])
            {
                ans[f[i]*mul]+=cnt[f[i]];
            }        
        }                       
    }
    
    for(int i=1;i<=n;i++)
    {
        cout<<ans[d[i]]-1<<"\n";
    }

    return 0;
}