#include<iostream>
#include<string>
#include<sstream>

using namespace std;
//P1022


int main()
{
	ios::sync_with_stdio(false);
	string tmp;
	cin >> tmp;
	int i;
	float w = 0, c = 0;
	char elem;
	int sgnpos = 0;
	string s;
	if (tmp[0] != '-')	//前面没符号，加上符号
	{
		s = "+";
	}
	s += tmp;
	s += "+0";			//统一结尾
		
	bool flag = 0;
	bool r = 0;
	for (i = 0; i < s.length(); i++)
	{
		if (s[i] == '=')
		{
			r = 1;		//切换到等式右边模式
			if (flag == 1)
			{
				stringstream ss;
				int tmp;
				ss << s.substr(sgnpos, i - sgnpos);		//会读入符号
				ss >> tmp;
				c += tmp;						//常数增加
				sgnpos = i;
			//	cout << s[sgnpos] << tmp << '\n';
			}
			s[i] = '+';
			flag = 1;
			sgnpos = i;
			continue;
		}

		switch (r)
		{
		case 0:											//等式左边情况
			if (s[i] == '+' || s[i] == '-')	//是符号
			{
				if (flag == 0)			//判断符号连起来
				{
					sgnpos = i;
					flag = 1;
				}
				else
				{
					stringstream ss;
					int tmp;
					ss << s.substr(sgnpos, i - sgnpos);		//会读入符号
					ss >> tmp;
					c += tmp;						//常数增加
			//		cout << s[sgnpos] << tmp << '\n';
					sgnpos = i;
				}

			}
			else if (s[i] >= 'a' && s[i] <= 'z')		//是字母，把从符号到字母之间的值记录到系数
			{
				elem = s[i];
				flag = 0;
				stringstream ss;
				int tmp;
				ss << s.substr(sgnpos, i - sgnpos);
				ss >> tmp;
				if (tmp == 0)
				{
					if (s[sgnpos] == '-')
						tmp = -1;
					else
						tmp = 1;
				}
		//		cout << s[sgnpos] << tmp << '\n';
				w += tmp;				//系数增加
			}
			break;
		case 1:
			if (s[i] == '+' || s[i] == '-')	//是符号
			{
				if (flag == 0)			//判断符号连起来
				{
					sgnpos = i;
					flag = 1;
				}
				else
				{
					stringstream ss;
					int tmp;
					ss << s.substr(sgnpos, i - sgnpos);
					ss >> tmp;
		//			cout << s[sgnpos] << tmp << '\n';
					c -= tmp;						//常数增加
					sgnpos = i;
				}

			}
			else if (s[i] >= 'a' && s[i] <= 'z')		//是字母，把从符号到字母之间的值记录到系数
			{
				elem = s[i];
				stringstream ss;
				flag = 0;
				int tmp;
				ss << s.substr(sgnpos, i - sgnpos);		//会读入符号
				ss >> tmp;
				if (tmp == 0)
				{
					if (s[sgnpos] == '-')
						tmp = -1;
					else
						tmp = 1;
				}
		//		cout << s[sgnpos] << tmp << '\n';
				w -= tmp;				//系数增加
			}
		}
	}
	printf("%c=%.3f", elem, -c / w);
	
	return 0;

}
