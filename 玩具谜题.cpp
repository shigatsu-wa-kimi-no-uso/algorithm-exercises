#include<iostream>
using namespace std;

int n, m;

int p[100005];
string name[100005];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i] >> name[i];
	}
	int a, b;
	int curr = 1;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		if (p[curr]!=a)
		{
			curr += b;
			if (curr > n) curr %= n;
		}
		else
		{
			curr -= b;
			if (curr < 1) curr = n + curr + ((-curr) / n) * n;
		}
	}
	cout << name[curr];
	return 0;

}
