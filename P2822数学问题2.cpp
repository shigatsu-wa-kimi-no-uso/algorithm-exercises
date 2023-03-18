#include<iostream>
using namespace std;


//P2822 数学问题2
int comb[2005][2005];
int f[2005][2005];


int main()
{
    int t,k;
    cin>>t>>k;
    int n,m;
    int i,j;
    for(int i=1; i<2001; i++)
    {
        comb[i][0]=1;
        comb[i][i]=1;
    }

    for(i=1; i<2001; i++)
    {
        for(j=1; j<=i-1; j++)
        {
            comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%k;          
        }
        
    }

    for(i=1; i<=2001; i++)
    {
        for(j=0; j<=i; j++)
        {
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
            //矩阵和状态转移方程
            if(comb[i][j]==0)
            {
                f[i][j]+=1;
            }
         //   getchar();
         //  cout<<comb[i][j]<<" ";
        }
   //     cout<<"\n";
        f[i][i+1]=f[i][i];
        //由于每一行的行数会加一 下一行比上一行多一格
        // 需要把下一行最后一格的正上面的矩阵和继承旁边的值才能保证正常递推
    }


    for(i=1; i<=t; i++)
    {
        cin>>n>>m;
        if(m>n)
            cout<<f[n][n]<<"\n";
        else 
            cout<<f[n][m]<<"\n";
    }
    return 0;
}