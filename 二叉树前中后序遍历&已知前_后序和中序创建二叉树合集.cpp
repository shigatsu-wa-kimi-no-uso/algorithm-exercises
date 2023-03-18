#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

/*二叉树 前序中序后序遍历
& 已知前/后序 和中序 重建二叉树 合集*/

//例题P1827


struct NODE
{
    char ls;
    char rs;
    char w;
} n[40];


inline int id(char ch)
{
    return ch-'A';
}
char pre[30];    //前序遍历标识
char in[30];    //中序遍历标识
char post[30];  //后序遍历标识
char pre2[30]; //DRL型前序遍历标识

void dlr(char fa)        //前序遍历
{
    printf("%c ",fa);
    if(n[id(fa)].ls)
    {
        
        dlr(n[id(fa)].ls);
    }
    if(n[id(fa)].rs)
    {
        dlr(n[id(fa)].rs);
    }
}
 

//DRL型前序遍历与后序遍历的关系：
//后序遍历标识==将DRL型前序遍历标识反转 
void drl(char fa)        //DRL型前序遍历
{
    static int cnt=0;
    sprintf(pre2+cnt,"%c",fa);
    cnt++;
  //  printf("%c ",fa);
    if(n[id(fa)].rs)
    {      
        drl(n[id(fa)].rs);
    }
    if(n[id(fa)].ls)
    {
        drl(n[id(fa)].ls);
    }
}


void ldr(char fa)   //中序遍历
{
    if(n[id(fa)].ls)
    {
        ldr(n[id(fa)].ls);
    }
    
    printf("%c ",fa);
    
    if(n[id(fa)].rs)
    {
        ldr(n[id(fa)].rs);
    }
}

void lrd(char fa)    //后序遍历
{   
    static int cnt=0;
    if(n[id(fa)].ls)
    {
        lrd(n[id(fa)].ls);
    } 
    
    if(n[id(fa)].rs)
    {
        lrd(n[id(fa)].rs);
    }
    sprintf(post+cnt,"%c",fa);
    cnt++;
  //  printf("%c",fa);
}

/*

GBEDAFCH
GEDBFHCA
*/
/*
ABEDFCHG in
CBADEFGH pre
AEFDBHGC post
*/
/*
ABEDFCHG
AEFDBHGC
*/

//已知后序 中序 创建二叉树
void remake2(int &pos,int start,int end)
{
//后序遍历从后向前扫描
    if(pos==0) //最后一个节点，一定是叶子，直接返回
    {
        return;
    }
    char now=post[pos];
    int i;
 /*   cout<<"chkroot "<<now<<"\n";
    cout<<"inord "<<"\n";
    for(int i=start;i<end;i++)
    {
        cout<<in[i]<<" ";
    }
    cout<<"\n";*/
    for(i=start;i<end;i++)
    {
        if(in[i]==now)
        {
            break;
        }
    }    
    pos--; //从后向前
    if(i!=end-1) //有右儿子
    {
     //   cout<<"rs! "<<pre[pos]<<"\n";
        n[id(now)].rs=post[pos];
        remake2(pos,i+1,end);
    }
  //  else cout<<"no rs\n";
 /*   
    cout<<"ret chkroot "<<now<<"\n";
    cout<<"inord "<<"\n";
    for(int i=start;i<end;i++)
    {
        cout<<in[i]<<" ";
    }
   cout<<"\n";*/
    if(i!=start) //有左儿子
    {
  //      cout<<"ls! "<<now<<"\n";
        n[id(now)].ls=post[pos];
        remake2(pos,start,i);
    }
  //  else cout<<"no ls\n";
}


//已知前序 中序 创建二叉树
void remake(int &pos,int start,int end,int l)
{
    if(pos==l) return;
    char now=pre[pos];
    int i;
    for(i=start;i<end;i++)
    {
        if(in[i]==now)
        {
            break;
        }
    }
    
  /* cout<<"chkroot "<<posnow<<"\n";
    cout<<"inord "<<"\n";
    for(int i=start;i<end;i++)
    {
        cout<<in[i]<<" ";
    }
    cout<<"\n";*/
    pos++;
    if(i!=start)    //说明该节点左边有树
    { 
       // cout<<"ls! "<<posnow<<"\n";
        n[id(now)].ls=pre[pos];   
        remake(pos,start,i,l);//检索前半段
    }
 //   else cout<<"no ls\n";
    
    /*cout<<"ret chkroot "<<posnow<<"\n";
    cout<<"inord "<<"\n";
    for(int i=start;i<end;i++)
    {
        cout<<in[i]<<" ";
    }
    cout<<"\n";*/
    if(end-1!=i)//有右儿子
    {      
     // cout<<"rs! "<<pre[pos]<<"\n";
        n[id(now)].rs=pre[pos];
        remake(pos,i+1,end,l); //检索后半段
    }
  
}


int main()
{
    return 0;
}