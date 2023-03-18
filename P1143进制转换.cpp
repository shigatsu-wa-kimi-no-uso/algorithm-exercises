#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

//P1143进制转换

int sys,to;
string s,ans;

inline int cast10(char i,int pw)
{
    if('0'<=i and i<='9')
    {
        return (i-'0')*pow(sys,pw);
    }
    if('A'<=i and i<='F')
    {
        return (i-'A'+10)*pow(sys,pw);
    }
}

char casttoaim(int s10)
{
    if(s10<10)
    {
        return s10+'0';
    }
    if(s10>=10)
    {
        return s10%10+'A';
    }
}

int main()
{
    cin>>sys;
    cin>>s;
    int l=s.length();
    int i=0;
    int s10=0;
    do
    {
        s10+=cast10(s[l-1],i);    
      //  cout<<s10<<"\n";
    }while(i++,--l);
 //   cout<<s10<<"\n";
    cin>>to;
    do
    {
        ans.push_back(casttoaim(s10%to));
        s10/=to;
    }while(s10);
    reverse(ans.begin(),ans.end());
    cout<<ans;
    
    
    
    return 0;
}