#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int a[(int)2E6+1];
vector<int> dp[(int)2E6 + 1];

//P1440
int main()
{
	int n, m,i,j,t;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (i = 0; i <= n; i++)
	{
		dp[i].push_back(a[i]);		//dp[i][0]为区间[i-0,i]上的最小值
	}
	//ST 
	int idx = log(m) / log(2);			//dp[i][j]=
	for (j = 1; j <= idx; j++)
	{
		for (i = n; i >= 0; i--)
		{
			t = i-pow(2,j-1);
			if (t > 0) dp[i].push_back(min(dp[t][j-1], dp[i][j - 1]));
			else dp[i].push_back(dp[i][j - 1]);		//dp[i][j]为 区间[i-2^j+1,i]上的最小值,共2^j个
		}
	}
	if (m & (m - 1))
	{
		for (i = 0; i < n; i++)
		{
			t = i - m + pow(2, idx);
			if (t > 0)
				cout << min(dp[i][idx], dp[t][idx]) << "\n"; //第i+1项的前m个,即区间[i-m+1,i],即min( [i-2^idx+1,i] , [i-m+1+2^idx-1-2^idx+1,i-m+1+2^idx-1] ) 即min(dp[i][idx],dp[i-m+2^idx][idx]) 
			else
				cout << dp[i][idx]<<"\n";
		}
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			cout << dp[i][idx] <<"\n";
		}
	}
	return 0;


}
