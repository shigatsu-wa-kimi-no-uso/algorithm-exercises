#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

int n;

const int MOD = 1E9 + 7;

int a[5500];

long long comb2(int n)
{
	return n * (n - 1) / 2;
}

long long comb3(int n)
{
	return n * (n - 1) * (n - 2) / 6;
}


int main()
{
	cin >> n;
	long long cnt = 0;
	int t,amin=0x3f3f3f3f,amax=0;
	for (int i = 1; i <= n; i++)
	{
		cin >> t;
		a[t]++;
		amax = max(amax, t);
		amin = min(amin, t);
	}

	for (int i = amin+1; i <= amax; i++)
	{
		if (a[i] >= 2)
		{
			for (int j = amin; j <= i/2; j++)
			{
				if (a[j] > 0 && a[i - j] > 0)
				{
					if (j != i - j)
						cnt = (cnt + comb2(a[i]) * a[j] * a[i - j]) % MOD;
					else if (j == i-j && a[j]>=2)
						cnt = (cnt + comb2(a[i]) * comb2(a[j])) % MOD;
				}
			}
		}
	}
	cout << cnt;

	return 0;
}
