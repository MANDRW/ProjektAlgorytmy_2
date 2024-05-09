#include "graph_matrix.h"
#include<iostream>
#include <queue>
#include <vector>

using namespace std;

GraphMatrix::GraphMatrix(int V){
    this->V = V;
    matrix.resize(V, vector<int>(V, 0));
}

void GraphMatrix::incidentEdges(int v){
    for(int i = 0; i < V; i++){
        if(matrix[v][i] != 0){
            std::cout << "Krawedzie incydentne wierzcholka" <<v<<" i "<<i <<" waga: " << matrix[v][i] << std::endl;
        }
    }
}

void GraphMatrix::insertVertex(){
    V++;
    matrix.resize(V, vector<int>(V,0));
}

void GraphMatrix::insertEdge(int v, int u, int w){
    if(v >= V or u >= V or v < 0 or u < 0){
        return;
    }
    matrix[v][u] = w;
    matrix[u][v] = w;
}

void GraphMatrix::removeEdge(int v, int u){
    matrix[v][u] = 0;
    matrix[u][v] = 0;
}


void GraphMatrix::printGraph() {
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            if(matrix[i][j]!=0)
                std::cout << "Wierzcholek " << i << " krawedz do wierzcholka " << j << " o wadze " << matrix[i][j] << std::endl;

}

int GraphMatrix::dijkstra(int start, int end){
    vector<int> route(V, INT_MAX);
    route[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    queue.push(make_pair(0, start));
    while(queue.empty()!=1){
        int u = queue.top().second;
        queue.pop();
        if(u == end) return route[u];

        for (int i = 0; i < V; ++i) {
            if (matrix[u][i] != 0) {
                int w = matrix[u][i];
                if (route[i] > route[u] + w) {
                    route[i] = route[u] + w;
                    queue.push({route[i], i});
                }
            }
        }
    }
    return -1;//start doesn't have a path to end
}

