#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

//P1678简单题

int s[1000005];

int c[1000005];

int m,n;

int main()
{
    cin>>m>>n;

    for(int i=1; i<=m; i++)
    {
        cin>>c[i];
    }

    for(int i=1; i<=n; i++)
    {
        cin>>s[i];
    }

    sort(c+1,c+m+1,less<int>());

    sort(s+1,s+n+1,less<int>());
    c[0]=INT_MAX;
    c[m+1]=INT_MAX;
    long long ans=0;
    int j=1;
    for(int i=1; i<=n; i++)
    {
        for(; j<=m; j++)
        {
            if(c[j]>s[i])
            {
            //    cout<<c[j]<<" "<<s[i]<<"\n";
                ans+=min(abs(s[i]-c[j]),abs(s[i]-c[j-1]));
                break;
            }
        }
        if(j>m)
            ans+=abs(s[i]-c[m]);
    }
    cout<<ans;
    return 0;
}