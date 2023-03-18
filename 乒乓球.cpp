#include<iostream>
#include<string>
using namespace std;

string s;

void printRes11()
{
	int a = 0, b = 0, i = 0;
	bool flag = 0;
	while (1)
	{
		char ch = s[i];
		if (ch == 'W')
		{
			a++;
		}
		else if (ch == 'L')
		{
			b++;
		}
		else if (ch == 'E')
		{
			printf("%d:%d\n", a, b);
			return;
		}
		i++;
		if (a >= 11 || b >= 11)
		{
			if (abs(a - b) >= 2)
			{
				printf("%d:%d\n", a, b);
				a = 0;
				b = 0;
			}
		}

	}
}

void printRes21()
{
	int a = 0, b = 0, i = 0;
	bool flag = 0;
	while (1)
	{
		char ch = s[i];
		if (ch == 'W')
		{
			a++;
		}
		else if (ch == 'L')
		{
			b++;
		}
		else if (ch == 'E')
		{
			printf("%d:%d\n", a, b);
			return;
		}
		i++;
		if (a >= 21 || b >= 21)
		{
			if (abs(a - b) >= 2)
			{
				printf("%d:%d\n", a, b);
				a = 0;
				b = 0;
			}
		}

	}
}


int main()
{

	char ch;
	while (1)
	{
		cin >> ch;
		switch (ch)
		{
		case '\n':
			break;
		case 'E':
			s += ch;
			printRes11();
			printf("\n");
			printRes21();
			return 0;
		default:
			s += ch;
		}
	}
	return 0;
}
