#include<iostream>
#define MAXN (int)5E3
#define reg register int

using namespace std;

//P1007独木桥

int l, N;

int main()
{
	ios::sync_with_stdio(false);
	cin >> l >> N;
	int pos;
	int mid = l / 2;
	int delta = 0, delta2 = 0;
	for (reg i = 1; i <= N; i++)
	{
		cin >> pos;
		delta = max(delta, min(pos - 0, l + 1 - pos));	//取得离独木桥出口最远的点的位置
		delta2 = max(delta2, max(pos - 0, l + 1 - pos));	//取得离独木桥出口最近的点的位置
	}
	cout << delta << " " << delta2;
	return 0;
}
