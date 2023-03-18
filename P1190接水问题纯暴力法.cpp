#include<iostream>
#include<list>
#include<algorithm>
#define reg register int
using namespace std;

int n, m;
int a[10005];
bool idle[10005];

//P1190 接水问题
//暴力模拟法

list<int> index;	

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	long long s = 0;
	for (reg i = 1; i <= n; i++)
	{
		cin >> a[i];
		s += a[i];
	}

	int cnt = 1;
	int ans = 0;
	
	do
	{
		ans++;
		for (reg i = index.size(); i < m; i++)			//装载
		{
			if (cnt <= n)
			{
			//	cout << a[cnt + 1] << " in list\n";
				index.push_back(a[cnt++]);
			}
		}
	//	cout << "\nok\n";
		index.sort(greater<int>());

		for (int &var : index)
		{
			var--;
			s--;
		}
		index.remove(0);			//移除所有为0的元素

	} while (s);	//！坑 不能使用empty判断，如果只有一个水龙头，链表中始终为 有1 和empty之间 会出错 

	cout << ans;
	return 0;

}
