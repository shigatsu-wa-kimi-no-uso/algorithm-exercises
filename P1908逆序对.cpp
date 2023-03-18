#include<iostream>
using namespace std;

int a[500005];
int n;
long long ans;

//P1908逆序对

int *merge(int *pl,int *pr,int sizel,int sizer)
{
    int i,j;
    int pos=0;
    int *tmp=new int[sizel+sizer];
    int cnt=0;
    
    /*cout<<"merge data :\n";
    for(int m=0;m<sizel; m++)
    {
        cout<<pl[m]<<" ";
    }
    
    cout<<"\n";
    for(int m=0;m<sizer;m++)
    {
        cout<<pr[m]<<" ";
    }
    cout<<"\n";*/
    for(i=0,j=0;i<sizel && j<sizer;)
    {
        if(pl[i]>pr[j])
        {
            ans+=1;     //逆序对个数加一
            tmp[pos++]=pr[j];
    //        cout<<"逆序对 "<<pl[i]<<" "<<pr[j]<<"\n";
     //       cout<<"ans+ "<<1<<" \n";
            j++;
        }
        else
        {
            ans+=cnt; //继承之前的逆序对个数
      //      cout<<"ans +"<<cnt<<"\n";
            tmp[pos++]=pl[i];
            i++;
            cnt=j;
        }
    }   
    
    if(i==sizel)
    {       
        for(;j<sizer;j++)
        {
            tmp[pos++]=pr[j];
        }   
    }
    else if(j==sizer)
    {
        tmp[pos++]=pl[i++];
        ans+=cnt;
        for(;i<sizel;i++)
        {
            ans+=j;
      /*    cout<<" 逆序对 "<<pl[i]<<" with ";
            for(int k=0;k<sizer;k++)
            {
                cout<<pr[k]<<" ";
            }
            cout<<"ans+ "<<j<<"\n";*/
            tmp[pos++]=pl[i];
        }
    }    
    delete pl,pr,cnt;        
    return tmp;
}

int *MergeSort(int *a,int l,int r)
{
  //  cout<<l<<" "<<r<<"\n";
    int *pl,*pr;
    int mid=(l+r)/2;
    if(l!=r)
    {
        pl=MergeSort(a,l,mid);
        pr=MergeSort(a,mid+1,r);   
    }
    else
    {
        int *tmp=new int(a[l]);
        return tmp;
    }
    
    return merge(pl,pr,mid-l+1,r-mid);
}




int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    
    int *b=MergeSort(a,1,n);
    /*
    for(int i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }*/
    
    cout<<ans;
    
    return 0;
}