#include<iostream>
#include<algorithm>
using namespace std;

//P1103 书本整理DP

int n, k;

int g;

struct A
{
	int h, w;
}a[130];

int f[130][130];

bool cmp(A &lft,A &rgt)
{
	return lft.h < rgt.h;
}

int main()
{
	int t;
	int cnt = 0;
	cin >> n >> k;
	int sum = 0;
	g = n - k;
	for (int i = 1; i <= n; i++)
	{
		cin  >> a[i].h >> a[i].w;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 2; j <= g; j++)
		{
			f[i][j] = 0x3f3f3f3f;
		}
	}
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i-1; j++)
		{
			for (int l = 2; l <= min(i,g); l++)
			{
				f[i][l] = min(f[i][l], f[j][l - 1] + abs(a[i].w - a[j].w));
			}
		}
	}
	int ans = 0x7fffffff;
	for (int i = g; i <= n; i++)
	{
		ans = min(ans, f[i][g]);
	}
	cout << ans;
	return 0;
}
