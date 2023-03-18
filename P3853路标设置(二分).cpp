#include<iostream>
using namespace std;

int l, n, k;

//P3853路标设置 (二分)

bool s[10000005];

int check(int dis)
{
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i <= l; i++)
	{
		if (s[i])
		{
			sum = 0;
		}
		if (dis == sum)
		{
			cnt++;
			sum = 0;
		}
		sum++;
	}
	return cnt;
}

int main()
{
	cin >> l >> n >> k;
	int x;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		s[x] = 1;
	}
	int lb=0, ub=l, mid;
	while (lb <= ub)
	{
		mid = (lb + ub) / 2;
		if (check(mid) > k)
		{
			lb = mid + 1;
		}
		else
		{
			ub = mid - 1;
		}
	}
	cout << lb;
	return 0;
}
