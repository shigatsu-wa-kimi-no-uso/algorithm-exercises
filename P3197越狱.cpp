#include<iostream>
using namespace std;

const long long mod=100003;

long long qmodpow(long long base,long long n)
{
    long long ans=1;
    while(n)
    {
        if(n&1)
        {
            ans=(ans*base)%mod;
        }
        base=(base*base)%mod;
        n>>=1;
    }
    return ans%mod;
}


int main()
{
    long long n,m;
    cin>>m>>n;
    cout<<(qmodpow(m,n)-(m%mod)*qmodpow(m-1,n-1)%mod+mod)%mod;        
    return 0;
}