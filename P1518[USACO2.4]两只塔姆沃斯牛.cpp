#include<iostream>
using namespace std;

char map[15][15];

struct POS
{
	int x, y;
	POS(){}
	POS(int x, int y)
		:x(x), y(y){}
	POS operator+(const POS p)
	{
		return POS(x+p.x, y+p.y);
	}
};

bool blockcheck(POS p)
{
	if (map[p.x][p.y] != '.' && map[p.x][p.y]!='F' && map[p.x][p.y]!='C') return true;
	else return false;
}

POS f, c;

int df,dc;

POS dir[4] = { {-1,0},{0,1},{1,0},{0,-1} };

int main()
{
	
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'F') f = POS(i, j);
			else if (map[i][j] == 'C') c = POS(i, j);
		}
	}
	int t = 0;
	while (1)
	{
		if (c.x == f.x && c.y == f.y) break;
		if (blockcheck(c + dir[dc % 4]))
		{
			dc++;
		}
		else
		{
			c = c + dir[dc % 4];
		}

		if (blockcheck(f + dir[df % 4]))
		{
			df++;
		}
		else
		{
			f = f + dir[df % 4];
		}
		t++;
		if (t > 1000000)
		{
			cout << 0;
			return 0;
		}
	}
	cout << t;
}
