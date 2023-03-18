#include<iostream>
using namespace std;

int a[500005];
int c[500005];
int n,m;
//P3368差分树状数组


inline int lowbit(int x)
{
    return x&(-x);
}

void update(int id,int v)    //把第id个元素值增加v
{
    for(int i=id; i<=n; i+=lowbit(i))
    {
        c[i]+=v;
    }
}

int getsum(int b)    //获得[1,b]上的和
{
    int sum=0;
    for(int i=b; i>0; i-=lowbit(i))
    {
        sum+=c[i];
    }
    return sum;
}



int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        update(i,a[i]-a[i-1]);
    }

    int x,y,op,k;
    for(int i=1; i<=m; i++)
    {
        cin>>op;
        switch(op)
        {
        case 1:
            cin>>x>>y>>k;
            update(x,k);
            update(y+1,-k);
            break;
        case 2:
            cin>>x;
            cout<<getsum(x)<<"\n";
         
        }
    }


    return 0;
}