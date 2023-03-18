#include<iostream>
using namespace std;

//P1017 ������ת��

int n, base;

void dectobase(int x)
{
	if (x == 0) return;
	int res = x / base;
	int ans = x % base;
	if (ans < 0)
	{
		res++;
		ans = x - res * base ;
	}
	dectobase(res);
	if (ans > 9)
		putchar('A' + ans - 10);
	else putchar('0' + ans);
}


int main()
{
	cin >> n >> base;
	cout << n <<"=";
	dectobase(n);
	cout << "(base" << base << ")";
	return 0;
}
