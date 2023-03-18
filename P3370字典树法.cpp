#include<iostream>
using namespace std;

//P3370 字典树法

int cnt=1;
int n;
int len;

string s;
struct DICT
{
    bool isword;
    int next[66];
}dict[5000000];

inline char atoid(char ch)
{
    if(ch>='a' && ch<='z')
    {
        return ch-'a'+11;
    }
    else if(ch>='A' && ch<='Z')
    {
        return ch-'A'+37;
    }
    else if(ch>='0' && ch<='9')
    {
        return ch-'0'+1;
    }
}

void build(int d,short pos)
{
 //   cout<<"word "<<s[pos]<<" id"<<d<<"\n";
    if(pos==len-1)
    {
        dict[d].isword=1;
   //     cout<<d<<" isword\n";
        return;
    }    
    char nextid=atoid(s[pos]);
    if(dict[d].next[nextid]==0) 
    {
        dict[d].next[nextid]=cnt++;
 //       cout<<"build "<<cnt-1<<"\n";
        build(dict[d].next[nextid],pos+1);
    }
    else
    {
//        cout<<"in "<<dict[d].next[nextid]<<"\n";
        build(dict[d].next[nextid],pos+1);
    }
}




int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        len=s.length();
        build(0,0);
    }
    int ans=0;
    for(int i=0;i<cnt;i++)
    {
        if(dict[i].isword)
        {
            ans++;
        }
    }
    
    cout<<ans;
    return 0;
}