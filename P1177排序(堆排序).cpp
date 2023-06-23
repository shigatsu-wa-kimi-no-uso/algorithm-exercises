#include<iostream>
#include<cmath>
using namespace std;

//P1177对排序

int a[1000010];

void HeapAdjust(int* arr, int node, int cnt) {
	int fa = node;
	int nodeval = arr[fa]; //取fa的值,暂存,此时arr[fa]是空位
	for (int son = fa * 2; son <= cnt; son = fa * 2) {
		if (son + 1 <= cnt && arr[son] < arr[son + 1]) {
			son += 1;
		}
		if (nodeval >= arr[son]) {
			//找到了合适的位置
			break;
		} else {
			arr[fa] = arr[son];	//arr[son]移动到arr[fa],此时arr[son]是空位
			fa = son;
		}
	}
	arr[fa] = nodeval;
}

void MakeHeap(int* arr, int cnt) {
	for (int i = cnt / 2; i >= 1; --i) {
		HeapAdjust(arr, i, cnt);
	}
}

void HeapSort(int* arr, int cnt) {
	MakeHeap(arr, cnt);
	for (int i = cnt; i >= 1; --i) {
		//每次取堆顶元素放到末尾，然后缩小堆的范围为[1,i-1]
		int t = arr[i];
		arr[i] = arr[1];
		arr[1] = t;
		HeapAdjust(arr, 1, i - 1);
	}
}



int main()
{

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	HeapSort(a, n);
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << " ";
	}

	return 0;
}
