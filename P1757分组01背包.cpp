#include<iostream>
#include<vector>
using namespace std;

//P1757 ·Ö×é01±³°ü

int f[1005][1005];

int m, n;

vector<int> w[1005];
vector<int> v[1005];



int main()
{
	cin >> m >> n;
	int a, b, c;
	int maxg = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b >> c;
		w[c].push_back(a);
		v[c].push_back(b);
		maxg = max(c, maxg);
	}
	for (int i = 1; i <= maxg; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			f[i][j] = f[i - 1][j];
			for (int k = 0; k < w[i].size(); k++)
			{
				if(j>=w[i][k])
					f[i][j] = max(f[i][j], f[i-1][j - w[i][k]] + v[i][k]);
			}
		}
	}
	cout << f[maxg][m];
	return 0;
}

