#include <iostream>
using namespace std;

//洛谷P3366最小生成树 Prim 算法
//N点的图,初始化第一个点后,还需要N-1次操作

int N;

//graph[i][j]>0 <i,j> in E
//graph[i][j]==-1(INT_MAX) <i,j> not in E
//graph[i][i]==0 i in V
//保证有N点时,点编号在[0,N-1]中
unsigned int graph[5010][5010];


struct DistToTree {
	int destPnt;
	unsigned int dist;
}dists[5010];//初始化为0xFFFFFFFF(-1)表示不可达,dists[i]为0说明i已经在生成树节点集合中,否则为点i到生成树的最短距离


void updateDists(int newVertex) {
	//当遍历到newVertex时,对应距离被设为0
	for (int k = 0; k < N; ++k) {
		if (dists[k].dist > graph[k][newVertex]) {
			dists[k] = { newVertex,graph[k][newVertex] };
		}
	}
}

void initDistArray(int initVertex) {
	for (int k = 0; k < N; ++k) {
		dists[k] = { initVertex, ~0u };
	}
}

int findClosestVertex() {
	int i;
	unsigned int minDist = ~0;
	int closestVertex = -1;
	for (i = 0; i < N; ++i) {
		if (dists[i].dist < minDist && dists[i].dist != 0) {
			closestVertex = i;
			minDist = dists[i].dist;
		}
	}
	return closestVertex;
}

unsigned long long MST_Prim(int initVertex) {
	unsigned long long weight = 0;
	initDistArray(initVertex);
	//初始化根节点
	updateDists(initVertex);
	//已经处理一点,i从1开始
	for (int i = 1; i < N; ++i) {
		int nextTreeVertex = findClosestVertex();
		//找不到最近的点,说明原来的图不是连通的
		if (nextTreeVertex == -1) {
			return -1;
		}
		weight += dists[nextTreeVertex].dist;
		//更新距离数组
		updateDists(nextTreeVertex);
	}
	return weight;
}


void initGraph() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i != j) {
				graph[i][j] = ~0;
			}
		}
	}
}

int main() {
	int M;
	cin >> N >> M;
	initGraph();
	for (int i = 0; i < M; ++i) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		//测试数据中点从1开始
		if (w < graph[v2 - 1][v1 - 1]) {
			graph[v1 - 1][v2 - 1] = graph[v2 - 1][v1 - 1] = w;
		}
	}
	unsigned long long weight = MST_Prim(0);
	if (weight != -1) {
		cout << weight;
	} else {
		cout << "orz";
	}
}