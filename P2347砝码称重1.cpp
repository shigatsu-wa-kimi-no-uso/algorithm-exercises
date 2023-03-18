#include<iostream>
using namespace std;


//P2347 砝码称重1

int w[7]={0,1,2,3,5,10,20};
int g[7];
bool s[1005];

int ans;

int main()
{
    for(int i=1; i<=6; i++)
    {
        cin>>g[i];
    }
    
    s[0]=1;
    
    for(int i=1;i<=6;i++)
    {
        for(int j=1;j<=g[i];j++)
        {
            for(int k=1000;k>=0;k--)
            {
                if(s[k])
                {
                    s[k+w[i]]=1;
                }
            }
        }
    }
    
    for(int i=1;i<=1000;i++)
    {
        if(s[i])
            ans++;
    }
    
    cout<<"Total="<<ans;

    return 0;
}