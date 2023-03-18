#include<iostream>
#include<map>
using namespace std;

//P2814����

map<string,int> cast;

string caststr[50005];

int fa[50005];

int getfa(int x)
{
	if (fa[x] == 0 || fa[x] == x)
		return x;
	return fa[x] = getfa(fa[x]);
}

void merge(int x, int y)
{
	fa[y] = getfa(x);
}

int main()
{
	string t;
	int id = 1;
	int faID = 0;
	bool isover = 0;
	while (!isover)
	{
		cin >> t;
		switch (t[0])
		{
		case '#':
			if (cast.find(t.substr(1)) == cast.end())
			{
				cast[t.substr(1)] = id;
				caststr[id] = t.substr(1);
				fa[id] = getfa(id);
				faID = id;
				id++;
			}
			else
			{
				faID = cast[t.substr(1)];
			}
			break;
		case '+':
			if (cast.find(t.substr(1)) == cast.end())
			{
				cast[t.substr(1)] = id;
				caststr[id] = t.substr(1);
				merge(faID, id);
				id++;
			}
			else
			{
				merge(faID, cast[t.substr(1)]);
			}
			break;
		case '?':
			cout << t.substr(1) << " " << caststr[getfa(cast[t.substr(1)])] << "\n";
			//ע�⣺��ѯʱʹ��getfa������fa[]����Ϊ�������������Ѿ��ı���ǰ���fa
			break;
		case '$':
			isover = 1;
			break;
		}
	}
	return 0;
}
