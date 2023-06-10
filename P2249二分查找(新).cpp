#include <iostream>
using namespace std;


//洛谷P2249 二分查找

int arr[1000010];


int bsearch(const int* arr,const int arrlen, const int target) {
	//范围[lb,ub]
	int lb = 0, ub = arrlen -1;
	int mid;

	//lb==ub时是最后一轮查找
	while (lb <= ub) {
		mid = lb + (ub - lb) / 2;
		if (arr[mid] == target) {
			return mid;
		} else if (arr[mid] < target) {
			lb = mid + 1;
		} else {
			ub = mid - 1;
		}
	}
	return -1;
}



int main() {
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin>>arr[i];
	}

	for (int i = 0; i < m; ++i) {
		int t;
		cin >> t;
		int index = bsearch(arr, n, t);
		int lastIndex = -1;
		while (index != -1) {
			lastIndex = index;
			index = bsearch(arr, index, t);
		}
		if (lastIndex != -1) {
			cout << lastIndex + 1 << " ";
		} else {
			cout << -1 << " ";
		}
	}
}