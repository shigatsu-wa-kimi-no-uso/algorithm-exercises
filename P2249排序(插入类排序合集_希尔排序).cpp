#include<iostream>
#include<cmath>
using namespace std;

//洛谷P2249排序模版  插入排序，折半插入排序，希尔排序

void InsertSort(int* arr, int cnt) {
	//设arr[0]为哨兵
	//arr[1,cnt]是有效数据范围,arr[0]空缺保留
	for (int i = 2; i <= cnt; ++i) {
		arr[0] = arr[i]; //arr[i]移动到arr[0]做哨兵&暂存
		int j;
		for (j = i - 1; arr[0] < arr[j]; --j) {
			//如果arr[0]比arr[j]小,则arr[j]应后移,此时位置j空出空位
			arr[j + 1] = arr[j];
		}
		//否则跳出,此时arr[j+1]是空位,arr[j]满足arr[0]>=arr[j]
		//将arr[0]放到空位arr[j+1]即可
		arr[j + 1] = arr[0];
	}
}

void BInsertSort(int* arr, int cnt) {
	//设arr[0]为哨兵
	//arr[1,cnt]是有效数据范围,arr[0]空缺保留
	for (int i = 2; i <= cnt; ++i) {
		arr[0] = arr[i]; //arr[i]移动到arr[0]做哨兵&暂存,此时arr[i]是空位
		int low = 1, high = i - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (arr[0] < arr[mid]) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		//arr[0]在arr[high,low]之间,high+1==low
		//arr[high+1,i-1]需要移动到arr[high+2,i]上去,此时空出空位arr[high+1]留给arr[0]
		for (int j = i - 1; j >= high + 1; --j) {
			arr[j + 1] = arr[j];
		}
		arr[high + 1] = arr[0];
	}
}

//单轮希尔排序
void ShellInsert(int* arr, int cnt, int dk) {
	int t;
	for (int i = dk; i < cnt; ++i) {
		t = arr[i]; //arr[i]被取出,为空位
		//找到合适位置插入 注意,相邻元素差值为dk
		int j;
		for (j = i - dk; j >= 0 && arr[j] > t; j -= dk) {
			arr[j + dk] = arr[j];	//后移,产生空位arr[j]
		}
		//arr[j]<=t, arr[j+dk]是空位
		arr[j + dk] = t;
	}
}

void ShellSort(int* arr, int cnt) {
	int t = log2(cnt + 1); //排序趟数
	//其中一种增量序列生成算法：dt[k]=2^(t-k+1)-1, 1<=k<=t<=[log2_(n+1)]
	for (int k = 1; k <= t; ++k) {
		ShellInsert(arr, cnt, pow(2, t - k + 1) - 1);
	}
}

int a[1000010];

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ShellSort(a, n);
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}

	return 0;
}
