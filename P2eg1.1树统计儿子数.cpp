#include<iostream>
#include<stdio.h>

using namespace std;


int main()
{
	int n,x,y;
	scanf("%d",&n);
	int cnt[100]={0};
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		cnt[x]++;	
	} 
	for(int i=1;i<=n;i++)
	{
		printf("%d %d\n",i,cnt[i]);
	}
	 

	return 0;
}


