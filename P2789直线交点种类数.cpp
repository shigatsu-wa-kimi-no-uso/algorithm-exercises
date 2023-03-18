#include<iostream>
#include<set>
using namespace std;


//P2789直线交点种类数
set<int> dp[27]; //dp[i]存放i条边的交点个数
int N;

int main()
{
    cin>>N;
    dp[0].insert(0);
    dp[1].insert(0);
    dp[2].insert(0);
    dp[2].insert(1);
    int tmp=0;
    for(int i=3; i<=N; i++)  //i为原本平行线个数
    {
        dp[i].insert(0);
        for(int j=0; j<i; j++)
        {
            for(int val : dp[j])
            {
                tmp=0;
                tmp+=(i-j)*j+val;
                dp[i].insert(tmp);
      //          cout<<"j "<<j<<" t"<<tmp<<"\n";
            }
            
            //i条边的顶点数组成情况为
            //初始化i条边均互相平行
            //j条边开始不同程度地旋转
            //顶点数为
            //j条边与没有旋转的i-j条边的交点数即 j*(i-j)
            //加上j条边的可能顶点数情况 每种情况分别作为一种结果(之前求出的set集合中的每个元素)   
            dp[i].insert(tmp);
        }       
    }
    cout<<dp[N].size();


        return 0;
}