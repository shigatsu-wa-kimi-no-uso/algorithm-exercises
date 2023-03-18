#include<iostream>
#include<queue>
using namespace std;

//P2032 单调队列应用

int a[5000005];

struct INFO
{
    int id;
    int val;
    INFO(){}
    INFO(int val,int id)
        :val(val),id(id){}
};


deque<INFO> q;

int n;
int k;

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=k;i++)
    {
        if(!q.empty() && q.front().id+k==i)
        {
            q.pop_front();
        }
        while(!q.empty() && a[i]>=q.back().val)    
        {
            q.pop_back();
        }
        q.push_back(INFO(a[i],i));
    }
    cout<<q.front().val<<"\n";
    for(int i=k+1;i<=n;i++)
    { 
        if(!q.empty() && q.front().id+k==i)
        {
            q.pop_front();
        }
        while(!q.empty() && a[i]>=q.back().val)    
        {
            q.pop_back();
        }
        q.push_back(INFO(a[i],i));
      
        cout<<q.front().val<<"\n";
    }
    
    return 0;
}