#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

//P1638逛画展

int a[1000006];

struct L
{
    int st,ed,l;
    bool operator<(const L &rgt) const
    {
        if(l==rgt.l)
        {
            return st<rgt.st;
        }
        return l<rgt.l;
    }

} l[1000006];

map<int,int> s;

int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    int j=1;
    int i;
    for( i=1; i<=n; i++)
    {
        for(; j<=n; j++)
        {
            if(s.size()==m)
            {
                l[i].st=i;
                l[i].ed=j-1;
                l[i].l=j-i;
                break;
            }
            s[a[j]]++;
        }
        if(j>n)
        {
            sort(l+1,l+i,less<L>());
            break;
        }
        s[a[i]]--;
        if(s[a[i]]==0 )
            s.erase(a[i]);
    }
    if(s.size()==m)
    {
        l[i].st=i;
        l[i].ed=j-1;
        l[i].l=j-i;
    }
    cout<<l[1].st<<" "<<l[1].ed;
    return 0;
}