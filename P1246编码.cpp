#include<iostream>
using namespace std;

//P1246 编码

string s;

long long comb(int m,int n)
{
    long long ans=1;
    long long div=1;
    for(int i=1; i<=m; i++)
    {
        ans*=(n-i+1);
        div*=i;
    }
    return ans/div;
}

int main()
{
    cin>>s;
    long long ans=0;
    //bfg
    // axx
    //  ba-e

    int off;
    int off2;
    for(int i=0; i<s.length()-1; i++)
    {
        ans+=comb(i+1,26);
        // cout<<comb(i+1,26)<<"\n";
        // cout<<"ans"<<ans<<"\n";
    }

    //a c d
    // off2 1
    // off 3

    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            off=s[i]-'a'+1;
            if(i!=s.length()-1)
            {
                if(i>=1)
                {
                    off2=s[i-1]-'a'+1;
                    //     cout<<"off2 "<<off2<<" off"<<off<<"\n";
                    for(int k=off2+1; k<off; k++)
                    {
                        ans+=comb(s.length()-i-1,26-k);
                        //         cout<<k<<" +"<<comb(s.length()-i-1,26-k)<<"\n";
                        //     cout<<"ans"<<ans<<"\n";
                    }

                }
                else for(int k=1; k<off; k++)
                    {
                        ans+=comb(s.length()-1,26-k);
                        //       cout<<k<<" ans+"<<comb(s.length()-1,26-k)<<"\n";
                    }
            }
            else
            {
                if(i>=1)
                {
                    if(s[i]-s[i-1]<=0)
                    {
                        cout<<0;
                        return 0;
                    }
                    //    cout<<ans<<"before\n";
                    //   cout<<i<<"i\n";
                    //  cout<<(int)s[i]<<" "<<(int)s[i-1]<<" "<<s[i]-s[i-1]<<"\n";
                    ans+=s[i]-s[i-1];
                }
                else ans+=off;
            }

        }
        else
        {
            cout<<0;
            return 0;
        }
    }

    cout<<ans;
    return 0;
}