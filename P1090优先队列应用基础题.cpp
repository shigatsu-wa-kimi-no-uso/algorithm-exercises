#include<iostream>
#include<queue>
using namespace std;
//P1090 优先队列应用

priority_queue<int,vector<int>,greater<int>> q;

int n;
int heap;
int sum;

int main()
{
    cin>>n;
    int t;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        q.push(t);
    }
    int cnt=0;
    while(q.size()!=1)
    {
        heap=q.top();
        q.pop();
        heap+=q.top();
        q.pop();
        q.push(heap);
        
        sum+=heap; 
    }
    cout<<sum;
    
    
    return 0;
}