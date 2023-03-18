#include<iostream>
#include<cmath>
#include<set>
using namespace std;

multiset<int> s;
int a[(int)1E5 + 2];
long long ans;

//P1732 [TJOI2011]序列

int main()
{
	int t,n;
	cin >> t;
	int i,j;
	multiset<int>::iterator iter;
	multiset<int>::iterator iter2;
	for (i = 1; i <= t; i++)
	{
		cin >> n;
		for(j=1;j<=n;j++)
			cin >> a[j];
		ans = a[1];
		s.insert(a[1]);
		for (j = 2; j <= n; j++)
		{		
			iter = s.lower_bound(a[j]);
			iter2 = iter;
			if (iter != s.begin()) iter2--;
			if (iter == s.end()) iter--;		//s.end()值在g++上为最后一个元素的后一个空元素的指针,但解引用后，值为最后一个元素的值  即 iter=s.end() *(--iter) 与*iter值相同  
			ans += min(abs(*iter - a[j]), abs(*iter2 - a[j]));
			s.insert(a[j]);
		}
		cout << ans << '\n';
		s.clear();
	}
	return 0;
}

