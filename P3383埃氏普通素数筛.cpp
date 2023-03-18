#include<iostream>
using namespace std;

//P3383 埃氏普通素数筛


int n,q;

bool flag[100000000];

int ranke[2000000];

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>q;
    int cnt=1;
    for(int i=2; i<=n/2; i++)
    {
        if(flag[i]==0)
        {
            ranke[cnt++]=i;
            for(int k=2; k*i<=n; k++)
            {
                flag[k*i]=1;
            }
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