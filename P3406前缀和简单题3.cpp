#include<iostream>
using namespace std;


//P3406海底高铁

unsigned int p[100005];
unsigned int sums[100005];

int m,n;

struct SEG
{
    unsigned long long a;
    unsigned long long b;
    unsigned long long c;
}seg[100005];


int main()
{
    cin>>n>>m;
    int end;
    int st;
    cin>>st;
    for(int i=2;i<=m;i++)
    {
        cin>>end;
        if(end>st)        
        {
            p[st]++;
            p[end]--;
        }   
        else if(end<st)
        {
            p[end]++;
            p[st]--;
        }
        st=end;
    }
    unsigned long long ans=0;    
    for(int i=1;i<n;i++)
    {
        cin>>seg[i].a>>seg[i].b>>seg[i].c;
    }
    
    for(int i=1;i<n;i++)
    {
        
        sums[i]=sums[i-1]+p[i];
        ans+=min(sums[i]*seg[i].a,seg[i].c+sums[i]*seg[i].b);
     //   cout<<sums[i]<<" "<<min(sums[i]*seg[i].a,seg[i].b+sums[i]*seg[i].c)<<"\n";
        
    }
    cout<<ans;
    return 0;
}

