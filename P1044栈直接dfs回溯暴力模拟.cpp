#include<iostream>
#include<stack>
using namespace std;

//P1044 dfs回溯暴力法

int n;
int cnt;
stack<int> t;

void recur(int left)    //还未进过栈的个数
{
    if(left==0)    //结束标志 未进过栈的个数为0
    {
        cnt++;
        return;
    }
    
    if(!t.empty())    //每次都有两种操作 弹出栈顶元素输出或把未入过栈的元素压入栈
    {
        int tmp=t.top();
        t.pop();
        recur(left);  
        t.push(tmp);    //恢复状态
    }
    t.push(n-left+1);      //1代指值，由于题目不要求输出具体内容，默认使用1
    recur(left-1);          
    t.pop();    //恢复状态，回溯时应恢复状态
}

int main()
{
    cin>>n;
    recur(n);
    cout<<cnt;
    return 0;
}