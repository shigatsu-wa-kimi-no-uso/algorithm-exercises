#include<iostream>
#include<set>
using namespace std;


//P1102 A-B数对

int n,c;
multiset<int> s;

int main()
{
    int x;
    multiset<int>::iterator it,f;
    
    cin>>n>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        s.insert(x);
    }
    long long ans=0;
    int maxn=*(--s.end());
    int cnt=0;
    for(it=s.begin();*it+c<=maxn; )
    {
        if((f=s.find(*it+c))!=s.end())
        {
            cnt=s.count(*it);
            ans+=s.count(*it)*s.count(*f);
            it=s.upper_bound(*it);
        }
        else
        {
            it=s.upper_bound(*it);
        }
    }
    cout<<ans;
    return 0;
}