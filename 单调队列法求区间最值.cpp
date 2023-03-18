#include<iostream>
#include<queue>
#include<utility>
#include<cmath>

using namespace std;

int a[(int)2E6 + 1];

struct elem
{
	int val;
	int index;
};

deque<elem> intvl;	//单调队列,保证最小值在前,最大值在后

//P1440

int main()
{
	int n, m,i,j;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cout << "0\n";
	for (i = 2; i <= n; i++)//区间 [i-m,i-1]
	{
		if (!intvl.empty())		//区间队列不为空
		{
			if (intvl.front().index < i - m ) //区间队列中，最先进如的那个下表已经超过区间左边界就弹出
				intvl.pop_front();
		}
		while ( !intvl.empty() && a[i - 1] < intvl.back().val) //a[i]进队,保证在正确的位置,以保证单调性
		{
			intvl.pop_back();		//把比a[i]大的元素弹出来
		}
		intvl.push_back({ a[i-1],i-1 });
		cout << intvl.front().val<<"\n";
	}
	return 0;


}
