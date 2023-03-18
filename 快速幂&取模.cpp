#include<iostream>
using namespace std;

//������P1226

/*ԭ��*//*����a^n�η�,����n=2^[log2(n)]+2^([log2(n)]-1)....2^2+2^1+1 ,
	  (����Ӧ�Ķ�����ÿλ�ĺ�)����a^n��Ҫn-1�μ��㣬���Ӷ�O(n)����
	  ��n��������Ҫlog2(n)+1�Σ����Ӷ���O(n)����O(logn)*/

long long quickpow(long long base,int n)//���ף�����
{
	long long ans = 1;
	while (n > 0)
	{
		if (n & 1) ans *= base;	//�����ķֽ�ʽ��������ƶ�Ӧ��1��0û��
		base *= base;		//���״������ߣ�base=x (x^n)^2=x^(n*2)������ֽ�ʽ�Ӷ�Ӧ
		n >>= 1;	//��������һλ
	}
	return ans;
}

//�����ݽ��ȡģ����
/*������ʽ*//*(A+B) mod n = (A mod n + B mod n) mod n
			(A*B) mod n = ((A mod n)*(B mod n)) mod n*/

//�ɷֽ�ʽ a^n=(a^2^[log2(n)])*(a^2^[log2(n)-1])*...
long long quickmod(long long base, int n,int a)	//���ף�����,��aȡģ
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

