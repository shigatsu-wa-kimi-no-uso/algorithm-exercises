#include<iostream>
#include<string>
#include<algorithm>
#define reg register int


using namespace std;

//P1009


string s[51];
int n;
string ans;

//高精度乘法
string haaplus(string a, string b);
string haamult(string a, string b);

string haamult(string a,string b)
{
	int la = a.length();
	int lb = b.length();
	string d1, d2;
	d1.reserve(la + lb + 2);	// 预留空间，a位数与b位数相乘，结果位数可达a+b+1，取a+b+2
	d2.reserve(la + lb + 2);
	if (la < lb)
	{
		swap(a, b);	//保证a比b长，提高效率(减少plus次数)
		swap(la, lb);
	}
	int i = 1, j = 1;
	int extra = 0;					//进位
	int val;
	char digit;
	while (1)
	{
		val = (a[la - i] - 48) * (b[lb - j] - 48) + extra;		//该位的值
		digit = val % 10 + 48;						
		extra = val / 10;							//进位存储
		d1.push_back(digit);
		if (i == la)		//一次乘法结束
		{
			if (extra != 0)	//【重要】判断进位有无
			{
				digit = extra + 48;
				d1.push_back(digit);
				extra = 0;			//重要，进位置0
			}
			reverse(d1.begin(), d1.end());	//字符串d1反转保证高位在前
			d1.append(j - 1, '0');			//末尾补0
			j++;
			i = 1;
			d2 = haaplus(d1, d2);	//d2存储上次的结果字符串，把d1 d2加起来
			d1.clear();
			if (j == lb + 1)		//乘法结束判断
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
		swap(a, b);	//保证a比b长
		swap(la, lb);
	}
	if (lb == 0)
		return a;
	int i = 1, j = 1;
	int val, extra = 0;
	char digit;
	string ans;
	ans.reserve(la + 2);	//预留空间，a位数+b位数，最终结果最高为max(a,b)+1位数，取max(a,b)+2
	while (1)
	{
		val = a[la - i] - 48 + b[lb - i] - 48 + extra;
		extra = val / 10;
		digit = val % 10 + 48;
		ans.push_back(digit);
		if (j == lb) //较短字符串达到终点
		{
			if (i == la)	//判断长字符串是否到达终点
			{
				if (extra != 0)		//重要
				{
					digit = extra + 48;
					ans.push_back(digit);
					extra = 0;
				}
				reverse(ans.begin(), ans.end());
			}
			else
			{
				i++;					//扫描后面的数
				digit = extra + a[la - i];
				ans.push_back(digit);
				i++;					//继续看后面的数
				if (la - i >= 0)
				{
					ans.append(a, 0, la - i + 1);   //取a的[0,la-i+1)字符串，把没加的地方加上注意左闭右开
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
		s[i] = haamult(s[i - 1], tmp);	//乘法 使用递推式计算i! s[i]存储i! 的值
		ans = haaplus(s[i], ans);		//加法
	}
	cout << ans;

	return 0;
}
