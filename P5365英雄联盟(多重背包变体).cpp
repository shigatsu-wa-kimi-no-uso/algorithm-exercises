#include<iostream>
using namespace std;

//P5365 Ó¢ÐÛÁªÃË

long long n, m;

long long k[50000];
long long c[50000];

long long f[50000];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
	}

	long long maxc = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		maxc += c[i]*k[i];
	}

	f[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = maxc; j >= 0; j--)
		{
			for (int p = 0; p<=k[i] && p*c[i]<=j; p++)
			{
				f[j] = max(f[j], p*f[j - p*c[i]]);
			}
		}
	}
	for (int j = 1; j <= maxc; j++)
	{
		if (f[j] >= m)
		{
			cout << j;
			break;
		}
	}
	return 0;
}
