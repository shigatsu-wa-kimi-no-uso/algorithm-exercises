#include<iostream>
#define MAXN (int)5E3
#define reg register int

using namespace std;

//P1007��ľ��

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
		delta = max(delta, min(pos - 0, l + 1 - pos));	//ȡ�����ľ�ų�����Զ�ĵ��λ��
		delta2 = max(delta2, max(pos - 0, l + 1 - pos));	//ȡ�����ľ�ų�������ĵ��λ��
	}
	cout << delta << " " << delta2;
	return 0;
}
