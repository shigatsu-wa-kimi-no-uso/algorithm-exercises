#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n;

string htimes(string a, string b)
{
	string res;
	int la = a.length();
	int lb = b.length();
	res.assign(la + lb , '\0');	//预初始化，la位数*lb位数最大为la+lb位数
	if (la > lb)
	{
		swap(a, b);
		swap(la, lb);
	}
	char ch;
	int ex;
	for (int i = 0; i <la ; i++)
	{
		ex = 0;
		for (int j = 0; j <lb; j++)
		{
			res[i + j] += (a[la - i - 1] - '0') * (b[lb - j - 1] - '0') + ex;
			ex = res[i + j] / 10;
			res[i + j] %= 10;
		}
		res[i + lb] = ex; //最后一位进位直接加
	}
	int len = res.length();
	for (int i = 0; i < len-1; i++)
	{
		res[i] += '0';	
	}
	if (res[len - 1] != '\0') res[len - 1] += '0'; //前导0判断
	else res.erase(len - 1);
	reverse(res.begin(), res.end());
	return res;
}

string hplus(string a, string b)
{
	string res;
	int la = a.length();
	int lb = b.length();
	if (la < lb)
	{
		swap(a, b);
		swap(la, lb);
	}
	res.reserve(la + 2);
	int ex=0;
	char ch;
	while (lb)
	{
		ch = a[la-1] -'0' + b[lb - 1] -'0' + ex;
		ex = ch / 10;
		ch %= 10;
		res += ch + '0';
		la--;
		lb--;
	}

	if (la == lb && ex>0)
	{
		res += ex + '0';
	}
	else if (la > lb)
	{
		while (la)
		{
			ch = a[la-1] -'0' + ex;
			ex = ch / 10;
			ch %= 10;
			res += ch + '0';
			la--;
		}
		if (ex > 0)
		{
			res += ex + '0';
		}
	}

	reverse(res.begin(), res.end());

	return res;
}


string fact(int n)
{
	static string* elem = new string[55];
	static int id = 0;
	elem[0] = "1";

	for (int i = id + 1; i <= n; i++)
	{
		elem[i] = htimes(elem[i - 1], to_string(i));
	}
	id = max(id, n);

	return elem[n];
}


int main()
{
	cin >> n;
	string ans="0";
	for (int i = 1; i <= n; i++)
	{
		ans = hplus(ans,fact(i));
	}
	cout << ans;
	return 0;

}
