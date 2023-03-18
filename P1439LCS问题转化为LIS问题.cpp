#include<iostream>
#include<algorithm>
using namespace std;

//P1439 LCS问题 转换为LIS问题

int a[100005];
int b[100005];
int n;

int orda[100005];
int ordb[100005];

int q[100005];
int len;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        orda[a[i]]=i;        
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        ordb[i]=orda[b[i]];
        
    }
    
    q[1]=ordb[1];
    len=1;
    for(int i=2;i<=n;i++)
    {
        if(ordb[i]>q[len])
        {
            q[++len]=ordb[i];
        }
        else
        {
            int *p=upper_bound(q+1,q+len+1,ordb[i],less<int>());
            *p=ordb[i];
        }
    }
    cout<<len;
    
    
    return 0;
}