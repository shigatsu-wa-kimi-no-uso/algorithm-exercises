#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n;

//P1219 八皇后问题
//深搜, 回溯（试探法）

bool r[15], l[15], d1[40],d2[40];		
int pos[15];
int ans;

void dfs(int y)
{
//	bool flag = 0;
	//cout << "line " << y << '\n';
	for (int i = 1; i <= n; i++)
	{
		//cout << "try " << i<<'\n';
		if (r[y] == 0 && l[i] == 0 && d1[i - y + n] == 0 && d2[i + y] == 0)		//如果没有被占用，进入
		{
		//	cout << "ok\n";
			r[y] = 1;			//预设第y行被占用
			l[i] = 1;			//预设
			d1[i - y + n] = 1;	//d1[i-y+n]存储点(y,i)所在的主对角线的占用情况,同一条主对角线上 y-x的值固定
			d2[i + y] = 1;		//d2[i+y]存储点(y,i)所在的副对角线的占用情况,同一条副对角线上 y+x值固定
			//flag = 1;		//标记这一行有可放置的点，后续返回true
			pos[y] = i;		//记录y坐标位置是i
			if (y != n)
			{
			//	cout << "goto line" << y + 1 << '\n';
				dfs(y + 1);
				/*
				if (dfs(y + 1))						//看下一行的情况
				{
					cout << "retok:" << y + 1 << '\n';
				}
				cout << "rettoline:" << y << '\n';
				*/
			}
			else
			{
				ans++;					//能放到最后一行，答案数+1
				if (ans <= 3)
				{
					for_each(pos + 1, pos + n + 1, [](int& x) {cout << x << " "; });
					cout << '\n';
				}
	//			return true;
			}
			r[y] = 0;
			l[i] = 0;			//返回时恢复占用状态，再选一个点
			d1[i - y + n] = 0;
			d2[i + y] = 0;
		}
	}
/*
	if (flag)
	{
		cout << "retok:" << y << '\n';
		return true;
	}
	else
	{
		cout << "retfailed:" << y << '\n';
		return false;
	}
	*/

}


int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	bool flag1 = 0;
	for (int i = 1; i <= n; i++)
	{
		r[1] = 1;
		l[i] = 1;
		pos[1] = i;
		d1[i - 1 + n] = 1;
		d2[i + 1] = 1;
		//cout << '\n';
		//cout << '\n';
		//cout << "TRY: " << i<<'\n';
		dfs(2);
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		memset(d1, 0, sizeof(d1));
		memset(d2, 0, sizeof(d2));
		
	}
	cout << ans;
	return 0;

}
