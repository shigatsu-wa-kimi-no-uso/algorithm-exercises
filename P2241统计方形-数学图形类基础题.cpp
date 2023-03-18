#include<iostream>
using namespace std;

int n,m;

//P2241统计方形


int main()
{
    cin>>n>>m;
    unsigned long long s1=0,s2=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i!=j)
                s1+=(m-j+1)*(n-i+1);
            else
            {
                s2+=(m-j+1)*(n-i+1);
            }          
        }           
    }
    cout<<s2<<" "<<s1;
    return 0;
}