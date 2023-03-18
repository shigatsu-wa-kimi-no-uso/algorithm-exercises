#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

char map[22][22]={0};
char hact[8][2]={{-1,-2},{-2,-1},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
int bx,by,hx,hy,cnt=0;


typedef pair<int,int> pos;


int main()
{
	int i,j,k;
	bool flaghctrl;
	cin>>bx>>by>>hx>>hy;
	for(i=0;i<=bx;i++)
	{
		for(j=0;j<=by;j++)
		{
			flaghctrl=false;
			for(k=0;k<8;k++)
			{
				if( (i==hx+hact[k][1] && j==hy+hact[k][0] ) or (i==hx && j==hy))
				flaghctrl=true;
			}
			if(flaghctrl) continue;
			else map[i][j]=1;	
		}
	}
	pos p0(0,0);
	queue<pos> q;
	q.push(p0);
	while(!q.empty())
	{
		pos pt=q.front();
		if(pt.first==bx && pt.second==by) cnt++;
		q.pop();
		if(map[pt.first+1][pt.second]==1) 
		{
			q.push(make_pair(pt.first+1,pt.second));
		}
		if(map[pt.first][pt.second+1]==1)
		{
			q.push(make_pair(pt.first,pt.second+1));
		}
	}
	
	cout<<cnt;

	return 0;
}


