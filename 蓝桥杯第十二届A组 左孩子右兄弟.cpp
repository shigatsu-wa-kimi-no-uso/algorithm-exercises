#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//蓝桥杯第十二届A组 左孩子右兄弟

typedef vector<int> vec;

bool cmp(const int&,const int&);

vec node[100005];

int siz[100005];

bool cmp(const int &lft,const int &rgt)
{
    return siz[lft]>siz[rgt];
}    

int n;

int dfs(int fa)
{
    siz[fa]=1+node[fa].size();
 //   cout<<fa<<" s "<<siz[fa]<<"\n";
    int maxsz=0;
    for(int i=0;i<node[fa].size();i++)
    {
        maxsz=max(maxsz,dfs(node[fa][i]));    
       
    }
    if(maxsz!=0) maxsz-=1;
   // cout<<maxsz<<"\n";
   // cout<<fa<<"getmaxt"<<maxsz<<"\n";
    siz[fa]+=maxsz;
    return siz[fa];
}


int main()
{
    cin>>n;
    int t;
    for(int i=2;i<=n;i++)
    {
        cin>>t;
        node[t].push_back(i);  
    }
    cout<<dfs(1)-1;  
    /*cout<<"\n";
    for(int i=1;i<=n;i++)  
    {
        cout<<siz[i]<<" "<<node[i].size()<<"\n";      
    }*/
    
      
    return 0;
}