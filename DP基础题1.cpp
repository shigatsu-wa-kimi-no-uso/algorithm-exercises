#include<iostream>
#include<algorithm>
#define reg register int
using namespace std;

//P1216 ����dp 
int a[1005][1005];
int dp[1005][1005]; 
/*����dp*/
/*dp[x][y]Ϊ�����x�е�y��ʱ�ĺͣ���֤dp[x][y]Ϊ��󣬾������Ŀ*/
/*dp[x][y]=a[x][y]+max(dp[x-1][y],dp[x-1][y-1])*/


int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (reg i = 1; i <= n; ++i)
	{
		for (reg j = 1; j <= i; ++j)
		{
			cin >> a[i][j];
		}
	}

	for (reg i = 1; i <= n; ++i)
	{
		for (reg j = 1; j <= i; ++j)
		{
			dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
		}
	}
	sort(dp[n], dp[n] + n+1, greater<int>());
	cout << dp[n][0];
	return 0;
}
