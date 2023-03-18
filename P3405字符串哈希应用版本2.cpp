#include<iostream>
using namespace std;


//P3405字符串哈希应用版本2

int base=27;

int hash1[200005];
int hash2[200005];

int city[709][709];


int gethash(string s)
{
    int val=0;
    for(int i=0;i<=1;i++)
    {
        val=val*base+(s[i]-'A');
    }
    return val;
}

int n;
string s1,s2;

int main()
{
    cin>>n;
    int v1,v2;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>s1>>s2; 
        v1=gethash(s1);
        v2=gethash(s2);
        if(v1==v2)
            continue;
        city[v1][v2]++;
  //      ans+=city[v2][v1];
        hash1[i]=v1;
        hash2[i]=v2;  
    }
    
    for(int i=1;i<=n;i++)
    {       
        ans+=city[hash2[i]][hash1[i]];                       
    }
    cout<<ans/2;
    
    return 0;
}