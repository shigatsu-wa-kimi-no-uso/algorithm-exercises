#include<iostream>
#include<stdio.h>
#include<stack>
#include<stdlib.h>
using namespace std;

struct CARPET
{
	int lx,ly;
	int dx,dy;
};


int main()
{
	int i,j,k;
	int n;
	cin>>n;
	CARPET* cp=(CARPET*)calloc(n,sizeof(CARPET));
	for(i=0;i<n;i++)
	{
		cin>>cp[i].lx>>cp[i].ly>>cp[i].dx>>cp[i].dy;
	}
	int x,y;
	cin>>x>>y;
	for(i=n-1;i>=0;i--)
	{
		if(x>=cp[i].lx && x<=cp[i].lx+cp[i].dx && y>=cp[i].ly && y<=cp[i].ly+cp[i].dy)
		{
			cout<<i+1;
			break;
		}
	}
	if(i<0) cout<<-1;
	
	return 0;
}


