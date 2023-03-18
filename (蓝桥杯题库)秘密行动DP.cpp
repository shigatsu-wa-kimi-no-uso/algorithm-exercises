#include<iostream>
#include<queue>
using namespace std;

//ÃØÃÜÐÐ¶¯

int n;

int a[10005];

int f[10005][2];

struct INFO
{
	int id;
	int t;
	bool flag;
	INFO(){}
	INFO(int id,int t,bool flag)
		:id(id),t(t),flag(flag){}
};


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	f[1][0] = a[1];
	for (int i = 2; i <= n; i++)
	{
		f[i][0] = min(f[i - 1][1] + a[i], f[i - 1][0] + a[i]);
		f[i][1] = min(f[i - 1][0], f[i - 2][0]);
	}
	cout << min(f[n][0], f[n][1]);
	return 0;
}

