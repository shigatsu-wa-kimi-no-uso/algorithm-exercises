#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

char a[2005];
char b[2005];

//P2758编辑距离(字符串操作dp)

int dp[2005][2005];

//定义dp[i][j]为 把字符串a的前i个转换为字符串b前j个所需次数
//操作：
//增加字符：dp[i][j]=dp[i][j-1]+1
//即 此状态比上一状态次数加一
//修改字符：dp[i][j]=dp[i-1][j-1]+1
//即 a的前i-1个字符串转换为b的前j-1个字符串的次数 加本次操作次数
//删除字符：dp[i][j]=dp[i-1][j]+1
//即 a的前i-1个字符转换为b的前j个(包含j 即 
//那种状态下已经转换为字符串b的次数)
//加上此操作(删除字符)的次数(意味着 删除原来的字符 加上对应的字符
// 或 只删除原来的字符的情况)
//发现相等  令此时次数与i-1.j-1时次数相同


int main()
{
    a[0]=b[0]=1;
    cin>>(a+1)>>(b+1);
    int l1=strlen(a);
    int l2=strlen(b);
    for(int i=0;i<=l1-1;i++)
    {
        dp[i][0]=i;
    }
    
    for(int j=0;j<=l2-1;j++)
    {
       dp[0][j]=j;
    }
    
    for(int i=1;i<=l1-1;i++)
    {
        
        for(int j=1;j<=l2-1;j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1];
         //   cout<<"j"<<i<<" "<<j<<"\n";
            }
            else
            {
                dp[i][j]=min({dp[i][j-1]+1,dp[i-1][j-1]+1,dp[i-1][j]+1});             
            }
        
        }
        
    }
    
    
    cout<<dp[l1-1][l2-1];
    return 0;
}