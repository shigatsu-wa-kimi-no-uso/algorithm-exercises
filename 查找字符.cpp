#include<iostream>
#include<string>
using namespace std;
//UVA10340

int main()
{
	string s, t;

	while (cin >> s >> t) //����EOF��ֹͣ
	{
		int i, pos = 0;
		for (i = 0; i < s.length(); i++)
		{
			if ((pos = t.find(s[i], pos)) == -1) break;
			pos++;	//��,find������pos���Ժ���� ����posλ��
		}
		if (i != s.length()) cout << "No";
		else cout << "Yes";
		cout << '\n';
	}
	return 0;
}

