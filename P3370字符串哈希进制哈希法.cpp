#include<iostream>
#include<vector>
#include<cmath>
typedef unsigned long long ull;
using namespace std;


//P3370 字符串哈希进制哈希法



int base=70;
int mod=13337;
string s[10005];
int n;

struct HASH
{
    int cnt;
    vector<int> id;
} hashe[13337];

int shash[10005];

int gethash(string s)
{

    int hashval=1;
    for(char ch : s)
    {
        if(ch>='a' && ch<='z')
            hashval=(hashval*base+(ch-'a'+11))%mod;
        else if(ch>='A'&&ch<='Z')
            hashval=(hashval*base+(ch-'A'+37))%mod;
        else if(ch>='0' && ch<='9')
            hashval=(hashval*base+(ch-'0'+1))%mod;
    }
    return hashval;
}


int main()
{
    cin>>n;
    bool flag=0;
    int val;
    for(int i=1; i<=n; i++)
    {
        cin>>s[i];
        shash[i]=gethash(s[i]);
        val=shash[i];
        if(hashe[val].cnt==0)
        {
            hashe[val].cnt++;
            hashe[val].id.push_back(i);
        }
        else
        {
            for(int v : hashe[val].id)
            {
                if(s[v]==s[i])
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                hashe[val].cnt++;
                hashe[val].id.push_back(i);
            }
            else
                flag=0;
        }
    }
    int ans=0;

    for(int i=1; i<=n; i++)
    {
        if(hashe[shash[i]].cnt)
        {
            ans++;
            hashe[shash[i]].cnt--;
        }
    }
    cout<<ans;
    return 0;
}