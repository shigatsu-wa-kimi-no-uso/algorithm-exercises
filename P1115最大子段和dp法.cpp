#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

//P1115 最大子段和dp法

int n;

long long a[200005];

int main()
{
    cin>>n;
    long long segsum=0;    //初始最小前缀和为0
    long long ans=LLONG_MIN;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        segsum=max(a[i],segsum+a[i]);
        ans=max(ans,segsum);
    }
   //如果前面的和加上此数 比此数还小 就舍弃前面的保留此数
    //否则继续累加
    cout<<ans;
    
    
    return 0;
}