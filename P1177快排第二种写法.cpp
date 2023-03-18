#include<iostream>
#include<algorithm>
using namespace std;


//P1177 快速排序第二种写法

int a[100005];


void quicksort(int l,int r)
{
    int i=l;
    int j=r;
    int mid=a[l+(r-l)/2];
    do
    {
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;
        if(i<=j)
        {
            swap(a[i],a[j]);   
            i++;
            j--;   
        }      
    }
    while(i<=j);
   
    if(l<j)
        quicksort(l,j);
    if(r>i)
        quicksort(i,r);
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    quicksort(1,n);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
          
    return 0;
}