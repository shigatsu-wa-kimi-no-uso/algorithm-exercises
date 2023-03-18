#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

//P1020

int h[100005];
int d[100005];


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
	//最长不上升子序列 nlogn算法
	//定义数组d[i],记录最长不上升子序列长度为i时的最小末尾
	//即当扫描到h[j]时(j>5)，d[5]存储在[1,j)上能取得的不上升子序列长度为5的最小末尾
	//故数组d并非最长不上升子序列

	int len = 2;
	int* pos;
	d[1] = h[1];
	for (j = 2; j < i; j++)
	{
		pos = upper_bound(d + 1, d + len, h[j], greater<int>());	//查找第一个小于h[j]的位置 upper不带等于 lower带
		if (pos == d + len)	//没找到，都比h[j]大 ,长度增加
		{
			len++;
		}
		*pos = h[j];		//对应位置更新数据
	}
	cout << len - 1<< '\n';
	
	/*第二问思路（狄尔沃斯定理）
	（1）假设打导弹的方法是这样的：取任意一个导弹，从这个导弹开始将能打的导弹全部打完。而这些导弹全部记为为同一组，再在没打下来的导弹中任选一个重复上述步骤，直到打完所有导弹。

		（2）假设我们得到了最小划分的K组导弹，从第a(1 <= a <= K)组导弹中任取一个导弹，必定可以从a + 1组中找到一个导弹的高度比这个导弹高（因为假如找不到，那么它就是比a + 1组中任意一个导更高，在打第a组时应该会把a + 1组所有导弹一起打下而不是另归为第a + 1组），同样从a + 1组到a + 2组也是如此。那么就可以从前往后在每一组导弹中找一个更高的连起来，连成一条上升子序列，其长度即为K;

	（3）设最长上升子序列长度为P，则有K <= P; 又因为最长上升子序列中任意两个不在同一组内(否则不满足单调不升)，则有

		K >= P，所以K = P。
		*/
	
	len = 2;		//要写入位置为2，实际长度为1
	d[1] = h[1];
	for (j = 2; j < i; j++)
	{
		pos = lower_bound(d + 1, d + len, h[j], less<int>());	//查找第一个大于或等于h[j]的位置（上升序列，前后相等时不能加入序列）
		if (pos == d + len)	//没找到，都比h[j]大
		{
			len++;			//要写入的位置后移
		}
		*pos = h[j];		//对应位置更新数据
	}
	cout << len - 1<< '\n';
	
	return 0;
}
