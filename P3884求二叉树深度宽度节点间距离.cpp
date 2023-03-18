#include<iostream>
using namespace std;

//P3884 求二叉树深度 宽度 节点间距离

struct A
{
    int ls;
    int rs;
}n[110];

int depth[110];
int width[110];

int m;
int u,v;

int updpt=0x7fffffff;
bool flag=0;

void dfs(int x,int fa)
{
    depth[x]=depth[fa]+1;
    width[depth[x]]++;
    
    if(x==u or x==v)
    {
        if(flag)
        {
            updpt=min(updpt,depth[x]);
            flag=0;    //开始记录期间内的最浅深度 即lca深度
        }
        else 
            flag=1;
    }   
     
    if(flag)
    {
        updpt=min(updpt,depth[x]);
    }
    
    if(n[x].ls)
    {
        dfs(n[x].ls,x);
    }   
      
    if(flag)
    {
        updpt=min(updpt,depth[x]);
    }
    
    if(n[x].rs)
    {
        dfs(n[x].rs,x);
    }
}



int main()
{
    cin>>m;
    int x,y;
    for(int i=1;i<m;i++)
    {
        cin>>x>>y;
        if(n[x].ls==0)
        {
            n[x].ls=y;
        }
        else if(n[x].rs==0)
        {
            n[x].rs=y;
        }        
    }
    cin>>u>>v;
    dfs(1,0);
    int dpt=0;
    for(int i=1;i<m;i++)
    {
        dpt=max(dpt,depth[i]);
    }
    int wid=0;
    for(int i=0;i<=dpt;i++)
    {
        wid=max(wid,width[i]);
    }
    cout<<dpt<<"\n"<<wid<<"\n";
//    cout<<updpt<<"\n";
    cout<<(depth[u]-updpt)*2+depth[v]-updpt;
    
    
    
    return 0;
}