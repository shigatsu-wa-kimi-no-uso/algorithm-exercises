#include<iostream>
using namespace std;

//P1100 高低位转换 
int main()
{
    int n;
    cin>>n;
    int hbit=n&0xffff0000;
    int lbit=n&0x0000ffff;
    unsigned int ans=(hbit>>16)+(lbit<<16); //hbit>>16|lbit<<16
    cout<<ans;
    
    
    return 0;
}