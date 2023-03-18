#include<iostream>
using namespace std;

int n;

//P1028 记忆化简单题

unsigned long long a[1005];

unsigned long long dfs(int x)
{
    unsigned long long ans;
    if(a[x])
        return a[x];
    if(x/2>0)
    {
        a[x]+=x/2;
    }
       
    
    for(int i=1;i<=x/2;i++)
    {
        a[x]+=dfs(i);
    }
    return a[x];
}

int main()
{
    cin>>n;        
    
    
    cout<<dfs(n)+1;
    
    
    return 0;
}
