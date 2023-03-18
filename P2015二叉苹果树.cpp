#include <iostream>
#include <vector>
using namespace std;

//P2015 ����ƻ���� ����DP

int n, q;

int f[105][105];

struct EDGE
{
    int to;
    int w;
    EDGE(int to, int w)
        :to(to), w(w){}
};

struct NODE
{
    int ls, lsw;
    int rs, rsw;
}p[105];

vector<EDGE> e[105];

void link(int x, int y,int z)
{
    e[x].push_back(EDGE(y,z));
    e[y].push_back(EDGE(x,z));
}

void build(int now,int nowfa)
{
    int cnt = 0;
    for (int i = 0; i < e[now].size(); i++)
    {
        if (e[now][i].to == nowfa) continue;
        if (cnt)
        {
            p[now].rs = e[now][i].to;
            p[now].rsw = e[now][i].w;
            build(p[now].rs, now);
        }
        else
        {
            p[now].ls = e[now][i].to;
            p[now].lsw = e[now][i].w;
            build(p[now].ls, now);
            cnt++;
        }
    }
}


int dfs(int now,int j)  //����ڵ��е�֦��  dfs����֦��
{
    if (j == 0 || now == 0) return 0;
    if (p[now].ls == 0) return 0;
    if (f[now][j]) return f[now][j];
    f[now][j] = max(f[now][j], dfs(p[now].ls, j - 1) + p[now].lsw); //֦��ѡ��ȫ��������� 
    f[now][j] = max(f[now][j], dfs(p[now].rs, j - 1) + p[now].rsw);
    for (int k = 1; k < j; k++)    //ö�ٸ�����ӱ���
    {
        f[now][j] = max(f[now][j], dfs(p[now].ls, k - 1) + dfs(p[now].rs, j - k - 1) + p[now].lsw + p[now].rsw);
    }
    return f[now][j];
}

int main()
{
    cin >> n >> q;
    int x, y, z;
    for (int i = 1; i <= n-1; i++)
    {
        cin >> x >> y >> z;
        link(x, y, z);
    }
    build(1, 1);
    cout << dfs(1, q);

    return 0;
}

