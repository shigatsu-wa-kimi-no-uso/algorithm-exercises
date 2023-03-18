#include<iostream>
#define f(x,y) for(int i=x;i<=y;i++)
using namespace std;

int fa[10050];
int n,m,p;


int getcap(int x)
{
    if(fa[x]==x)    //父亲等于自己
    {
        return x;    
    }
    else
    {
        return fa[x]=getcap(fa[x]);
    }
}

void merge(int x,int y)
{
    fa[getcap(y)]=getcap(x);
    //如果不设父亲等于自己 此处会出现赋值最后父亲为自己的情况
    //会导致后序getcap无限递归 
    //如果设没父亲始终为0 需修改此处代码逻辑 
}

int main()
{
    cin>>n>>m>>p;
    int x,y;
    
    f(1,n)
    {
        fa[i]=i;
    }
    f(1,m)
    {
        cin>>x>>y;
        merge(x,y);  
    }
    f(1,p)
    {
        cin>>x>>y;
        if(getcap(x)==getcap(y))
        {
            cout<<"Yes\n";
        }
        else
        {
            cout<<"No\n";
        }
     
    }
    
    return 0;
}