#ifndef PIAA_PROJ2_GRAPH_MATRIX_H
#define PIAA_PROJ2_GRAPH_MATRIX_H
#include <vector>
#include "base.h"
class GraphMatrix: public Base{
    private:
        std::vector<std::vector<int>> matrix;
        int V;//ilosc wierzchołkow
    public:
        GraphMatrix(int V);
        void incidentEdges(int v);
        void insertVertex();
        void insertEdge(int v, int u, int w);
        void removeEdge(int v, int u);
        void printGraph();
        int dijkstra(int start, int end);
        std::vector<int> dijkstra_all(int start);
        int getV();
};
#endif
