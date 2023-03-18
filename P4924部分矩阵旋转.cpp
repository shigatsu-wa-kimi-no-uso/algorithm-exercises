#include<iostream>

using namespace std;

int n, m;

int a[555][555];

void clockwise(int x, int y, int r)
{
	int d = (r - 1) / 2;
	int lr = x - d, lc = y - d;
	for (int i = 0; i <= r - 1; i++)
	{
		for (int k = 1 + i; k <= r - 1; k++)
		{
			swap(a[lr + i][lc + k], a[lr + k][lc + i]);
		}
	}

	for (int i = lc; i < y; i++)
	{
		for (int j = lr; j <= x + d; j++)
		{
			swap(a[j][i], a[j][2 * y - i]);
		}
	}
}

void anti_clockwise(int x, int y, int r)
{
	int d = (r - 1) / 2;
	int lr = x - d, lc = y - d;
	for (int i = 0; i <= r - 1; i++)
	{
		for (int k = 1 + i; k <= r - 1; k++)
		{
			swap(a[lr + i][lc + k], a[lr + k][lc + i]);
		}
	}

	for (int i = lr; i < x; i++)
	{
		for (int j = lc; j <= y + d; j++)
		{
			swap(a[i][j], a[2 * x - i][j]);
		}
	}
}



int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = n * (i - 1) + j;
		}
	}

	int x, y, r, z;

	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y >> r >> z;
		if (z == 0)
			clockwise(x, y, 2 * r + 1);
		else if (z == 1)
			anti_clockwise(x, y, 2 * r + 1);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d ", a[i][j]);
		}
		cout << "\n";
	}
	return 0;
}
