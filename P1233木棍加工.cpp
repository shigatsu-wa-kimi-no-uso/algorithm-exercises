#include<iostream>
#include<algorithm>
using namespace std;
struct INFO
{
    int x,y;
    bool operator<(const INFO &right) const
    {
        if(x!=right.x)
        {
            return x<right.x;
        }
        if(y!=right.y)
        {
            return y<right.y;
        }
        return 0;
    }
    
    bool operator>(const INFO &right) const
    {
        if(x!=right.x)
        {
            return x>right.x;
        }
        
        if(y!=right.y)
        {
            return y>right.y;
        }
        return 0;
    }
}s[5005];

int n;

int d[5005];

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>s[i].x>>s[i].y;
    }
    sort(s+1,s+n+1,greater<INFO>());
    int len=1;
    d[1]=s[1].y;
 /* for(int i=1;i<=n;i++)
    {
        cout<<s[i].x<<" "<<s[i].y<<"\n";
    }  */
    for(int i=2; i<=n; i++)
    {
        //  cout<<d[len].x<<" "<<d[len].y<<" "<<s[i].x<<" "<<s[i].y<<"\n";
        if(d[len]<s[i].y)
        {
            d[++len]=s[i].y;
        }
        else
        {
            *lower_bound(d+1,d+len+1,s[i].y,less<int>())=s[i].y;
        }
    }

    cout<<len;
    return 0;
}