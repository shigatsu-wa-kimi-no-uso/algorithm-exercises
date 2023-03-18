#include<iostream>

using namespace std;

int m;
int fi[10],to[10],ne[10];

void link(int x,int y)
{
	to[++m]=y;
	ne[m]=fi[x];
	fi[x]=m;
	printf("link(%d,%d) to[%d]=%d  ne[%d]=%d fi[%d]=%d\n",x,y,m,to[m],m,ne[m],x,fi[x]);
	
}

int main()
{
	link(1,0);
	link(2,0);
	link(3,0);
	link(4,1);
	link(5,1);
	link(6,3);
	link(7,3);
	link(8,3);
/*	for(int i=0;i<9;i++)
	{
		printf("%d",i);
		for(int t=fi[i];t;t=ne[t])
		{
			printf("->%d",t);
		}
		printf("\n");

	}

	*/
	return 0;
}


