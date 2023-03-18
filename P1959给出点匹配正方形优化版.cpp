#include<iostream>
#include<algorithm>
#define reg register int
using namespace std;

//P1959 给出点匹配正方形
//利用几何信息+ 记忆化 

struct POINT
{
	int x, y;
	POINT() {};
	POINT(int x, int y)
		:x(x), y(y) {}
};

struct VECTOR
{
	int x, y;
	VECTOR() {}
	VECTOR(int x, int y)
		:x(x), y(y) {}
	VECTOR(POINT start, POINT end)
		:x(end.x - start.x), y(end.y - start.y) {}

	VECTOR operator+(const VECTOR right) const
	{
		return VECTOR(right.x + x, right.y + y);
	}

	int operator*(const VECTOR right) const
	{
		return x * right.x + y * right.y;
	}

	int sqmod()
	{
		return x * x + y * y;
	}
};


int n;
POINT pnt[3005];
bool pntexist[5005][5005];
int ans;

void search(int start)
{
	set<POINT>::iterator paim;
	for (int i = start; i <= n; i++)
	{
		VECTOR curr(pnt[start], pnt[i]);
		POINT aim(pnt[start].x + curr.y, pnt[start].y - curr.x);
		if (aim.x >= 0 && aim.y >= 0 && aim.x <= 5000 && aim.y <= 5000 && pntexist[aim.x][aim.y])
		{
			POINT aim(pnt[i].x + curr.y, pnt[i].y - curr.x);
			if (aim.x >= 0 && aim.y >= 0 && aim.x <= 5000 && aim.y <= 5000 && pntexist[aim.x][aim.y])
			{
				ans = max(ans, curr.sqmod());
			}
		}
		else
		{
			POINT aim(pnt[start].x - curr.y, pnt[start].y + curr.x);
			if (aim.x >= 0 && aim.y >= 0 && aim.x <= 5000 && aim.y <= 5000 && pntexist[aim.x][aim.y])
			{
				POINT aim(pnt[i].x - curr.y, pnt[i].y + curr.x);
				if (aim.x >= 0 && aim.y >= 0 && aim.x <= 5000 && aim.y <= 5000 && pntexist[aim.x][aim.y])
				{
					ans = max(ans, curr.sqmod());
				}
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (reg i = 1; i <= n; i++)
	{
		cin >> pnt[i].x >> pnt[i].y;
		pntexist[pnt[i].x][pnt[i].y] = 1;		//标记这个点存在，快速定位，关键 
	}
	for (int i = 1; i <= n; i++)
	{
		search(i);
	}
	cout << ans;

	return 0;

}
