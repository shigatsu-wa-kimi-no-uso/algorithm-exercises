#include<iostream>
using namespace std;

//快速幂P1226

/*原理*//*对于a^n次方,总有n=2^[log2(n)]+2^([log2(n)]-1)....2^2+2^1+1 ,
	  (即对应的二进制每位的和)计算a^n需要n-1次计算，复杂度O(n)，而
	  将n代换后，需要log2(n)+1次，复杂度由O(n)降至O(logn)*/

long long quickpow(long long base,int n)//基底，次数
{
	long long ans = 1;
	while (n > 0)
	{
		if (n & 1) ans *= base;	//次数的分解式子与二进制对应，1有0没有
		base *= base;		//基底次数升高，base=x (x^n)^2=x^(n*2)与次数分解式子对应
		n >>= 1;	//次数右移一位
	}
	return ans;
}

//快速幂结合取模运算
/*基本公式*//*(A+B) mod n = (A mod n + B mod n) mod n
			(A*B) mod n = ((A mod n)*(B mod n)) mod n*/

//由分解式 a^n=(a^2^[log2(n)])*(a^2^[log2(n)-1])*...
long long quickmod(long long base, int n,int a)	//基底，次数,对a取模
{
	long long ans = 1;
	while (n > 0)
	{
		if (n & 1)
		{
			ans *= base;
			ans %= a;
		}
		base *= base;
		base %= a;
		n >>= 1;
	}
	return ans;
}

int main()
{
	int a, b, p;
	cin >> a >> b >> p;
	cout << a<<'^'<<b<<" mod "<<p<<'='<<quickmod(a, b, p);
	return 0;
}

