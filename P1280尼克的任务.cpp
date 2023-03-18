#include<iostream>
#include<vector>
using namespace std;

//P1280 尼克的任务

vector<int> t[100005];

int d[100005];


int n,k;

int main()
{
    cin>>n>>k;
    int x,y;
    for(int i=1; i<=k; i++)
    {
        cin>>x>>y;
        t[x].push_back(y);
    }

    for(int i=n; i>=0; i--)
    {
        if(!t[i].empty())
        {
            for(int v: t[i])
            {
                d[i]=max(d[i],d[i+v]);
            }
        }
        else
            d[i]=d[i+1]+1;
    }
    cout<<d[1];
    return 0;
}