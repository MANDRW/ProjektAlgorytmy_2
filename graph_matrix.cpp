#include "graph_matrix.h"
#include<iostream>

GraphMatrix::GraphMatrix(int V){
    this->V = V;
    matrix.resize(V, std::vector<int>(V, 0));
}

void GraphMatrix::incidentEdges(int v){
    for(int i = 0; i < V; i++){
        if(matrix[v][i] != 0){
            std::cout << "Krawedzie incydentne wierzcholka" <<v<< i << " waga: " << matrix[v][i] << std::endl;
        }
    }
}

void GraphMatrix::insertVertex(){
    V++;
    matrix.resize(V, std::vector<int>(V,0));
}

void GraphMatrix::insertEdge(int v, int u, int w){
    matrix[v][u] = w;
    matrix[u][v] = w;
}

void GraphMatrix::removeEdge(int v, int u){
    matrix[v][u] = 0;
    matrix[u][v] = 0;
}

void GraphMatrix::removeVertex(int v){
    matrix.erase(matrix.begin() + v);
    V--;
    for(int i = 0; i < V; i++){
        matrix[i].erase(matrix[i].begin() + v);
    }
}

void GraphMatrix::printGraph() {
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            if(matrix[i][j]!=0)
                std::cout << "Wierzcholek " << i << " krawedz do wierzcholka " << j << " o wadze " << matrix[i][j] << std::endl;

}

