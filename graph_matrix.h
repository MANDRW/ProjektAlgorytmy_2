#ifndef PIAA_PROJ2_GRAPH_MATRIX_H
#define PIAA_PROJ2_GRAPH_MATRIX_H
#include <vector>
class GraphMatrix{
    private:
        std::vector<std::vector<int>> matrix;
        int V;//ilosc wierzchołkow
    public:
        GraphMatrix(int V);
        void incidentEdges(int v);
        bool areAdjacent(int v, int u);
        void insertVertex();
        void insertEdge(int v, int u, int w);
        void removeEdge(int v, int u);
        void printGraph();
        int dijkstra(int start, int end);
};
#endif
