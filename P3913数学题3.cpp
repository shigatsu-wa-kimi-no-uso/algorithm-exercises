#include<iostream>
#include<algorithm>
using namespace std;

//P3913 车的攻击

int r[(int)1E6],c[(int)1E6];

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>r[i]>>c[i];
    }
    sort(r+1,r+k+1,less<int>());
    sort(c+1,c+k+1,less<int>());
    
    int *pc,*pr;
    pc=unique(c+1,c+k+1);
    pr=unique(r+1,r+k+1);
    unsigned long long sizc=pc-(c+1);
    unsigned long long sizr=pr-(r+1);
    cout<<sizc*n+sizr*n-sizr*sizc;
    return 0;
}