#include<iostream>
using namespace std;

int q;

//P1364
//二叉树重心类问题(最短路径和等)

struct NODE
{
    int ls;
    int rs;
    int w;
    int wsize;
    int depth;
}n[120];

int f[120];

int bfsinit(int x,int fa)
{
    
    n[x].depth=n[fa].depth+1;
    n[x].wsize=n[x].w;
    if(n[x].ls)
    {       
        n[x].wsize+=bfsinit(n[x].ls,x);
    }
    if(n[x].rs)
    {
        n[x].wsize+=bfsinit(n[x].rs,x);
    }    
  //  cout<<"node "<<x<<" size "<<n[x].wsize<<" "<<n[x].depth<<"\n";
    return n[x].wsize;
}

int bfsgetsum(int x)
{
    int len=n[x].w*n[x].depth;
    if(n[x].ls)
    {
        len+=bfsgetsum(n[x].ls);
    }
    if(n[x].rs)
    {
        len+=bfsgetsum(n[x].rs);
    }
    return len;
}

void moveG(int x,int fa)
{
    f[x]=f[fa]-n[x].wsize+n[1].wsize-n[x].wsize;
  //  cout<<"f"<<x<<" "<<f[x]<<"\n";
    if(n[x].ls)
        moveG(n[x].ls,x);
    if(n[x].rs)
        moveG(n[x].rs,x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>n[i].w>>n[i].ls>>n[i].rs;
    }
    n[0].depth=-1;
    bfsinit(1,0);
    
    f[1]=bfsgetsum(1);  
    int ans=f[1];
    if(n[1].ls)
        moveG(n[1].ls,1);
    if(n[1].rs)
        moveG(n[1].rs,1);
    for(int i=2;i<=q;i++)
    {
        ans=min(ans,f[i]);
    }
    cout<<ans;
    return 0;
}