#include<iostream>
#include<climits>
using namespace std;

int n, m;

int a[100005];

bool check(long long maxn)
{
	int cnt = 0;
	long long sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += a[i];
		if (sum > maxn)
		{
			cnt++;
			sum = a[i];
		}
	}
	return cnt > m-1;
}


int main()
{
	cin >> n >> m;
	long long lb = 1, rb = 0, mid;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		rb += a[i];
		lb = max(lb,(long long) a[i]);
	}
	while (lb <= rb)
	{
		mid = (lb + rb) / 2;
		if (check(mid))
			lb = mid + 1;
		else
			rb = mid - 1;
	}
	cout << lb;
	return 0;
}
