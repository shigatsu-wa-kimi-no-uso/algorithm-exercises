//P256

#include<iostream>
#include<cmath>
using namespace std;
int m, n, p;

inline double f(double x)	
{
	return x*x*x+2*x*x+1;			//f(x)=x^3+x^2+1
}


int main()
{
	double a,b,l,r,midl,midr;
	cin  >> a >> b;
	l = a, r = b;
	while (!(abs(r - l) < 1E-12))
	{
		midl = l + (r - l) / 3.0;
		midr = r - (r - l) / 3.0;
		f(midl) < f(midr) ? l = midl : r = midr;		//求极大值时保留小，极小值时保留大
	}
	printf("%.10e\n", l);
	printf("%.10e\n", f(l));

	return 0;

}
