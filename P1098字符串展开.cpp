#include <iostream>
using namespace std;

string s;
int p[4];

bool isBothLCase(char c,char d)
{
	return ('a' <= c && c <= 'z') && ('a'<=d && d<='z');
}

bool isBothDigit(char c, char d)
{
	return ('0' <= c && c <= '9') && ('0' <= d && d <= '9');
}


void printD(char st, char end)
{
	for (char j = st + 1; j < end; j++)
	{
		for (int k = 0; k < p[2]; k++)
		{
			cout << (char)j;
		}
	}
}

void printL(char st,char end)
{
	for (char j = st + 1; j < end; j++)
	{
		for (int k = 0; k < p[2]; k++)
		{
			cout << (char)j;
		}
	}
}

void printLR(char st, char end)
{
	for (char j = end - 1; j > st; j--)
	{
		for (int k = 0; k < p[2]; k++)
		{
			cout << (char)j;
		}
	}
}

void printU(char st, char end)
{
	for (char j = st + 1; j < end; j++)
	{
		for (int k = 0; k < p[2]; k++)
		{
			cout << (char)(j-('a'-'A'));
		}
	}
}


void printUR(char st, char end)
{
	for (char j = end - 1; j > st; j--)
	{
		for (int k = 0; k < p[2]; k++)
		{
			cout << (char)(j - ('a' - 'A'));
		}
	}
}


void printStar(char st,char end)
{
	for (char j = st + 1; j < end; j++)
	{
		for (int k = 0; k < p[2]; k++)
		{
			cout << '*';
		}
	}
}


int main()
{
	cin >> p[1] >> p[2] >> p[3];
	cin >> s;
	int len = s.length();
	cout << s[0];
	void (*func[7])(char, char) = {printD,printL,printU,printStar,printLR,printUR,printStar};
	for (int i = 1; i < len-1; i++)
	{
		if (s[i] == '-')
		{
			if (s[i - 1] < s[i + 1])
			{
				if (isBothLCase(s[i - 1], s[i + 1]))
				{
					func[p[1] + (p[3]-1)*3](s[i - 1], s[i + 1]);
					continue;
				}
				else if (isBothDigit(s[i - 1], s[i + 1]))
				{
					func[0+3*(p[1]/3)](s[i-1],s[i+1]);
					continue;
				}
			}
		}
		cout << s[i];
	}
	cout << s[len-1];
	return 0;
}


