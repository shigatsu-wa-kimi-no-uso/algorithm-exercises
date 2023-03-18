#include<iostream>
#include<bitset>
using namespace std;

//P1441 砝码称重2

int w[21];

int t,l;
int n,m;


bitset<10001> b;
int ans;

bool del[25];
void dp();


void dfs(int now,int ndel)
{
    if(ndel)
    {
        for(int i=now; i<=n; i++)
        {
            del[i]=1;
            dfs(i+1,ndel-1);
            del[i]=0;
        }
    }
    else
    {
        dp();
    }
}

void dp()
{
    b[0]=1;
    for(int i=1; i<=n; i++)
    {
        if(del[i]) continue;
        b|=b<<w[i];
    }
    int c=b.count()-1;
    ans=max(ans,c);
    b.reset();
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>w[i];
    }
    dfs(1,m);
    cout<<ans;

    return 0;
}