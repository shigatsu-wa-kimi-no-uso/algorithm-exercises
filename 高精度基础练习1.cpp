#include<iostream>
#include<string>
#include<algorithm>
#define reg register int


using namespace std;

//P1009


string s[51];
int n;
string ans;

//�߾��ȳ˷�
string haaplus(string a, string b);
string haamult(string a, string b);

string haamult(string a,string b)
{
	int la = a.length();
	int lb = b.length();
	string d1, d2;
	d1.reserve(la + lb + 2);	// Ԥ���ռ䣬aλ����bλ����ˣ����λ���ɴ�a+b+1��ȡa+b+2
	d2.reserve(la + lb + 2);
	if (la < lb)
	{
		swap(a, b);	//��֤a��b�������Ч��(����plus����)
		swap(la, lb);
	}
	int i = 1, j = 1;
	int extra = 0;					//��λ
	int val;
	char digit;
	while (1)
	{
		val = (a[la - i] - 48) * (b[lb - j] - 48) + extra;		//��λ��ֵ
		digit = val % 10 + 48;						
		extra = val / 10;							//��λ�洢
		d1.push_back(digit);
		if (i == la)		//һ�γ˷�����
		{
			if (extra != 0)	//����Ҫ���жϽ�λ����
			{
				digit = extra + 48;
				d1.push_back(digit);
				extra = 0;			//��Ҫ����λ��0
			}
			reverse(d1.begin(), d1.end());	//�ַ���d1��ת��֤��λ��ǰ
			d1.append(j - 1, '0');			//ĩβ��0
			j++;
			i = 1;
			d2 = haaplus(d1, d2);	//d2�洢�ϴεĽ���ַ�������d1 d2������
			d1.clear();
			if (j == lb + 1)		//�˷������ж�
				return d2;
		}
		else
			i++;
	}
}

string haaplus(string a, string b)
{
	int la = a.length();
	int lb = b.length();
	if (la < lb)
	{
		swap(a, b);	//��֤a��b��
		swap(la, lb);
	}
	if (lb == 0)
		return a;
	int i = 1, j = 1;
	int val, extra = 0;
	char digit;
	string ans;
	ans.reserve(la + 2);	//Ԥ���ռ䣬aλ��+bλ�������ս�����Ϊmax(a,b)+1λ����ȡmax(a,b)+2
	while (1)
	{
		val = a[la - i] - 48 + b[lb - i] - 48 + extra;
		extra = val / 10;
		digit = val % 10 + 48;
		ans.push_back(digit);
		if (j == lb) //�϶��ַ����ﵽ�յ�
		{
			if (i == la)	//�жϳ��ַ����Ƿ񵽴��յ�
			{
				if (extra != 0)		//��Ҫ
				{
					digit = extra + 48;
					ans.push_back(digit);
					extra = 0;
				}
				reverse(ans.begin(), ans.end());
			}
			else
			{
				i++;					//ɨ��������
				digit = extra + a[la - i];
				ans.push_back(digit);
				i++;					//�������������
				if (la - i >= 0)
				{
					ans.append(a, 0, la - i + 1);   //ȡa��[0,la-i+1)�ַ�������û�ӵĵط�����ע������ҿ�
				}
				reverse(ans.begin(), ans.end());						
			}
			return ans;
		}
		else
		{
			i++;
			j++;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	s->reserve(200);
	ans.reserve(300);
	s[0] = "1";
	char tmp[3];
	cin >> n;
	for (reg i = 1; i <= n; i++)
	{
		sprintf_s(tmp,3, "%d", i);
		s[i] = haamult(s[i - 1], tmp);	//�˷� ʹ�õ���ʽ����i! s[i]�洢i! ��ֵ
		ans = haaplus(s[i], ans);		//�ӷ�
	}
	cout << ans;

	return 0;
}
