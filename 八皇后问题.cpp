#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n;

//P1219 �˻ʺ�����
//����, ���ݣ���̽����

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
		if (r[y] == 0 && l[i] == 0 && d1[i - y + n] == 0 && d2[i + y] == 0)		//���û�б�ռ�ã�����
		{
		//	cout << "ok\n";
			r[y] = 1;			//Ԥ���y�б�ռ��
			l[i] = 1;			//Ԥ��
			d1[i - y + n] = 1;	//d1[i-y+n]�洢��(y,i)���ڵ����Խ��ߵ�ռ�����,ͬһ�����Խ����� y-x��ֵ�̶�
			d2[i + y] = 1;		//d2[i+y]�洢��(y,i)���ڵĸ��Խ��ߵ�ռ�����,ͬһ�����Խ����� y+xֵ�̶�
			//flag = 1;		//�����һ���пɷ��õĵ㣬��������true
			pos[y] = i;		//��¼y����λ����i
			if (y != n)
			{
			//	cout << "goto line" << y + 1 << '\n';
				dfs(y + 1);
				/*
				if (dfs(y + 1))						//����һ�е����
				{
					cout << "retok:" << y + 1 << '\n';
				}
				cout << "rettoline:" << y << '\n';
				*/
			}
			else
			{
				ans++;					//�ܷŵ����һ�У�����+1
				if (ans <= 3)
				{
					for_each(pos + 1, pos + n + 1, [](int& x) {cout << x << " "; });
					cout << '\n';
				}
	//			return true;
			}
			r[y] = 0;
			l[i] = 0;			//����ʱ�ָ�ռ��״̬����ѡһ����
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
