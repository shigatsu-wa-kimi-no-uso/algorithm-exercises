#include<iostream>
#include<cmath>
using namespace std;

//P3383 埃氏普通素数筛优化版


int n,q;

bool flag[200000000];

int ranke[200000000];

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>q;
    int sq=sqrt(n);
    int cnt=1;
    for(int i=2; i<=sq; i++)    //n范围内 用根号n内的素数筛即可
    {
        if(flag[i]==0)
        {
            ranke[cnt++]=i;
            for(int k=i; k*i<=n; k++)    //优化 从i^2开始 2i和i^2之间的数一定被筛过
            {
                flag[k*i]=1;
            }
        }
    }
    for(int i=sq+1;i<=n;i++)
    {
        if(flag[i]==0)
        {
            ranke[cnt++]=i;
        }
    }
    int x;
    for(int i=1; i<=q; i++)
    {
        cin>>x;
        cout<<ranke[x]<<"\n";
    }

    return 0;
}