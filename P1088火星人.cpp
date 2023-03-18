#include<iostream>
using namespace std;

int n, m;

int arr[11111];
bool used[11111];

int cnt = 0;

string s;

bool start = 1;

void arrange(int id)
{

	for (int i = start ? arr[id] : 1; i <= n; i++)
	{
		if (!used[i])
		{
			arr[id] = i;
			used[arr[id]] = 1;
			if (id == n)
			{
				if (start) start = 0;
				else cnt++;
				used[arr[id]] = 0;
				return;
			}
			arrange(id + 1);
			used[arr[id]] = 0;
			if (cnt == m) return;
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	arrange(1);
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;

}
