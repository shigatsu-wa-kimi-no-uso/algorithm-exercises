#include<iostream>
#include<algorithm>
using namespace std;


//P1255

string a[5005];

int n;

inline string hplus(string a,string b)
{
    if(a.length()<b.length())
        swap(a,b);
    string t;
    t.reserve(a.length()+2);
    int i=1;
    int extra=0;
    int val;
    int la=a.length(),lb=b.length();
    if(la>lb)
    {
        b.insert(0,la-lb,'0');
    }
    lb=b.length();
    char d;
    //cout<<a<<" "<<b<<" st\n";
    while(1)
    {
        val=a[la-i]+b[lb-i]-96+extra;
        d=val%10+48;
        extra=val/10;
        t.push_back(d);
        //cout<<d<<' ';
       // cout <<"val*"<<val<<"\n ";
       // cout<<extra<<"s t ";
        if(i==lb)
        {
            //cout<<extra<<' ';
            if(extra!=0)
                t.push_back(extra+48);
            break;
        }
        i++;                      
    }
    reverse(t.begin(),t.end());
    return t;
}



int main()
{
    a[1]="1";
    a[2]="2";
//   string a,b,c;
//  cin>>a>>b;
  //  c=hplus(a,b);
//  cout<<c;
    cin>>n;
    
    
    for(int i=3;i<=n;i++)
    {
        a[i]=hplus(a[i-1],a[i-2]);
    }
    cout<<a[n];
    return 0;
}