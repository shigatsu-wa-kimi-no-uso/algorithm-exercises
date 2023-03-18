#include<iostream>
#include<string>
#include<cstring>
using namespace std;


//P1706 全排列遍历模板
int n;
string s;
bool used[12];

void recur(int time)
{
    if(time==n)
    {     
        cout<<s;       
        cout<<'\n';
        
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!used[i])
        {
            used[i]=1;
            char t[10];
            sprintf(t,"%5d",i);
            s+=t;
            recur(time+1);
            s.resize(s.length()-strlen(t));
            used[i]=0;
        }
        
    }

}

int main()
{
    cin>>n;
    recur(0);
    
    return 0;
}