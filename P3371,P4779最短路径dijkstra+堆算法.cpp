#include <iostream>
#include <queue>
using namespace std;

//P4779 P3371 最短路 dijkstra + 堆 算法

int n, m, s;

struct Edge {
	int dest;
	unsigned long long weight;
	Edge* nextEdge;
};

//专门存放从S指向dest的边
struct VirtualEdge {
	int dest;
	unsigned long long distToS;
	bool operator>(const VirtualEdge& rgt) const {
		return distToS > rgt.distToS;
	}
};

struct Vertex {
	Edge* firstEdge;
	Edge* lastEdge;
}vertices[300010];


void dijkstra(int v0) {
	//minDest[i]为点i到v0的最短距离
	static unsigned long long minDistToS[300010];
	static bool vis[300010];
	for (int i = 1; i <= n; ++i) {
		minDistToS[i] = ~0;
	}

	//存储未确定距离的点的集合
	priority_queue<VirtualEdge,vector<VirtualEdge>,greater<VirtualEdge>> heap;
	//提前push v0, 相当于初始化第一个点
	heap.push({ v0,0 });
	minDistToS[v0] = 0;
	do {
		//在未确定距离的点中选择距离v0最近的点
		VirtualEdge vEdge = heap.top();
		heap.pop();
		//确定点
		int newVex = vEdge.dest;
		if(vis[newVex]) continue; //重要！一个点有可能被多次push,但最先pop的就是最短的，此时已经确定该点，不需要重复确定
		vis[newVex] = true;

		//更新刚刚确定的点附近的点到v0的距离,加入到未确定距离的点的集合中去
		Edge* edge = vertices[newVex].firstEdge;
		while (edge != nullptr) {
			int adjacentVex = edge->dest;
			unsigned long long edgeWeight = edge->weight;
			//如果不比之前小,就不push,因为即使push也肯定后pop,反而增加计算量,引起混乱
			if (!vis[adjacentVex] && adjacentVex != newVex && edgeWeight + minDistToS[newVex] < minDistToS[adjacentVex]) {
				//建立一个假想边(从v0到edge->dest)(更新相应edge->dest的点到v0的距离
				minDistToS[adjacentVex] = edgeWeight + minDistToS[newVex];
				heap.push({ adjacentVex,  minDistToS[adjacentVex]});
			}
			edge = edge->nextEdge;
		}
	} while (!heap.empty());

	for (int i = 1; i <= n; ++i) {
		
		if (minDistToS[i] == ~0) {
			cout << -1 << " ";
		}else {
			cout << minDistToS[i] << " ";
		}
		//cout << minDistToS[i] << " ";
	}
}

void destroyEdges() {
	for (int i = 0; i < n; ++i) {
		Edge* edge = vertices[i].firstEdge;
		while (edge != nullptr) {
			Edge* nextEdge = edge->nextEdge;
			delete edge;
			edge = nextEdge;
		}
	}
}

void addEdge(int start,int dest, unsigned long long weight) {
	Edge* newEdge = new Edge{ dest,weight,nullptr };
	if (vertices[start].firstEdge == nullptr) {
		vertices[start].firstEdge = newEdge;
	} else {
		vertices[start].lastEdge->nextEdge = newEdge;
	}
	vertices[start].lastEdge = newEdge;
}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < m; ++i) {
		unsigned long long u, v, w;
		cin >> u >> v >> w;
		if(u==v) continue;
		addEdge(u, v, w);
	}
	dijkstra(1);
	destroyEdges();
}