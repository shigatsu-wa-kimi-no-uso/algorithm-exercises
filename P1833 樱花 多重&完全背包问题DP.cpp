#include<iostream>
using namespace std;

//P1833 樱花 多重/完全混合背包DP

int T;

struct TIME
{
	int h;
	int m;
	int operator-(const TIME &rgt) const
	{
		if (m - rgt.m >= 0)
		{
			return m - rgt.m + (h - rgt.h) * 60;
		}
		else
		{
			return 60 + m - rgt.m + (h - rgt.h - 1) * 60;
		}
	}
	friend istream& operator>>(istream&, TIME& t)
	{
		cin >> t.h;
		getchar();
		cin >> t.m;
		return cin;
	}


}ts,te;

int n;

int v[10005], t[10005], p[10005];

int f[2][1005];

int main()
{
	cin >> ts >> te >> n;
	T = te - ts;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> v[i] >> p[i];
	}
	int id = 1;
	for (int i = 1; i <= n; i++)
	{
		if (p[i] == 0)
		{
			for (int j = 1; j <= T; j++)
			{
				if (j >= t[i])
				{
					f[id%2][j] = max(f[(id - 1)%2][j], f[id%2][j - t[i]] + v[i]);
				}
				else
				{
					f[id%2][j] = f[(id - 1)%2][j];
				}
			}
			id++;
		}
		else
		{
			for (int k = 1; k <= p[i]; k++)
			{
				for (int j = 1; j <= T; j++)
				{
					if (j >= t[i])
					{
						f[id % 2][j] = max(f[(id - 1) % 2][j], f[(id - 1) % 2][j - t[i]] + v[i]);
					}
					else
					{
						f[id%2][j] = f[(id - 1)%2][j];
					}
				}
				id++;
			}		
		}
	}
	/*
	for (int i = 1; i < id; i++)
	{
		for (int j = 1; j <= T; j++)
		{
			cout << f[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << f[(id - 1) % 2][T];
	return 0;


}

