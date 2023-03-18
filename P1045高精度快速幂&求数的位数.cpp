#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

//P1045 高精度快速幂&求数的位数

int n;

char *hmult(char *a,char *b)
{
    int la=strlen(a);
    int lb=strlen(b);
    
    char *s=new char[la+lb+2];
    memset(s,0,sizeof(char[la+lb+2]));
    int i,j;
    for(i=0;a[i]!=0;i++)
    {
        for(j=0;b[j]!=0;j++)
        {
            s[i+j]+=(a[la-1-i]-'0')*(b[lb-1-j]-'0');
            s[i+j+1]+=s[i+j]/10;
            s[i+j]%=10;
       //    cout<<a[la-i-1]<<" * "<<b[lb-1-j]<<" = "<<(int)s[i+j]<<"\n";
       //    cout<<(int)s[i+j+1]<<" ex\n";     
        }
    }
    int k;
    for(k=0;k<=i+j-1;k++) //转换成ascii
    {
        s[k]+='0';
    }
    k--;
    while(s[k]=='0' && k>0)    //去除前导0 保留一个0
    {
        s[k]=0;
        k--;
    }
    char *t=new char[500];        //高精度取模 取前500位
    strncpy(t,s,500);
    delete s;
    reverse(t,t+strlen(t));    
    return t;
}


char *qpow(int n,char *base)
{
    char *s=new char[2];
    char *ps;
    char *pbase;
    s[0]='1';
    s[1]=0;
    int cnt=0;
    while(n)
    {
        if(n&1)    //最后一位是否为0
        {        
            ps=s;
            s=hmult(s,base);
            delete ps;
        }
        pbase=base;
        base=hmult(base,base);  
        delete pbase;
        n>>=1;
    }
    return s;
}



int main()
{
    int n;
    cin>>n;  
    char *base=new char[2];
    base[0]='2';
    base[1]=0;   
    char *t=qpow(n,base);
    int l=strlen(t);
    t[l-1]-=1;
    cout<<(int)(n*log10(2)+1)<<"\n";
    int cnt=0;
    if(l<500)
    {
        while(l<500)
        {
            cout<<0;
            l++;
            cnt++;
            if(cnt%50==0)
                cout<<"\n";
        }
        for(int i=0;cnt<500;i++)
        {           
            putchar(t[i]);
            cnt++;
            if(cnt%50==0)
                cout<<"\n";
        }       
    }
    else 
    {
        int i;
        int cnt=0;
        for(i=l-500;i<l;i++)
        {
            putchar(t[i]);
            cnt++;
            if(cnt%50==0)
            {
                putchar('\n');
            }
        }
        
    }
    
    return 0;
}