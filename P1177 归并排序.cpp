#include<iostream>
using namespace std;

int n;
int a[100005];
int b[100005];
int pos;

//P1177 归并排序


int* Merge(int *pl,int *pr,int sizel,int sizer)
{
    int i,j;
    int pos=0;
    int *tmp=new int[sizel+sizer];
    for(i=0,j=0;i<sizel && j<sizer;)
    {
        if(pl[i]<pr[j])
        {
            tmp[pos++]=pl[i];  
    //        cout<<tmp[pos-1]<<" ";
            i++;      
        }
        else
        {
            tmp[pos++]=pr[j];
     //       cout<<tmp[pos-1]<<" ";
            j++;
        }
    }
    if(i==sizel)
    {
        for(;j<sizer;j++)
        {
            tmp[pos++]=pr[j];
    //        cout<<tmp[pos-1]<<" ";
        }
    }
    else if(j==sizer)
    {
        for(;i<sizel;i++)
        {
            tmp[pos++]=pl[i];
  //          cout<<tmp[pos-1]<<" ";
        }
    }
//    cout<<"\n";
    delete pl;
    delete pr;
    return tmp;  
}

int* MergeSort(int *a,int l,int r)
{
 //   cout<<l<<" "<<r<<"\n";
 //   getchar();
    int mid=(l+r)/2;
    int *pl;
    int *pr;
    if(r!=l)
    {
        pl=MergeSort(a,l,mid);
        pr=MergeSort(a,mid+1,r);
    }
    else
    {
        int *tmp=new int(a[l]);
        return tmp;
    }
    return Merge(pl,pr,mid-l+1,r-mid);    
}


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        
    }
    
    int *ans=MergeSort(a,1,n);
    
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    
    
    return 0;
}