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
	if (tmp[0] != '-')	//ǰ��û���ţ����Ϸ���
	{
		s = "+";
	}
	s += tmp;
	s += "+0";			//ͳһ��β
		
	bool flag = 0;
	bool r = 0;
	for (i = 0; i < s.length(); i++)
	{
		if (s[i] == '=')
		{
			r = 1;		//�л�����ʽ�ұ�ģʽ
			if (flag == 1)
			{
				stringstream ss;
				int tmp;
				ss << s.substr(sgnpos, i - sgnpos);		//��������
				ss >> tmp;
				c += tmp;						//��������
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
		case 0:											//��ʽ������
			if (s[i] == '+' || s[i] == '-')	//�Ƿ���
			{
				if (flag == 0)			//�жϷ���������
				{
					sgnpos = i;
					flag = 1;
				}
				else
				{
					stringstream ss;
					int tmp;
					ss << s.substr(sgnpos, i - sgnpos);		//��������
					ss >> tmp;
					c += tmp;						//��������
			//		cout << s[sgnpos] << tmp << '\n';
					sgnpos = i;
				}

			}
			else if (s[i] >= 'a' && s[i] <= 'z')		//����ĸ���Ѵӷ��ŵ���ĸ֮���ֵ��¼��ϵ��
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
				w += tmp;				//ϵ������
			}
			break;
		case 1:
			if (s[i] == '+' || s[i] == '-')	//�Ƿ���
			{
				if (flag == 0)			//�жϷ���������
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
					c -= tmp;						//��������
					sgnpos = i;
				}

			}
			else if (s[i] >= 'a' && s[i] <= 'z')		//����ĸ���Ѵӷ��ŵ���ĸ֮���ֵ��¼��ϵ��
			{
				elem = s[i];
				stringstream ss;
				flag = 0;
				int tmp;
				ss << s.substr(sgnpos, i - sgnpos);		//��������
				ss >> tmp;
				if (tmp == 0)
				{
					if (s[sgnpos] == '-')
						tmp = -1;
					else
						tmp = 1;
				}
		//		cout << s[sgnpos] << tmp << '\n';
				w -= tmp;				//ϵ������
			}
		}
	}
	printf("%c=%.3f", elem, -c / w);
	
	return 0;

}
