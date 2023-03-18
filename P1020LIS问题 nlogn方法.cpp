#include<iostream>
#include<algorithm>
using namespace std;

int a[100005];
int n;

int q1[100005],q2[100005];

//P1020LIS问题 nlogn做法

int main()
{
    
    while(cin>>a[++n]);// 读到EOF就退出
    n--;    //读EOF时多加了一次
    int len1=1,len2=1;
    q1[1]=a[1];
    
    for(int i=2;i<=n;i++)
    {
        if(a[i]<=q1[len1])
        {
            q1[++len1]=a[i];
        }
        else
        {
            int *p=upper_bound(q1+1,q1+len1+1,a[i],greater<int>());
            *p=a[i];
        }
    }
   
    q2[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]>q2[len2])
        {
            q2[++len2]=a[i];
        }
        else
        {
            int *p=lower_bound(q2+1,q2+len2+1,a[i],less<int>());
            *p=a[i];            
        }
    }
    cout<<len1<<"\n"<<len2;
    
    
    return 0;
}