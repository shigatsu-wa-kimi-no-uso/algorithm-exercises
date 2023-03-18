#include<iostream>
#include<queue>
using namespace std;

int s,v;
//P5707


struct TIME
{
    int h;
    int m;
    bool flag;
    TIME(){}
    TIME(int h,int m,bool flag)
        :h(h),m(m),flag(flag){}
    TIME operator+(const TIME &right) const
    {
        TIME res(h,m,flag);
        res.h+=right.h;
        res.m+=right.m;
        if(res.m>=60)
        {
            res.h+=res.m/60;
            res.m%=60;
        }
        if(res.h>=24)
        {
            res.h%=24;
        }
        return res;
    
    }
    
    TIME operator-(const TIME &right) const
    {
        TIME res(h,m,flag);
        res.h-=right.h;
        res.m-=right.m;
        if(res.m<0)
        {
            res.m-=60;
            res.h+=res.m/60;
            res.m%=60;
            res.m+=60;
        }
        if(res.h<0)
        {
            res.h%=24;
            res.h+=24;
        }
        return res;
    }
};



int main()
{
    ios::sync_with_stdio(false);
    cin>>s>>v;
    TIME time(0,s/v,s%v);
   
    TIME ans=TIME(8,0,0)-time-TIME(0,10,0);
    if(time.flag)
        ans=ans-TIME(0,1,0);
    printf("%02d:%02d",ans.h,ans.m);
    
    return 0;
}