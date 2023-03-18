#include<iostream>
using namespace std;

unsigned char cnt[(int)1E9+10];

int a[50000];
int n;



void countsort()
{
    int maxnum=a[1];
    for(int i=1;i<=n;i++)
    {
        cnt[a[i]]++;
        maxnum=max(maxnum,a[i]);
    }
    
    int pos=1;
    for(int i=0;i<=maxnum;i++)
    {
        
        for(int j=1;j<=cnt[i];j++)
        {
            a[pos++]=i;
        }
    }

}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
       cin>>a[i];
    }
    countsort();
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}