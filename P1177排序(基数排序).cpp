#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

int a[1000010];


int getdigit(int val,int t) {
	while (t > 1) {
		val /= 10;
		--t;
	}
	return val % 10;
}

void RadixSort(int* arr, int cnt, int t, int radix) {
	queue<int>* cont = new queue<int>[radix];
	for (int i = 0; i < t; ++i) {
		for (int j = 0; j < cnt; ++j) {
			cont[getdigit(arr[j],i+1)].push(arr[j]);
		}
		int it = 0;
		for (int j = 0; j < radix; ++j) {
			while (!cont[j].empty()) {
				arr[it++] = cont[j].front();
				cont[j].pop();
			}
		}
	}
}


int digitcnt(int v) {
	int len = 0;
	if (v == 0) {
		return 1;
	}
	while (v > 0) {
		v /= 10;
		++len;
	}
	return len;
}

int main()
{
	int maxlen = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		int l = digitcnt(a[i]);
		maxlen = l > maxlen ? l : maxlen;
	}
	RadixSort(a, n,maxlen,10);
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}

	return 0;
}
