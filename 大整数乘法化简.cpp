##include<iostream>
using namespace std;

unsigned long long n;

//P2181 
//组合数 & 大整数乘法化简 

int main()
{
	cin >> n;
	if (n == 3)
		cout << 0;
	else
	{
		unsigned long long ans = n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4;	//大整数乘法化简，由于n n-1中必有2的倍数，故n * (n - 1) / 2 可整除
																				//由于n n-1 n-2中必有3的倍数，故n * (n - 1) / 2*(n-2)/3可整除
																				//n * (n - 1) / 2  只会把n*(n-1)中含有2的因子除掉，如果n n-1中有3的倍数，不会破坏
																				//同理
		cout << ans;
	}
		
	return 0;
}

