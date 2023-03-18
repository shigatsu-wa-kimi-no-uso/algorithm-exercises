#include<iostream>
#include<algorithm>
using namespace std;
//P3985 不开心的金明


int pv[105], w[105], v[105];

int n, V;

int f[10000][105];

int main()
{
	cin >> n >> V;
	int sumv = 0;
	int minv = 0x3fffffff;
	for (int i = 1; i <= n; i++)
	{
		cin >> pv[i] >> w[i];
		sumv += pv[i];
		minv = min(pv[i], minv);
	}
	sumv -= (minv - 1) * n;
	for (int i = 1; i <= n; i++)
	{
		v[i] = pv[i] - minv + 1;
	}】 
	for (int i = 1; i <= n; i++)
	{
		for (int j = sumv; j >=v[i]; j--)
		{
			for (int k = n; k > 0; k--)
			{
				if (j + k * (minv - 1) <= V)
				{
					f[j][k] = max(f[j][k], f[j - v[i]][k - 1] + w[i]);
				}
			}
		}
	}
	cout << *max_element(&f[0][0], &f[sumv][n]);
	return 0;
}
