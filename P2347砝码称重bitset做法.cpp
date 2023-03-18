#include<iostream>
#include<bitset>
using namespace std;

//P2347砝码称重bitset法

int w[7]={0,1,2,3,5,10,20};

int cnt[7];

bitset<1001> b;


int main()
{
    for(int i=1;i<=6;i++)
    {
        cin>>cnt[i];
    }
    b[0]=1;
    for(int i=1;i<=6;i++)
    {
        for(int j=1;j<=cnt[i];j++)
        {
            b|=b<<w[i];
        }
    }
    cout<<"Total="<<b.count()-1;
    return 0;
}