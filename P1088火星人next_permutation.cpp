#include<iostream>
#include<stdio.h>

using namespace std;


int main()
{
	int i,j,col,row;
	cin>>row>>col;
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;

int arr[11111];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= m; i++)
	{
		next_permutation(arr + 1, arr + 1 + n);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;

}
