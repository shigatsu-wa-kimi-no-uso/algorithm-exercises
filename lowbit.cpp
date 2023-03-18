#include<iostream>
#include<stdio.h>

using namespace std;

int lowbit(int x)
{
	return x&(-x);
} 

int main()
{
	int i=15;
	while(lowbit(i))
	{
		cout<<lowbit(i)<<" ";
		i-=lowbit(i);
	}
	
	return 0;
}


