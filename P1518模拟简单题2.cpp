#include<iostream>
#include<cstring>
using namespace std;

char map[12][12];


//P1518 模拟

int dir[4][2]= {0,-1,1,0,0,1,-1,0};


int main()
{
    ios::sync_with_stdio(false);
    int i,j;
    int posc[2],posf[2];
    for(i=1; i<=10; i++)
    {
        for(j=1; j<=10; j++)
        {
            cin>>map[i][j];
            if(map[i][j]=='C')
            {
                posc[0]=j;
                posc[1]=i;
                map[i][j]='.';
            }
            else if(map[i][j]=='F')
            {
                posf[0]=j;
                posf[1]=i;
                map[i][j]='.';
            }

        }
    }
    int cnt=0;
    int d1=0,d2=0;
    while(memcmp(posf,posc,sizeof(posf)) && cnt!=100000)
    {


        if(map[posf[1]+dir[d1][1]][posf[0]+dir[d1][0]]=='.')
        {
            //     cout<<"f";
            //    cout<<posf[1]<<" "<<posf[0];
            posf[1]+=dir[d1][1];
            posf[0]+=dir[d1][0];
            //     cout<<" to "<<posf[1]<<" "<<posf[0]<<"\n";

        }
        else
        {
            d1++;
            if(d1==4)
            {
                d1=0;
            }
        }




        if(map[posc[1]+dir[d2][1]][posc[0]+dir[d2][0]]=='.')
        {
            //        cout<<"c";
            //     cout<<posc[1]<<" "<<posc[0];
            posc[1]+=dir[d2][1];
            posc[0]+=dir[d2][0];
            //     cout<<" to "<<posc[1]<<" "<<posc[0]<<"\n";

        }
        else
        {
            d2++;
            if(d2==4)
            {
                d2=0;
            }
        }

        //  getchar();
        cnt++;

    }
    if(cnt==100000)
        cout<<0;
    else
        cout<<cnt;

    return 0;
}