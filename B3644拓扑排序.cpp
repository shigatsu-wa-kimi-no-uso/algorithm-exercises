#include <iostream>
#include <stack>
using namespace std;

//洛谷B3644 拓扑排序

struct Edge {
    int dest;
    int weight;
    Edge* adjacentEdge;
};

struct Vertex {
    Edge* firstEdge;
    Edge* lastEdge;
    int indegree;
}vertices[105];
    
int N;

void link(int vertex1, int vertex2,int weight) {
    Edge* edge = new Edge{ vertex2,weight ,nullptr};
    if (vertices[vertex1].firstEdge == nullptr) {
        vertices[vertex1].firstEdge = edge;
    } else {
        vertices[vertex1].lastEdge->adjacentEdge = edge;
    }
    vertices[vertex1].lastEdge = edge;
    ++vertices[vertex2].indegree;
}

void topologicalSort() {
    stack<int> zeroDegreeVertices;
    for (int i = 1; i <= N; ++i) {
        if (vertices[i].indegree == 0) {
            zeroDegreeVertices.push(i);
        }
    }

    while (!zeroDegreeVertices.empty()) {
        int zeroIndVex = zeroDegreeVertices.top();
        zeroDegreeVertices.pop();
        cout << zeroIndVex << " ";
        Edge* edge = vertices[zeroIndVex].firstEdge;
        while (edge != nullptr) {
            --vertices[edge->dest].indegree;
            if (vertices[edge->dest].indegree == 0) {
                zeroDegreeVertices.push(edge->dest);
            }
            edge = edge->adjacentEdge;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int j;
        cin >> j;
        while(j!=0) {
            link(i, j, 1);
			cin >> j;
        }
    }
    topologicalSort();
}