#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

//P1020

int h[100005];
int dp[100005];
int dp2[100005];


int main()
{
	int i = 1;
	char ch;
	do
	{
		scanf("%d", &h[i]);
		i++;
	} while ((ch = getchar()) != '\n' && ch != EOF);
	int j, k;
	//最长不上升子序列
	// 定义dp[k]为到第k个数据能与前面的数据组成的最长不上升子序列的长度
	//关系式：dp[k]=dp[i]+1  其中k为当前点，i为比k小且其对应值最接近k点对应值的点（即k<i且abs(v[k]-v[i])最小的点）
	
	dp[1] = 1;
	int f, m = 0;
	for (j = 2; j < i; j++)
	{
		f = 0;
		for (k = j - 1; k > 0; k--)
		{
			if (h[k] >= h[j])
			{
				f = max(f, dp[k]);
			}
		}
		dp[j] = f + 1;
		m = max(dp[j], m);
	}
	cout << m << '\n';
	/*第二问即求最长上升子序列 证明（狄尔沃斯定理）
	（1）假设打导弹的方法是这样的：取任意一个导弹，从这个导弹开始将能打的导弹全部打完。而这些导弹全部记为为同一组，再在没打下来的导弹中任选一个重复上述步骤，直到打完所有导弹。

		（2）假设我们得到了最小划分的K组导弹，从第a(1 <= a <= K)组导弹中任取一个导弹，必定可以从a + 1组中找到一个导弹的高度比这个导弹高（因为假如找不到，那么它就是比a + 1组中任意一个导更高，在打第a组时应该会把a + 1组所有导弹一起打下而不是另归为第a + 1组），同样从a + 1组到a + 2组也是如此。那么就可以从前往后在每一组导弹中找一个更高的连起来，连成一条上升子序列，其长度即为K;

	（3）设最长上升子序列长度为P，则有K <= P; 又因为最长上升子序列中任意两个不在同一组内(否则不满足单调不升)，则有

		K >= P，所以K = P。
		*/
	dp2[1] = 1;
	m = 0;
	for (j = 2; j < i; j++)
	{
		f = 0;
		for (k = j - 1; k > 0; k--)
		{
			if (h[k] < h[j])
			{
				f = max(f, dp2[k]);
			}
		}
		dp2[j] = f + 1;
		m = max(dp2[j], m);
	}
	cout << m;
	return 0;
}
