#include<iostream>
#include<queue>
using namespace std;

int n[102];
queue<pair<int, int>> pr;
priority_queue<int, vector<int>, less<int>> rankedpr;

//UVA12100

int main()
{
	ios::sync_with_stdio(false);
	int T, n, m, i,j,p;
	cin >> T;
	for (i = 1; i <= T; ++i)
	{
		cin >> n >> m;
		for (j = 0; j < n; ++j)
		{
			cin >> p;
			pr.push(make_pair(p,j));			//原始的
			rankedpr.push(p);			//排序的
		}
		int t=0;
		while (1)
		{
			if (pr.front().first != rankedpr.top())
			{
				pr.push(pr.front());
				pr.pop();
			}
			else
			{	
				++t;
				if (pr.front().second == m)
				{
					cout << t<<'\n';
					break;
				}
				pr.pop();
				rankedpr.pop();
			}
		}
		pr = queue<pair<int, int>>();
		rankedpr = priority_queue<int, vector<int>, less<int>>();
	}
	return 0;
}
