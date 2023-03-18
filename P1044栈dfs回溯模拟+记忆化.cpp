#include<iostream>
#include<stack>
using namespace std;

//P1044栈 dfs回溯+记忆化


int n;
stack<int> t;
//int cnt[25][25];  //状态进入计数 
unsigned long long f[25][25]; //记忆化
//data[i][j]记录当i个在栈中，j个已弹出

//当还有n个未进过栈的数据 栈中有m个数据时，对此时分析得到结果一定
//又由于状态(m,n)可由pop步骤 即(m+1,n)->(m+1-1,n)得到
//也可由push步骤(m-1,n+1)->(m-1+1,n+1-1)得到
//出现了重复，因此使用记忆化dfs可加速



unsigned long long recur(int stacksize,int left)    //已经弹出的个数，还未进过栈的个数
{ 
    
   // cout<<"into "<<stacksize<<" "<<left<<"\n";
    if(f[stacksize][left])
    { 
      //  cout<<" got\n";    //dfs细节信息打印
      //  cout<<cnt[stacksize][left]<<"\n";
     //   cnt[stacksize][left]++;
    // cout<<stacksize<<" "<<left;
    //    cout<<" have gotten data ret"<<f[stacksize][left]<<"\n";
         return f[stacksize][left];
    }
  
    if(left==0)    //结束标志 未进栈的个数为0
    {
      //  cout<<"ret 1\n";
       
        return 1;
    }
    
    if(!t.empty())    //每次都有两种操作 弹出栈顶元素输出或把未入过栈的元素压入栈
    {
        int tmp=t.top();
        t.pop();
    //    cout<<stacksize<<" "<<left;
     //   cout<<" pop\n";
        f[stacksize][left]+= recur(stacksize-1,left);
        t.push(tmp);    //恢复状态
   //     cout<<" return to ";
  //      cout<<stacksize<<" "<<left<<"\n";
    }
    t.push(n-left+1);     
 //   cout<<stacksize<<" "<<left;
  //  cout<<" push\n";
    f[stacksize][left]+=recur(stacksize+1,left-1);          
    t.pop();    //恢复状态，回溯时应恢复状态
  //  cout<<" return to ";
 //   cout<<stacksize<<" "<<left<<"\n";
  //  cout<<stacksize<<" "<<left;
  //  cout<<" get data ret "<<f[stacksize][left]<<"\n";
    // cnt[stacksize][left]++;
    return f[stacksize][left]; 
   
}

int main()
{
    cin>>n;
    
    cout<<recur(0,n);
    return 0;
}