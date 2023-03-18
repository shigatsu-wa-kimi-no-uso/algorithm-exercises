#include<iostream>
using namespace std;

//P1157
//组合遍历模板 
int n,r; 
bool used[100];

void recur(int time,int last)
{
    if(time==r)
    {
        for(int i=1;i<=n;i++)  
        {
            if(used[i])
            {
                printf("%3d",i);
            }
        }   
        cout<<"\n" ;  
        return;
    }
    
    for(int i=last+1;i<=n;i++)
    {
        if(!used[i])
        {
            used[i]=1;
            recur(time+1,i);
            used[i]=0;      
        }
    }
}




int main()
{
    cin>>n>>r;
    recur(0,0);
    
    return 0;
}