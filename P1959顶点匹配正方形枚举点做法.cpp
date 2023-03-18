#i#include<iostream>
#define reg register int
using namespace std;

//P1959 给出点匹配正方形
//枚举顶点做法 

struct POINT
{
	int x, y;
	POINT() {};
	POINT(int x,int y)
		:x(x),y(y){}
};

struct VECTOR
{
	int x, y;
	VECTOR(){}
	VECTOR(int x,int y)
		:x(x),y(y){}
	VECTOR(POINT start,POINT end)
		:x(end.x-start.x),y(end.y-start.y){}

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
bool okpnt[3005];
bool used[3005];
int ans;

int firstpnt;

VECTOR vec[4];



void dfs(int thisindex,int lastvecord)
{
	if (lastvecord == 2)
	{
		VECTOR thisvec(pnt[thisindex], pnt[firstpnt]);
		if (thisvec * vec[0] == 0 && thisvec.sqmod() == vec[0].sqmod())
		{
			//cout << "getans:" << vec[0].sqmod() << '\n';
			ans = max(ans, vec[0].sqmod());
		//	getans = 1;
		}
	}
	else
	{
		for (int i = firstpnt; i <= n; i++)
		{
			if (used[i] || okpnt[i])
			{
			//	cout << "used point: " << pnt[i].x << " " << pnt[i].y << '\n';
				continue;
			}
				
			VECTOR thisvec(pnt[thisindex], pnt[i]);
			if (lastvecord != -1)
			{
				if (thisvec * vec[lastvecord] == 0 && thisvec.sqmod() == vec[lastvecord].sqmod())			//直角,长度相等
				{
					vec[lastvecord + 1] = thisvec;
				//	cout << "match! " << "POINT:" << pnt[thisindex].x << " " << pnt[thisindex].y << " with " << pnt[i].x << " " << pnt[i].y<<'\n';
					used[i] = 1;
					dfs(i, lastvecord + 1);
					used[i] = 0;
				}
				//else
				//	cout << "fail! " << "POINT:" << pnt[thisindex].x << " " << pnt[thisindex].y << " with " << pnt[i].x << " " << pnt[i].y << '\n';
			}
			else
			{
				vec[0] = thisvec;
				if (thisvec.sqmod() <= ans)			//比已知的答案还小，不必再找
					continue;
			//	cout << "start:\n" << "POINT:" << pnt[thisindex].x << " " << pnt[thisindex].y<<'\n';
			//	cout << "mod:" << thisvec.sqmod()<<'\n';
				used[i] = 1;
				dfs(i, 0);
				used[i] = 0;
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
	}
	for (int i = 1; i <= n; i++)
	{
		used[i] = 1;
		firstpnt = i;
		dfs(i,-1);
	}
	cout << ans;
	
	return 0;

}
