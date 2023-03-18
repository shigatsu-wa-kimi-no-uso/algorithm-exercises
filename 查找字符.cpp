#include<iostream>
#include<string>
using namespace std;
//UVA10340

int main()
{
	string s, t;

	while (cin >> s >> t) //遇到EOF才停止
	{
		int i, pos = 0;
		for (i = 0; i < s.length(); i++)
		{
			if ((pos = t.find(s[i], pos)) == -1) break;
			pos++;	//坑,find函数在pos及以后查找 包括pos位置
		}
		if (i != s.length()) cout << "No";
		else cout << "Yes";
		cout << '\n';
	}
	return 0;
}

