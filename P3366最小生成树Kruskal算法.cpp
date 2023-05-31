#include <iostream>
#include <queue>
using namespace std;

//洛谷P3366最小生成树 Kruskal 算法
//N点的图,初始化第一个点后,还需要N-1次操作

int N;	//点数
int M;	//边数

//保证边数为M时,边的标号在[0,M-1]中
//点数为N时,点的标号在[0,N-1]中
struct Edge {
	int start;
	int end;
	int weight;
	bool operator>(const Edge& rgt) const {
		return weight > rgt.weight;
	}
};

priority_queue<Edge,vector<Edge>,greater<Edge>> edgeHeap;

//father[i]表示点i指向的父节点,初始化时,father[i]=i,即所有点都是孤立的点
//采用并查集的方式,findAncestor(i)相同的点,视为同一连通分量
int father[5010]; 

//在寻找ancestor时顺便更新所有ancestor,以缩短后续寻找祖先时的路径
//father[i] = i 时,说明找到了祖先(根节点)
int findAncestor(int i) {
	if (father[i] != i) {
		father[i] = findAncestor(father[i]);
	}
	return father[i];
}

//合并两个连通分量,即令两个点的祖先相同
void merge(int newVertex,int targetVertex) {
	//newVertex是另外一个连通分量的根节点,直接修改指向
	if (father[newVertex] == newVertex) {
		father[newVertex] = targetVertex;
	} else {
		//否则找到其祖先,修改祖先的指向
		int ancesVertex = findAncestor(newVertex);
		father[ancesVertex] = targetVertex;
	}
}

bool verticesInSameSet(int vertex1, int vertex2) {
	return findAncestor(vertex1) == findAncestor(vertex2);
}

void initFather() {
	for (int i = 0; i < N; ++i) {
		father[i] = i;
	}
}

unsigned long long MST_Kruskal() {
	unsigned long long weight = 0;
	initFather();
	int treeEdgeCnt = 0;
	while (!edgeHeap.empty()) {
		Edge edge = edgeHeap.top();
		if (!verticesInSameSet(edge.start, edge.end)) {
			merge(edge.start, edge.end);
			//每次merge 生成树的边数+1
			++treeEdgeCnt;
			weight += edge.weight;
		}
		edgeHeap.pop();
	}
	//N个点的图,其最小生成树的边数为N-1. 如果最后treeEdgeCnt!=N-1,说明图不是连通的
	if (treeEdgeCnt != N - 1) {
		return -1;
	}
	return weight;
}


int main() {
	cin >> N >> M;
	//输入的点号在[1,N]减1后使得范围在[0,N-1]中
	for (int i = 0; i < M; ++i) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		edgeHeap.push({ v1-1,v2-1,w });
	}
	unsigned long long weight = MST_Kruskal();

	if (weight != -1) {
		cout << weight;
	} else {
		cout << "orz";
	}
}