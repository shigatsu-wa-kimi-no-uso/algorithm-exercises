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
	if (delta > 0)	//bλ����,���Ϊ����
	{
		b.insert(b.begin(), delta, '0');
	}
	else if (delta < 0)	//aλ����,�������,����ab	��֤a��λ����
	{
		swap(a, b);
		b.insert(b.begin(), -delta, '0');
	}

	int dga, dgb,s=0,result;
	while (!a.empty())
	{
		dga = a.back()-'0';
		dgb = b.back()-'0';	
		digit.push_back((dga+dgb+s)%10 +'0');	//��
		s = (dga + dgb+s) / 10;	//��
		a.pop_back();
		b.pop_back();
	}
	/// <summary>
	/// ***********
	/// </summary>
	if (s) digit.push_back('1');  //��
	/// <summary>
	/// *******
	/// </summary>
	for (int i = digit.length() - 1; i >= 0; i--)	//ע�⵹�����
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
