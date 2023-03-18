#include<iostream>
using namespace std;

//É¾³ý×Ö·ûDP
string s;

int t;

string f[105][105];

//LANQIAO
//	1	2	3	4	5	6	7	8
//1 L	A	A	A	A	A	A	
//2		LA	AN	AN	AI	AA	AA	
//3			LAN	ANQ	ANI	AIA	AAO
//4			  LANQ ANQI ANIA AIAO
//5				 LANQI ANQIA ANIAO
//6
//7


int main()
{
	cin >> s;
	cin >> t;
	int k = s.length() - t;
	s.insert(0, 1, 0);
	for (int i = 1; i <= k; i++)
	{
		for (int j = i; j<s.length(); j++)
		{
			if (j == i) f[i][j] = f[i - 1][j - 1] + s[j];
			else f[i][j] = min(f[i - 1][j - 1] + s[j], f[i][j - 1]);
			//cout << f[i][j] << ' ';
		}
		//cout << "\n";
	}
	cout << f[k][s.length() - 1];
	
	return 0;
}
