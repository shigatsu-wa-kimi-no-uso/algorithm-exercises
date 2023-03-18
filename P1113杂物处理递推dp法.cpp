#include<iostream>
#include<vector>
using namespace std;



//P1113 杂务处理 递推dp法
vector<int> e[10005];

int N;

struct NODE
{

    int w;
}v[10005];

void link(int x,int y)
{
    e[x].push_back(y);
}




int main()
{
    cin>>N;
    int i,x,w,pred;
    int maxpred=0;
    int maxt=0;
    for(i=1;i<=N;i++)
    {
        cin>>x>>w;
        while(1)
        {
            cin>>pred;    //输入当前点的前驱
            if(pred==0)
            {
                break;
            } 
            link(x,pred);
            if(v[maxpred].w<v[pred].w)     
            {
                maxpred=pred;
            }
        }
        v[x].w=w+v[maxpred].w;
        maxpred=0;
        maxt=max(v[x].w,maxt);
    }
    cout<<maxt;
    return 0;
}