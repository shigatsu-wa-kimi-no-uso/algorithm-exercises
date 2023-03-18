#include<iostream>
#include<cmath>
using namespace std;

int n;

//P1990 动态规划

int d1[1000005];
int d2[1000005];
int dl[1000005];
int dL[1000005];
int dr[1000005];

//定义d1[i]为放满2*i格子的方案数 以竖条结尾
//d2[i]以两横条结尾
//dl[i]为以L或类似结尾 最长的一节长度为i
//dr L型后插横岗形成另一种L
//dL L型后补齐的
//d1[i]=d1[i-1]+d2[i-1]+dL[i-1]
//d2[i]=d1[i-2]+...
//dl[i]=2*d1[i-2]+2*d2[i-2]+2*dL[i-2]
//dr[i]=dl[i-1]+dr[i-1]
//dL[i]=dl[i-1]+dr[i-1]
/*
012 002 011 001 011
012 112 022 011 001
00 01 
11 01 

012233
01123

0221
0011

00113
02233

d1 5
d2 2
dl 2
d7 2
11
d1 11
d2 5
dl 3
d7 3
22
d1 22
d2 11
dl 7
d7 7*/



int main()
{
    int mod=10000;
    cin>>n;
    d1[1]=1;
    d1[2]=1;
    d2[2]=1;
    dl[2]=2;
    
    
    
    for(int i=3;i<=n;i++)
    {              
        d1[i]=(d1[i-1]+d2[i-1]+dL[i-1])%mod;
        d2[i]=(d1[i-2]+d2[i-2]+dL[i-2])%mod;
        dl[i]=(2*d1[i-2]+2*d2[i-2]+2*dL[i-2])%mod;
        dr[i]=(dl[i-1]+dr[i-1])%mod;
        dL[i]=(dl[i-1]+dr[i-1])%mod;
    //    cout<<d1[i]<<" "<<d2[i];
     //   cout<<" "<<dl[i]<<" "<<dL[i]<<"\n";
     }
    
    
    cout<<(d1[n]+d2[n]+dL[n])%mod;
    
    return 0;
}