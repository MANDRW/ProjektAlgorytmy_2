#ifndef PIAA_PROJ2_GRAPH_LIST_H
#define PIAA_PROJ2_GRAPH_LIST_H
#include<vector>
#include"edge.h"

class GraphList{
    private:
        std::vector<std::vector<edge>> list;
        int V;//ilosc wierzchołkow
    public:
        GraphList(int V);
        void incidentEdges(int v);
        bool areAdjacent(int v, int u);
        void insertVertex();
        void insertEdge(int v, int u, int w);
        void removeEdge(int v, int u);
        void removeVertex(int e);
        void printGraph();
        int dijkstra(int start, int end);
};
#endif
