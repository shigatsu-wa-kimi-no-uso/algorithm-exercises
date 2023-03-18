#include<iostream>
#include<algorithm>
using namespace std;

int n, m;

char map[55][55];

int w[55], b[55], r[55];
int wb[55], bb[55], rb[55];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
			switch (map[i][j])
			{
			case 'W':
				w[i]++;
				break;
			case 'B':
				b[i]++;
				break;
			case 'R':
				r[i]++;
			}
		}
		wb[i+1] = w[i]+wb[i];
		bb[i+1] = b[i]+bb[i];
		rb[i+1] = r[i]+rb[i];
	}



	int res = 0x3f3f3f3f;
	//[1,i) W [i,j) B [j,n+1) R
	for (int i = 2; i < n; i++)
	{
		for (int j = 3; j <= n; j++)
		{
			res = min(res, bb[i] + rb[i] + wb[j] - wb[i] + rb[j] - rb[i] + wb[n + 1] - wb[j] + bb[n + 1] - bb[j]);
		}
	}
	cout << res;
	return 0;

}
