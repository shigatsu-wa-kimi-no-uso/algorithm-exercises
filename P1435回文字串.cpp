#include<iostream>
#include<cstring>
using namespace std;

//P1435 回文字串

char s[1005],r[1005];

int d[1005][1005];

int main()
{
    cin>>(s+1);
    s[0]=1;
    int l=strlen(s);
    for(int i=1;i<l;i++)
    {
        r[l-i]=s[i];
    }
    
  //  cout<<"\n";
 //   cout<<r+1<<"\n";
    for(int i=1;i<l;i++)
    {
        for(int j=1;j<l;j++)
        {
            if(s[i]==r[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else 
                d[i][j]=max(d[i-1][j],d[i][j-1]);
         //   cout<<d[i][j]<<" ";
        } 
     //   cout<<"\n";   
    }
    cout<<l-1-d[l-1][l-1];
    return 0;
}