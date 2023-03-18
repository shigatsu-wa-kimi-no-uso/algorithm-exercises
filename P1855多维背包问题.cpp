#include<iostream>
#include<algorithm>
using namespace std;


//P1855 Õ¥È¡kkksc03 ¶àÎ¬±³°ü

int n, M, T;

int t[105], m[105];


int f[105][205][205];


int main()
{
	cin >> n >> M >> T;
	for (int i = 1; i <= n; i++)
	{
		cin >> m[i] >> t[i];
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (j >= m[i])
			{
				for (int k = 1; k <= T; k++)
				{
					if (k >= t[i])
					{
						f[i][j][k] = max(f[i - 1][j - m[i]][k - t[i]] + 1, f[i - 1][j][k]);
					}
					else f[i][j][k] = f[i - 1][j][k];
				}
			}
			else for (int k = 1; k <= T; k++)
			{
				f[i][j][k] = f[i - 1][j][k];
			}
		}
	}
	cout << f[n][M][T];

	return 0;
}
