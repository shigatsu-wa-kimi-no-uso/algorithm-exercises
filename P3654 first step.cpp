#include<iostream>
#include<algorithm>
using namespace std;

int n, m, k;

char map[111][111];


int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin >> map[i][j];
		}
	}
	int len = 0, res=0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j] == '.')
			{
				len++;
			}
			if(map[i][j]=='#' || j==m)
			{
				if (len >= k)
				{
					res += len - k + 1;
				}
				len = 0;
			}
		}
	}

	if(k>1)
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (map[j][i] == '.')
				{
					len++;
				}
				if (map[j][i] == '#' || j == n)
				{
					if (len >= k)
					{
						res += len - k + 1;
					}
					len = 0;
				}
			}
		}
	cout << res;
	return 0;

}
