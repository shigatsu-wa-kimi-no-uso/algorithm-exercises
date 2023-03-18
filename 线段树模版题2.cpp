#include<iostream>
#define MAXN 100004
#define reg register int
typedef long long ll;
using namespace std;

//P3373 线段树2
/*较难*/ 

ll n, m, p,op;
ll a[MAXN];
ll node[MAXN << 2], tag1[MAXN << 2], tag2[MAXN << 2];

inline int ls(int n)
{
	return n << 1;
}

inline int rs(int n)
{
	return n << 1 | 1;
}

void build(ll l, ll r, int n)
{
	tag1[n] = 1;
	if (l == r)
	{
		node[n] = a[l] % p;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls(n));
	build(mid + 1, r, rs(n));
	node[n] = (node[ls(n)] + node[rs(n)]) % p;
}


void tagcheck(int l, int r, int mid, int n)
{
	int lson = ls(n), rson = rs(n);
	node[lson] = (node[lson] * tag1[n]) %p;
	node[rson] = (node[rson] * tag1[n]) %p;
	tag1[lson] = (tag1[lson] * tag1[n]) % p;
	tag1[rson] = (tag1[rson] * tag1[n]) % p;
	node[lson] = (node[lson] + (mid - l + 1) * tag2[n]) % p;
	node[rson] = (node[rson] + (r - mid) * tag2[n]) % p;
	tag2[lson] = (tag2[lson] * tag1[n]+ tag2[n]) % p;		//坑 上面的标签乘下来时  要把以前的也乘一下 
	tag2[rson] = (tag2[rson] * tag1[n] + tag2[n]) % p;
	tag1[n] = 1;
	tag2[n] = 0;
}

void update(int x, int y, int l, int r, int n, int k)
{
	if (x <= l && y >= r)
	{
		if (op == 1)
		{
			node[n] = (node[n] * k) % p;
			tag1[n] = (tag1[n] * k) % p;
			tag2[n] = (tag2[n] * k) % p;		//操作包含乘和加，在乘的时候，以前加的值也要乘 
		}
		else
		{
			node[n] = (node[n] + (r - l + 1) * k) % p;
			tag2[n] = (tag2[n] + k) % p;
		}
		return;
	}
	int mid = (l + r) >> 1;
	tagcheck(l, r, mid, n);
	if (x <= mid) update(x, y, l, mid, ls(n), k);
	if (y > mid) update(x, y, mid + 1, r, rs(n), k);
	node[n] = (node[ls(n)] + node[rs(n)]) % p;
}

ll query(int x, int y, int l, int r, int n)
{
	ll ans = 0;
	if (x <= l && y >= r)
	{
		return node[n];
	}
	int mid = (l + r) >> 1;
	tagcheck(l, r, mid, n);
	if (x <= mid) ans+=query(x, y, l, mid, ls(n));
	if (y > mid) ans+=query(x, y, mid + 1, r, rs(n));
	return ans % p;
}


int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> p;
	for (reg i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	build(1, n, 1);
	int x, y, k;
	for (reg i = 1; i <= m; ++i)
	{
		cin >> op;
		switch (op)
		{
		case 1:
		case 2:
			cin >> x >> y >> k;
			update(x, y, 1, n, 1, k);
			break;
		case 3:
			cin >> x >> y;
			cout<<query(x, y, 1, n, 1)<<'\n';
		}
	}
	return 0;
}
