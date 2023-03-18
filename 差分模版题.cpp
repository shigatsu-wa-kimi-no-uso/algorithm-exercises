#include<iostream>
using namespace std;

//AT2442
//线段树/差分模版题 
long long D[200002];
int n, q, s, t, l, r, x;

inline long long temp(long long h)
{
	return h > 0 ? -s * h : -t * h;
}

int main()
{
	ios::sync_with_stdio(false);
	int pre,now;
	cin >> n >> q >> s >> t;
	cin >> now;
	D[0] = now;
	long long ans=0;
	for (register int i = 1; i <= n; ++i)
	{
		pre = now;
		cin >> now;
		D[i] =now-pre;	//差分数组
		ans += temp(D[i]);
	}
	for (register int i = 1; i <= q; ++i)
	{
		cin >> l >> r >> x;
		ans -= temp(D[l]);	//先把以前的减去
		D[l] += x;
		ans += temp(D[l]); //再加
		if (r < n)
		{
			ans -= temp(D[r + 1]);
			D[r + 1] -= x;
			ans += temp(D[r + 1]);
		}
		cout << ans<<'\n';
	}

	return 0;
}
