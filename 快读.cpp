#include<iostream>
#include<stdio.h>

using namespace std;

//适用于：纯数字,无字母 
inline int read() //快读
{
	int s = 0;
	char c = getchar();
	while (c < '0' || c>'9') 
		c = getchar();
	while (c >= '0' && c <= '9')
	{
		s = s * 10 + c - '0';
		c = getchar();
	}
	return s;
}



int main()
{
	return 0;
}


