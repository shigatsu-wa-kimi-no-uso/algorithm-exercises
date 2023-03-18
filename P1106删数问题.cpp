#include<iostream>
#include<cstring>
using namespace std;
string s;
int zpos=777;


//P1106 删数问题
int k;
int main()
{
    cin>>s;   
    cin>>k;
    int n=s.length();
    
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            zpos=i;
            break;
        }
    }
   // cout<<"ok\n";
    if(zpos!=777 and zpos<=k)
    {
        while(s[0]!='0')
        {
  //          cout<<"erase "<<s[0]<<" ";
            s.erase(0,1);           
        }
        k-=zpos;
        while(s[0]=='0')
        {          
 //          cout<<"erase "<<s[0]<<" ";
            s.erase(0,1);
        }       
    }
    //    cout<<"ok\n";
    int i=0;
    bool flag=0;
    int l;
    while(k && !s.empty())
    {
 //       getchar();
        l=s.length();
        if(i==l-1)
        {
            if(flag)
                break;
            flag=1;
            i=0;
        }
        if(s[i]>s[i+1] )
        {
 //    cout<<"erase "<<s[i]<<" ";
            flag=0;
            s.erase(i,1);          
            k--;
            i=0;
        }
        else   
        {
            i++;
  //     cout<<i<<"i++\n";
        }

    }
    while(k && !s.empty())
    {
 //       getchar();
        l=s.length();
        if(i==l-1)
        {
            if(flag)
                break;
            flag=1;
            i=0;
        }
        if(s[i]>=s[i+1] )
        {
 //    cout<<"erase "<<s[i]<<" ";
            flag=0;
            s.erase(i,1);          
            k--;
            i=0;
        }
        else   
        {
            i++;
  //     cout<<i<<"i++\n";
        }

    }
    while(k && !s.empty())
    {
        s.erase(--s.end());
        k--;
    
    }
//   cout<<"break\n";
 //   int cnt=0;
   
   
    while(s[0]=='0')
    {
        s.erase(0,1);
    } 
    if(s.empty())  cout<<0;
    cout<<s;
    
    return 0;
}