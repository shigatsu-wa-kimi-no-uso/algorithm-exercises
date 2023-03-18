#include<iostream>
#define MAXN (int)1E9+10
using namespace std;

//P1469 

//异或运算性质
//a^a=0 a^a^a=1
//a^b=b^a
//a^b^a=b

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int t;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        ans^=t;
    }
    
    cout<<ans;
    return 0;
}