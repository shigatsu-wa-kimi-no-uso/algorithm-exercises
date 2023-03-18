#include<iostream>
#include<sstream>
using namespace std;


//P1928
//字符串处理题
string s;

int process(int p)
{
    string str;
    stringstream ss;
    bool digit=0;
    int off=0;
    int val;
    for(int i=p+1; i<s.length(); i++)
    {
        //sd[2xg[4ds[7ad]]]ss
        //s[4t]g[5e]q
        //[2[2[2CB]]]
        if(s[i]=='[')
        {
            //   cout<<"found [ at"<<i<<"\n";
            if(digit)
            {

                // cout<<"off:"<<off<<"\n";
                //  cout<<"getdigit ";
                digit=0;
                ss<<s.substr(i-off,off);
                ss>>val;
                //  cout<<val<<"\n";


            }
            i=process(i);
            // cout<<"ret with pos"<<i<<"\n";
        }
        else if(s[i]==']')
        {
            // cout<<"found ] at"<<i<<"\n";
            // cout<<"copy "<<str<<" "<<val<<" times\n";
            str=s.substr(p+off+1,i-p-off-1);
            s.erase(p,i-p+1);
            int k=p;
            for(int j=1; j<=val; j++)
            {
                s.insert(k,str);
                k+=str.length();
            }
            //  cout<<"str now "<<s<<"\n";
            //  cout<<"strlen "<<s.length()<<"\n";
            return k-1;
        }
        else if(s[i]>='0'&&s[i]<='9')
        {
            // cout<<"digit at "<<i<<"\n";
            digit=1;
            off++;
        }
        else
        {

            if(digit)
            {
                // cout<<"off:"<<off<<"\n";
                //  cout<<"getdigit ";
                digit=0;
                ss<<s.substr(i-off,off);
                ss>>val;
                //  cout<<val<<"\n";
            }
        }
    }
}


int main()
{

    s.reserve(20005);
    cin>>s;
    int cnt=0;
    bool found=0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='[')
        {
            // cout<<"found [ at"<<i<<"\n";
            i=process(i);
        }
    }
    cout<<s;



    return 0;
}