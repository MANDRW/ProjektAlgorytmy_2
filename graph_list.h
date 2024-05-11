#ifndef PIAA_PROJ2_GRAPH_LIST_H
#define PIAA_PROJ2_GRAPH_LIST_H
#include<vector>
#include"edge.h"
#include"base.h"

class GraphList: public Base{
    private:
        std::vector<std::vector<edge>> list;
        int V;//ilosc wierzchołkow
    public:
        GraphList(int V);
        void incidentEdges(int v);
        void insertVertex();
        void insertEdge(int v, int u, int w);
        void removeEdge(int v, int u);
        void printGraph();
        int dijkstra(int start, int end);
        std::vector<int>dijkstra_all(int start);
        int getV();
};
#endif
