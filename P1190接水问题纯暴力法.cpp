#include<iostream>
#include<list>
#include<algorithm>
#define reg register int
using namespace std;

int n, m;
int a[10005];
bool idle[10005];

//P1190 ��ˮ����
//����ģ�ⷨ

list<int> index;	

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	long long s = 0;
	for (reg i = 1; i <= n; i++)
	{
		cin >> a[i];
		s += a[i];
	}

	int cnt = 1;
	int ans = 0;
	
	do
	{
		ans++;
		for (reg i = index.size(); i < m; i++)			//װ��
		{
			if (cnt <= n)
			{
			//	cout << a[cnt + 1] << " in list\n";
				index.push_back(a[cnt++]);
			}
		}
	//	cout << "\nok\n";
		index.sort(greater<int>());

		for (int &var : index)
		{
			var--;
			s--;
		}
		index.remove(0);			//�Ƴ�����Ϊ0��Ԫ��

	} while (s);	//���� ����ʹ��empty�жϣ����ֻ��һ��ˮ��ͷ��������ʼ��Ϊ ��1 ��empty֮�� ����� 

	cout << ans;
	return 0;

}
