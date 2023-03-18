#include<iostream>
using namespace std;

int n,m;


//P2249 二分查找

int a[1000006];




int bsearch(int x)
{
    int lb=1,ub=n;
    int mid;
    while(lb<ub)
    {
        mid=lb+(ub-lb)/2;//此种写法防止溢出
        if(a[mid]>=x)
        {
            ub=mid;
        }
        else 
        {
            lb=mid+1;
        }
    }
    if(a[lb]==x)
    {     
        return lb;   
    }
    
    return -1;
}





int main()
{
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int x;
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        cout<<bsearch(x)<<" ";
    }
    
    return 0;
}