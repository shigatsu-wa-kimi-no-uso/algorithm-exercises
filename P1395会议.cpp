#include <iostream>
#include <vector>
using namespace std;

//P1395 ����

vector<int> e[50005];

int n;

void link(int x, int y)
{
    e[x].push_back(y);
    e[y].push_back(x);
}

int ans;

int dep[50005];

int g=0x3fffffff;

int sum=0x3fffffff;

int dfsgetG(int now, int fa)
{
    int sz = 1;        //�ýڵ���ͬ�Լ���������С
    int sonsz = 0, t = 0;
    for (int i = 0; i < e[now].size(); i++)
    {
        if (e[now][i] == fa) continue;
        sonsz = dfsgetG(e[now][i], now);    
        t = max(sonsz, t);  //�������
        sz += sonsz;
    }
    t = max(t, n - sz);  //�������Ϊ��ʱ�����������С
    if (t < sum ||( (t == sum) && now < g))     //�����ж�
    {
        sum = t;
        g = now;
    }
    return sz;
}


void dfsgetdep(int now, int fa)
{
    dep[now] = dep[fa] + 1;
    ans += dep[now];
    for (int i = 0; i < e[now].size(); i++)
    {
        if (e[now][i] == fa) continue;
        dfsgetdep(e[now][i], now);
    }
}

int main()
{
    cin >> n;
    int x, y;
    for (int i = 1; i <= n-1; i++)
    {
        cin >> x >> y;
        link(x, y);
    }
    dfsgetG(1, 1);
    dep[g] = -1;
    dfsgetdep(g, g);
    cout << g << " " << ans;
    return 0;
}

