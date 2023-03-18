#include<iostream>
#include<cmath>
using namespace std;

//P1024 一元三次方程求解

double a,b,c,d;

double v1,v2;

double da,db,dc;

double x1,x2;


inline double val(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}



int main()
{
    cin>>a>>b>>c>>d;
    da=3*a;
    db=2*b;
    dc=c;
    double sqdelta=sqrt(db*db-4*da*dc);
    double ext1=(-db-sqdelta)/(2*da);
    double ext2=(-db+sqdelta)/(2*da);
    
    double x1l=ext1;
    double x2r=ext2;


    if(a>0)
    {
        while(val(x1l)>0)
        {
            x1l-=10;
        }
        while(val(x2r)<0)
        {
            x2r+=10;
        }
    }
    else if(a<0)
    {
        while(val(x1l)<0)
        {
            x1l-=10;
        }
        while(val(x2r)>0)
        {
            x2r+=10;
        }
    }
    double mid,l=x1l,r=ext1;
    double x1,x2,x3;

    if(a>0)
    {
        while(1)
        {            
            mid=(l+r)/2;
            if(val(mid)>0)
            {
                r=mid;
            }
            else if(val(mid)<0)
            {
                l=mid;
            }
            if(abs(val(mid))<1E-6)
            {
                x1=mid;
                break;            
            }
            
        }
        l=ext1;
        r=ext2;
        while(1)
        {
            mid=(l+r)/2;
            if(val(mid)>0)
            {
                l=mid;
            }
            else if(val(mid)<0)
            {
                r=mid;
            }
            if(abs(val(mid))<1E-6)
            {
                x2=mid;
                break;
            }
        }
        l=ext2;
        r=x2r;
        while(1)
        {
            mid=(l+r)/2;
            if(val(mid)>0)
            {
                r=mid;
            }
            else if(val(mid)<0)
            {
                l=mid;
            }
            if(abs(val(mid))<1E-6)
            {
                x3=mid;
                break;
            }
        }
    }
    else if(a<0)
    {   
        while(1)
        {
            mid=(l+r)/2;
            if(val(mid)>0)
            {

                l=mid;
            }
            else if(val(mid)<0)
            {
                r=mid;
            }
            if(abs(val(mid))<1E-6)
            {
                x1=mid;
                break;
            }
        }
        l=ext1;
        r=ext2;
        while(1)
        {
            mid=(l+r)/2;
            if(val(mid)>0)
            {
                r=mid;
            }
            else if(val(mid)<0)
            {
                l=mid;
            }
            if(abs(val(mid))<1E-6)
            {
                x2=mid;
                break;
            }
        }
        l=ext2;
        r=x2r;
        while(1)
        {
            mid=(l+r)/2;
            if(val(mid)>0)
            {
                l=mid;
            }
            else if(val(mid)<0)
            {
                r=mid;
            }
            if(abs(val(mid))<1E-6)
            {
                x3=mid;
                break;
            }
        }
    }
    
    printf("%.2f %.2f %.2f",x1,x2,x3);
    
    
    return 0;
}