//P258

#include<iostream>
#include<cmath>
using namespace std;
int m, n, p;

inline double f(double x)	//f(x)=m^x+n^x-p^x 
{
	return pow(m, x) + pow(n, x) - pow(p, x);
}


int main()
{
	double a,b,l,r,mid;
	cin >> m >> n >> p >> a >> b;
	l = a, r = b;
	if(f(a)*f(b)>0) 
	{
		printf("NO");
		return 0;
	}
	
	while (!(abs(r - l) < 1E-12))
	{
		mid = (l + r )/ 2;
		f(l)*f(mid)>0 ? l = mid : r = mid;	//f(l)与f(mid)同号判断，（单调性位置）
	}
	printf("%.10e\n", (l+r)/2);
	printf("%.10e\n", f((l+r)/2));
	
	return 0; 
}
