#include<iostream>
#include<utility>
#include<cmath>

using namespace std;

string digit;
string a, b;

void calc()
{
	int offset = 0;
	int delta = a.length() - b.length();
	if (delta > 0)	//b位数少,结果为正数
	{
		b.insert(b.begin(), delta, '0');
	}
	else if (delta < 0)	//a位数少,结果负数,交换ab	保证a的位数大
	{
		swap(a, b);
		b.insert(b.begin(), -delta, '0');
	}

	int dga, dgb,s=0,result;
	while (!a.empty())
	{
		dga = a.back()-'0';
		dgb = b.back()-'0';	
		digit.push_back((dga+dgb+s)%10 +'0');	//坑
		s = (dga + dgb+s) / 10;	//坑
		a.pop_back();
		b.pop_back();
	}
	/// <summary>
	/// ***********
	/// </summary>
	if (s) digit.push_back('1');  //坑
	/// <summary>
	/// *******
	/// </summary>
	for (int i = digit.length() - 1; i >= 0; i--)	//注意倒序输出
	{
		cout << digit[i];
	}

}
int main()
{
	
	cin >> a >> b;

	calc();



	return 0;
}
