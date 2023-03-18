#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> index, hashmap;

hashmap map[10001];

inline int hashfunc(int k,int M)
{
	return k % M;
}


int main()
{
	int val[10001],n,i,x;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> val[i];
		map[hashfunc(val[i],n)].push_back(i);	//map[哈希值][i] 对应下标值 i取冲突链表
	}
	cin >> x;
	int x_hash = hashfunc(x, n);
	for (i = 0; i < map[x_hash].size(); ++i)
	{
		if (x == val[map[x_hash][i]])
		{
			cout << map[x_hash][i];
			break;
		}
	}
	if (i == map[x_hash].size()) cout << -1;


	return 0;

}
