#include<iostream>
#include<string>
using namespace std;

string s;
//P1928字符串处理
//优化精简版

string read()
{
    string s;
    string t;
    char ch;
    int n;
    while(1)
    {
      //  cout<<"s\n";
        ch=getchar();
        if(ch=='[')
        {          
            cin>>n;
            t=read();
            while(n--)
            {
                s+=t;
            }
        }
        else if(ch==']')
        {
            return s;
        }
        else if(ch=='\n' or ch==EOF or ch=='\r')
        {
            return s;
        }
        else
            s+=ch;       
    }
    
}


int main()
{
    s.reserve(20005);
    s=read();
    cout<<s;
    return 0;
}