#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

//P1536 村村通

int n,m;

int fa[1005];

int getfa(int x)
{
    if(fa[x]==x)
    {
        return x;    
    }
    else
    {
        return fa[x]=getfa(fa[x]);    //赋值给对应节点父亲 优化后续查询
    }    
}

void merge(int x,int y)
{
    fa[getfa(y)]=getfa(x);
}


bool favis[1005];

int getfacnt()
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int f=getfa(i);
        if(favis[f]==0)
        {
            cnt++;
            favis[f]=1;          
        }
    }
    memset(favis,0,sizeof(favis));
    return cnt-1;
}


int main()
{
    int x,y;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        cin>>m;
        for(int i=1;i<=n;i++)    
        {
            fa[i]=i;
        }
                   
        for(int i=1;i<=m;i++)
        {
            cin>>x>>y;
            merge(x,y);
        }    
        cout<<getfacnt()<<"\n";
    }
    
    return 0;
}