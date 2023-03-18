#include<iostream>
using namespace std;


//P2574 XOR的艺术

char s[200005];
int n,m;
int op,x,y;

struct SEG
{
    int cnt;
    int len;
    char changed;
} seg[200005<<2];

inline int ls(int x)
{
    return x<<1;
}

inline int rs(int x)
{
    return x<<1|1;
}

inline void pushup(int p)
{
    seg[p].cnt=seg[ls(p)].cnt+seg[rs(p)].cnt;
    seg[p].len=seg[ls(p)].len+seg[rs(p)].len;

}

inline void pushdown(int p)
{
    int l=ls(p);
    int r=rs(p);
    seg[l].cnt=seg[l].len-seg[l].cnt;
    
    seg[l].changed^=1;

    seg[r].cnt=seg[r].len-seg[r].cnt;
    seg[r].changed^=1;
    seg[p].changed=0;
}

void build(int p,int l,int r)
{
    if(l==r)
    {
        if(s[l]=='1')
        {
            seg[p].cnt=1;
        }
        seg[p].len=1;
        //cout<<"l "<<l<<" r "<<r<<" "<<seg[p].cnt<<"\n";
        return ;
    }
    int mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    pushup(p);
    //  cout<<"l "<<l<<" r "<<r<<" "<<seg[p].cnt<<"\n";
}



void update(int p,int l,int r)
{

    if(x<=l && y>=r)
    {
        //  cout<<"l "<<l<<" r "<<r<<" state"<<(int)seg[p].state<<" to ";
        seg[p].cnt=seg[p].len-seg[p].cnt;
        seg[p].changed^=1;
        return;
    }
    if(seg[p].changed)
        pushdown(p);
    int mid=(l+r)>>1;
    if(x<=mid)
        update(ls(p),l,mid);
    if(y>mid)
        update(rs(p),mid+1,r);
    pushup(p);
//    cout<<"l "<<l<<" r "<<r<<" "<<seg[p].cnt<<"\n";
}

int query(int p,int l,int r)
{
    int ans=0;
    if(x<=l && y>=r)
    {
        return seg[p].cnt;
    }
    if(seg[p].changed)
        pushdown(p);
    int mid=(l+r)>>1;
    if(x<=mid)
        ans+=query(ls(p),l,mid);
    if(y>mid)
        ans+=query(rs(p),mid+1,r);
    return ans;
}

int main()
{
    cin>>n>>m;
    cin>>s+1;
    build(1,1,n);
    for(int i=1; i<=m; i++)
    {
        cin>>op>>x>>y;
        switch(op)
        {
        case 0:
            update(1,1,n);
            break;
        case 1:
            cout<<query(1,1,n)<<"\n";
        }
    }



    return 0;
}