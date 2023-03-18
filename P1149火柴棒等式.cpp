#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

int n;

const int D[10] = { 6,2,5,5,4,5,6,3,7,6 };

int need[2001];

int main()
{
	int cnt;
	cin >> n;
	int ans = 0;
	for(int i=0;i<2001;i++)
	{
		char s[5];
		sprintf(s, "%d", i);
		for (int j = 0; j < strlen(s); j++)
		{
			need[i] += D[s[j] - '0'];
		}
	}
	for (int i = 0; i <= 1000; i++)
	{
		for (int j = 0; j <= 1000; j++)
		{
			int res = i + j;
			cnt = 4+need[i]+need[j]+need[res];
			if (cnt == n) ans++;
		}
	}
	cout << ans;
	return 0;
}
