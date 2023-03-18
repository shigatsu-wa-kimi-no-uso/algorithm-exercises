#include<iostream>
#include<deque>
using namespace std;

//P2251÷ ¡øºÏ≤‚ 


int n, m;

struct A
{
	int v;
	int id;
}a[1000005];

deque<A> desc;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].v;
		a[i].id = i;
	}

	for (int i = 1; i < m; i++)
	{
		while (1)
		{
			if(!desc.empty())
			{
				if (a[i].v >= desc.back().v)
				{
					desc.push_back(a[i]);
					break;
				}
				else desc.pop_back();
			}
			else
			{
				desc.push_back(a[i]);
				break;
			}
		}
	}
	for (int i = m; i <= n; i++)
	{
		while (1)
		{
			if (!desc.empty())
			{
				if (i - desc.front().id >= m)
				{
					desc.pop_front();
					continue;
				}

				if (a[i].v >= desc.back().v)
				{
					desc.push_back(a[i]);
					break;
				}
				else desc.pop_back();
			}
			else
			{
				desc.push_back(a[i]);
				break;
			}
		}
		cout << desc.front().v << '\n';
	}

	return 0;
}
