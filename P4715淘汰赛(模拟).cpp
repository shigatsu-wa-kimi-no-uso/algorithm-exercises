#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

//P4715 

struct A
{
    int id;
    int val;
    bool operator<(const A &right) const
    {
        return val<right.val;
    }
    bool operator>(const A &right) const
    {
        return val>right.val;
    }

} a[1024];



int main()
{
    int n;
    cin>>n;
    int id1=1,id2=pow(2,n)/2+1;
    for(int i=1; i<=pow(2,n)/2; i++)
    {
        cin>>a[i].val;
        a[i].id=i;
  //      cout<<a[i].id;
        if(a[id1]<a[i])
        {
            id1=i;
        }
    } 
    
    for(int i=pow(2,n)/2+1; i<=pow(2,n); i++)
    {
        cin>>a[i].val;
        a[i].id=i;
    //    cout<<a[i].id;
        if(a[id2]<a[i])
        {
            id2=i;
        }
    }
   
    if(a[id1]>a[id2])
    {
      //  cout<<id2<<"\n";
    //    cout<<a[5].id;
      //  cout<<a[id2].val<<"\n";
        cout<<a[id2].id;
    }
    else
    {
        cout<<a[id1].id;
    }



    return 0;
}