#include<iostream>
using namespace std;

//P5836 Milk Visits S
//���鼯�Ż���ѯ·���ϵ�ֵ 

int n, m;

char node[100005];

int fa[100005];

int x,y;
char t;

int getfa(int x)
{
	if (fa[x] == x) return x;
	else return fa[x]=getfa(fa[x]);
}

void merge(int x, int y)
{
	fa[getfa(y)] = getfa(x);
}

int main(int argc, char** argv)
{
	cin >> n >> m;
	cin >> (node + 1);
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}

	for (int i = 1; i <= n-1; i++)
	{
		cin >> x >> y;
		if(node[x]==node[y])	//���ڵ�ֵ��ͬ���ϲ�
			//֮ǰӵ����ͬ��ֵ�Ľڵ��Ѿ��ϲ������Ա�֤ԭʼ������һ��·����ֵ��ͬʱ���ϲ�Ϊ���׺Ͷ��������ڵ�
			merge(x, y);
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		cin >> t;
		if (getfa(x) ==getfa(y) && t != node[x]) cout << 0;
		else cout << 1;
		//���Ѿ��ϲ���������ĸ�����ͬ˵��ԭʼ��������·���ϵ�ֵ����ͬ
		// ����Ϊ����һ�����ϵ�ֵ�����ڲ�ѯֵt ������ԭʼ��������·����û����t��ȵĵ�
		//����˵����
	}

	return 0;
}

