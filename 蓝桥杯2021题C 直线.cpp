#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;


//蓝桥杯2021 题C 直线

struct PNT
{
    double x,y;
} pnt[10057];

struct LN
{
    double a,b,c;
    //标准多元素比较重载函数
    bool operator<(const LN &right) const
    {
        if(!(abs(a-right.a)<1E-5))
        {
            return a<right.a;
        }
        if(!(abs(b-right.b)<1E-5))
        {
            return b<right.b;
        }
        if(!(abs(c-right.c)<1E-5))
        {
            return c<right.c;
        }
        
        return 0;
    }    
};




LN getln(PNT p1,PNT p2)
{
    double a,b,c;
    if(abs(p1.x-p2.x)<1E-5)
    {
        a=1;
        b=0;
        c=-p1.x;
    }
    else if(abs(p1.y-p2.y)<1E-5)
    {
        a=0;
        b=1;
        c=-p1.y;
    }
    else
    {
        a=(p1.y-p2.y)/(p1.x-p2.x);
        b=-1;
        c=-a*p1.x+p1.y;
    }
    return {a,b,c};
}

set<LN> s;

int main()
{
    int m,n;
    cin>>m>>n;
    int cnt=0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            pnt[++cnt].x=i;
            pnt[cnt].y=j;
        }
    }
    int cnt2=0;
    for(int i=1; i<=cnt; i++)
    {
        for(int j=i+1; j<=cnt; j++)
        {
            LN l=getln(pnt[i],pnt[j]);
            s.insert(l);           
        }
    }   
    
    cout<<s.size();
    return 0;
}