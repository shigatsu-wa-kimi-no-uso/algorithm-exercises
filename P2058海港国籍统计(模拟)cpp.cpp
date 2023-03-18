#include<iostream>
#include<map>
using namespace std;


//P2058 海港国籍统计


unsigned int fcnt[100005];
unsigned int gcnt;

map<int,int> m[100005];
unsigned int tms[100005];

int main()
{
    int n;
    cin>>n;
    unsigned int t;
    int k,g;
    int ord=1;
    map<int,int>::iterator mit;
    for(int i=1; i<=n; i++)
    {
        cin>>t>>k;
        tms[i]=t; //第i号船只到达时间为t

        while(t-tms[ord]>=86400) //超过24小时 注意 可能减去不只一个船只的人数
        {
            for(mit=m[ord].begin(); mit!=m[ord].end(); ++mit)
            {
                fcnt[mit->first]-=mit->second; //减去对应所含国籍人数
                if(fcnt[mit->first]==0)
                {
                    gcnt--; //所含国籍数减
                }
            }
            ord++;
        }
        for(int j=1; j<=k; j++)
        {
            cin>>g;
            m[i][g]++;   //新建的映射 value默认初始化为0
            if(!fcnt[g]) //未记录过
            {
                gcnt++;
            }
            fcnt[g]++;
        }   
        cout<<gcnt<<"\n";
    }
    return 0;
}