#include<iostream>
#define reg register int
typedef long long ll;
using namespace std;


//P3372 模版题 线段树1

ll m, n;
ll sums[400004];	
ll a[100001];
ll dat,aiml,aimr;
ll tag[400004];
/*btree*/
/*btree性质：若把节点（根在上）从上到下，从左往右从1标号，则节点x的左儿子为2x，右儿子为2x+1，父亲为[x/2]*/
// sums[1]==[1,n]
// sums[2]==[1,(n+1)/2]
// sums[3]==[(n+1)/2+1,n]
// sums[4]==[1,(n+3)/4]
// sums[5]==[(n+3)/4,(n+1)/2]
// sums[6]==[(n+1)/2+1,(3n+3)/4]
// sums[7]==[(3n+3)/4+1,n]
// sums[8]==[1,n/8]
// ...
// sums[n/2]==[1,2]
// sums[n/2+1]==[3,4]
// sums[n]==[1,1]
// sums[n+1]==[2,2]
// sums[n+2]==[3,3]
// ...
// sums[n+n]==[n,n]
//

inline int ls(int x)
{
	return x << 1;
}

inline int rs(int x)
{
	return x << 1 | 1;
}

/*二叉树建立*/
void build(int x,ll l,ll r)		//要写入的节点x，区间左界l，右界r //从x==1 l==1 r==n开始递归
{
	if (l == r)	//当不可再分割时
	{
		sums[x] = a[l];
		return;
	}
	ll mid = (l + r) >> 1;
	build(ls(x), l, mid);
	build(rs(x), mid + 1, r);
	/*回溯代码push_up*/
	sums[x] = sums[ls(x)] + sums[rs(x)];
}

inline void write(int x, ll l, ll r, ll k)
{
	tag[x] += k;	//懒惰标签，记录节点x的区间增加了k，其儿子节点未真正增加
	sums[x] += k * (r - l + 1); //修改节点值
}

inline void push_down(int x, ll l, ll r)	//向下传递修改区间的信息(下推)
{
	ll mid = (l + r) >> 1;
	write(ls(x), l, mid,tag[x]);	//tag[x]:父亲传过来的累计变化值
	write(rs(x), mid + 1, r,tag[x]);
	tag[x] = 0;//父亲的标签设为0
}


/*修改*//*思想：找到目标修改区间的完全匹配的区间节点，涉及的区间节点，进行修改，
	  但不再修改儿子。即：只修改直接涉及的区间节点
	  如果下次修改涉及到其子节点，则到达子节点后，会传递父亲的标签，即到时候会连
	  带上次的一起修改*/
void update(ll aiml, ll aimr, int x,ll l, ll r, ll k)
{
	if (aiml <= l && r <= aimr)	//要修改的区间完全匹配节点代表区间，进行修改并贴懒惰标签
								//[aiml,aimr]超过[l,r]时，其超过部分会在其他区间进行了处理
	{
		sums[x] += k * (r - l + 1);
		tag[x] += k;
		return;
	}
	/*不能完全覆盖情况*/
	if(tag[x])
		push_down(x,l,r);		//传递父亲的标签，以便完成之前的区间修改
	ll mid = (l + r) >> 1;
	/*要修改的区间涉及左儿子,看看左儿子的情况*/
	if (aiml <= mid) update(aiml,aimr, ls(x),l, mid, k);
	/*要修改的区间涉及右儿子，看看右儿子的情况*/
	if (aimr > mid) update(aiml, aimr, rs(x), mid+1, r, k);
	/*回溯代码*/
	sums[x] = sums[ls(x)] + sums[rs(x)];//更新节点代表区间的值
}

ll query(ll x, ll y,int n, ll l, ll r)
{
	ll ans=0;
	if (x <= l && r <= y)
	{
		return sums[n];
	}
	ll mid = (l + r) >> 1;
	if(tag[n])
		push_down(n, l, r); //要输出了，处理下没有加的值
	//涉及左儿子
	if (x <= mid) ans += query(x, y, ls(n), l, mid);
	//涉及右儿子
	if (y > mid) ans += query(x, y, rs(n), mid + 1, r);
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (reg i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	int op, x, y;
	ll k;
	build(1, 1, n);
	for (reg i = 1; i <= m; ++i)
	{
		cin >> op;
		switch(op)
		{

		case 1:
			cin >> x >> y >> k;
			update(x, y,1, 1, n, k);
			break;
		case 2:	
			cin >> x >> y;
			cout<<query(x, y, 1, 1, n)<<'\n';
		}
	}
	return 0;
}
