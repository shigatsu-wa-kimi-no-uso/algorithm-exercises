#include<iostream>
using namespace std;

//P1095 守望者的逃离


int m,s,T;

int s1,s2,t=1;



int main()
{
    cin>>m>>s>>T;
    
    do
    {
        s1+=17;
        if(m>=10)
        {
            s2+=60; 
            m-=10;            
        }
        else
            m+=4;
        if(s2>s1) s1=s2;
        
        if(s1>=s)
        {
            cout<<"Yes\n"<<t;
            return 0;
        }                 
        t++;
    }
    while(t<=T);
    cout<<"No\n"<<s1;
    
    return 0;
}