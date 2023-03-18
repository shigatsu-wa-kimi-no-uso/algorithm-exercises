#include<iostream>
#define reg register int
typedef long long ll;
using namespace std;


//P3372 ģ���� �߶���1

ll m, n;
ll sums[400004];	
ll a[100001];
ll dat,aiml,aimr;
ll tag[400004];
/*btree*/
/*btree���ʣ����ѽڵ㣨�����ϣ����ϵ��£��������Ҵ�1��ţ���ڵ�x�������Ϊ2x���Ҷ���Ϊ2x+1������Ϊ[x/2]*/
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

/*����������*/
void build(int x,ll l,ll r)		//Ҫд��Ľڵ�x���������l���ҽ�r //��x==1 l==1 r==n��ʼ�ݹ�
{
	if (l == r)	//�������ٷָ�ʱ
	{
		sums[x] = a[l];
		return;
	}
	ll mid = (l + r) >> 1;
	build(ls(x), l, mid);
	build(rs(x), mid + 1, r);
	/*���ݴ���push_up*/
	sums[x] = sums[ls(x)] + sums[rs(x)];
}

inline void write(int x, ll l, ll r, ll k)
{
	tag[x] += k;	//�����ǩ����¼�ڵ�x������������k������ӽڵ�δ��������
	sums[x] += k * (r - l + 1); //�޸Ľڵ�ֵ
}

inline void push_down(int x, ll l, ll r)	//���´����޸��������Ϣ(����)
{
	ll mid = (l + r) >> 1;
	write(ls(x), l, mid,tag[x]);	//tag[x]:���״��������ۼƱ仯ֵ
	write(rs(x), mid + 1, r,tag[x]);
	tag[x] = 0;//���׵ı�ǩ��Ϊ0
}


/*�޸�*//*˼�룺�ҵ�Ŀ���޸��������ȫƥ�������ڵ㣬�漰������ڵ㣬�����޸ģ�
	  �������޸Ķ��ӡ�����ֻ�޸�ֱ���漰������ڵ�
	  ����´��޸��漰�����ӽڵ㣬�򵽴��ӽڵ�󣬻ᴫ�ݸ��׵ı�ǩ������ʱ�����
	  ���ϴε�һ���޸�*/
void update(ll aiml, ll aimr, int x,ll l, ll r, ll k)
{
	if (aiml <= l && r <= aimr)	//Ҫ�޸ĵ�������ȫƥ��ڵ�������䣬�����޸Ĳ��������ǩ
								//[aiml,aimr]����[l,r]ʱ���䳬�����ֻ���������������˴���
	{
		sums[x] += k * (r - l + 1);
		tag[x] += k;
		return;
	}
	/*������ȫ�������*/
	if(tag[x])
		push_down(x,l,r);		//���ݸ��׵ı�ǩ���Ա����֮ǰ�������޸�
	ll mid = (l + r) >> 1;
	/*Ҫ�޸ĵ������漰�����,��������ӵ����*/
	if (aiml <= mid) update(aiml,aimr, ls(x),l, mid, k);
	/*Ҫ�޸ĵ������漰�Ҷ��ӣ������Ҷ��ӵ����*/
	if (aimr > mid) update(aiml, aimr, rs(x), mid+1, r, k);
	/*���ݴ���*/
	sums[x] = sums[ls(x)] + sums[rs(x)];//���½ڵ���������ֵ
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
		push_down(n, l, r); //Ҫ����ˣ�������û�мӵ�ֵ
	//�漰�����
	if (x <= mid) ans += query(x, y, ls(n), l, mid);
	//�漰�Ҷ���
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
