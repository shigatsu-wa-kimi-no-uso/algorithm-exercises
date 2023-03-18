#include<iostream>
using namespace std;


//P5076 
//BST 二叉排序树

int x;

struct NODE
{
    int ls;
    int rs;
    int size;
    int cnt;
    int val;
} n[100006];   //n[0]保留 置0

int cnt=1;

void add(int fa)
{
    n[fa].size++;    //当进入此节点时 以此节点为根的树的大小一定增加
    if(x==n[fa].val)
    {
        n[fa].cnt++;
        return;
    }
    
    if(x<n[fa].val)
    {
        if(n[fa].ls)
        {
            add(n[fa].ls);
        }
        else
        {
            n[cnt].val=x;
            n[cnt].size++;
            n[cnt].cnt++;
            n[fa].ls=cnt;
            cnt++;
        }
    }
    else
    {
        if(n[fa].rs)
        {
            add(n[fa].rs);
        }
        else
        {
            n[cnt].val=x;
            n[cnt].size++;
            n[cnt].cnt++;
            n[fa].rs=cnt;
            cnt++;
        } 
    }
}


int getRank(int fa)
{
    if(fa==0)
        return 0;
    if(x==n[fa].val)
    {
        return n[n[fa].ls].size;
    }
    if(x<n[fa].val)
    {
        return getRank(n[fa].ls);
    }
    return getRank(n[fa].rs)+n[n[fa].ls].size+n[fa].cnt;
}

int getVal(int fa,int rank)
{
    if(fa==0)
        return 0x7fffffff;
    //以前累加的排名加左儿子大小加父亲节点计数小于排名，即小于等于fa的排名还不够x 
    //累加排名后到右儿子查找
    if(rank+n[n[fa].ls].size+n[fa].cnt<x) 
    {
        return getVal(n[fa].rs,rank+n[n[fa].ls].size+n[fa].cnt);
    }
    //左儿子大小加之前累加的排名 大于等于x 说明答案在左儿子里 
    else if(rank+n[n[fa].ls].size>=x)
    {
        return getVal(n[fa].ls,rank); 
        //不能确定排名的变化，继承上次的排名不累加
    }
    //左儿子大学加之前累加的排名小于x 但加上fa的计数后大于x 说明答案就是fa
    else if(rank+n[n[fa].ls].size+n[fa].cnt>=x)
    {
        return n[fa].val;
    }
}

int getPredVal(int fa,int ans=0x80000001)
{
    if(n[fa].val>=x)
    {
        if(n[fa].ls)
            return getPredVal(n[fa].ls,ans);
        else
            return ans;     //没有比fa更小的点了 返回ans
    }
    else
    {
        ans=max(ans,n[fa].val);
        if(n[fa].rs)    //有右儿子看看右儿子情况 继承ans 
                        //如果找不到合适ans会返回以前的ans
        {
            return getPredVal(n[fa].rs,ans); 
        }      
        return ans;    //如果没右儿子说明没有比fa更大的点了 直接返回
    }
}

int getSucVal(int fa,int ans=0x7fffffff)
{
    if(n[fa].val<=x)
    {
        if(n[fa].rs)
        {
            return getSucVal(n[fa].rs,ans);
        }
        else
            return ans;   
    }
    else if(n[fa].val>x)
    {
        if(n[fa].cnt)
            ans=min(ans,n[fa].val);
        if(n[fa].ls)
        {
            return getSucVal(n[fa].ls,ans);
        }
        return ans;
    }

}


int main()
{
    int q,op;
    cin>>q;
    while(q--)
    {
        cin>>op>>x;
        switch(op)
        {
        case 1:
            cout<<getRank(1)+1<<"\n";
            break;

        case 2:
            if(x>n[1].size)
            {
                cout<<0x7fffffff<<"\n";
            }
            else
                cout<<getVal(1,0)<<"\n";
            break;
        case 3:
            cout<<getPredVal(1)<<"\n";
            break;
        case 4:
            cout<<getSucVal(1)<<"\n";
            break;
        case 5:
            if(cnt==1)
            {
                n[cnt].val=x;
                n[cnt].size++;
                n[cnt].cnt++;
                cnt++;
            }
            else
                add(1);
        }
    }
    return 0;
}