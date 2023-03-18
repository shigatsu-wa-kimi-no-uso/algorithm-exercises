#include<iostream>
#include<vector>
using namespace std;

vector<int> g[20];

inline void link(int x, int y)  //����x--->y	 y=g[i][x]��Ϊiָ��x�ĵ�i����
{
	g[x].push_back(y);
}

int depth[20] = { 0 }, father[20];
int lca(int x, int y) //��x��y�������������
{
	while (father[x] != father[y])
	{
		depth[x] > depth[y] ? x = father[x] : y = father[y];
	}
	return father[x];
}

int main()
{
	link(1, 0);
	link(4, 0);
	link(5, 0);
	link(2, 1);
	link(3, 1);
	link(6, 5);
	link(7, 5);
	link(8, 5);
	link(9, 7);
	
	int i,curr;
	/*dfs*/
	for (i = 0; i < 10; i++)		//��ÿ�������Ⱥ͸���  
	{
		curr = i;
		while (!g[curr].empty())	//���жϣ���û�и��ף�
		{
			father[curr] = g[curr][0];	//i��ֱϵ������g[i][0]
			curr = g[curr][0];   //currָ���ף�������Ҫ�ǿ����
			depth[i]++;				//i�����+1
		}
	}
	cout << lca(6, 9);

}
