#include<iostream>
#include<utility>
#include<cmath>

using namespace std;

string digit;
string a, b;

void calc()
{
	int offset = 0;
	bool s = 0;
	bool sign = 0;
	int delta = a.length() - b.length();
	if (a == b)
	{
		cout << 0;
		return;
	}
	if (delta > 0)	//bλ����,���Ϊ����
	{
		b.insert(b.begin(), delta, '0');
	}
	else if (delta < 0)	//aλ����,�������,����ab
	{
		sign = 1;
		swap(a, b);
		b.insert(b.begin(), -delta, '0');
	}
	else
	{
		a > b || (swap(a, b), sign = 1);	//��֤a��b��
	}
	

	int dga, dgb;
	while (!a.empty())
	{
		dga = (s ? a.back()-1 : a.back()), dgb = b.back();
		dga >= dgb ? (digit.push_back(dga - dgb + '0'), s = 0) : (digit.push_back(dga - dgb + 1 + '9'), s = 1);
		a.pop_back();
		b.pop_back();
	}

	digit.back() == '0' && (digit.pop_back(), 1);
	if (sign) cout << '-';
	for (int i = digit.length() - 1; i >= 0; i--)
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
