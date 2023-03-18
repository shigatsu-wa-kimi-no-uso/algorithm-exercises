#include<iostream>
#include<cmath>
using namespace std;

//P3383 欧拉筛


int n,q;

bool flag[200000000];

int prime[200000000];

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>q;
    int cnt=1;
    for(int i=2; i<=n; i++)    //n范围内 用根号n内的素数筛即可
    {
        if(flag[i]==0)
        {
            prime[cnt++]=i;
        }

        for(int k=1; k<cnt && i*prime[k]<=n; k++)    //优化 从i^2开始 2i和i^2之间的数一定被筛过
        {
            flag[prime[k]*i]=1;
            if(i%prime[k]==0)
                break;
            //i能整除素数表中的一个数(假设为x)
            //意味着i=k倍x  而当前素数表中的下一个素数(假设为y)
            //有i*y=kx*y 意味着合数i*y有一个更小的质因数x
            //且ky*x能把它筛去 x<y 所以ky>kx=i ky将在未来取到
            //所以现在还不需要筛去这个数 当前情况下后续的数同理 直接跳出
        }
    }
    int x;
    for(int i=1; i<=q; i++)
    {
        cin>>x;
        cout<<prime[x]<<"\n";
    }

    return 0;
}