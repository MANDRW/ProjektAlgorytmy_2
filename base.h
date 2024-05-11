#ifndef PIAA_PROJ2_BASE_H
#define PIAA_PROJ2_BASE_H
#include <vector>
class Base{
    public:
    virtual void incidentEdges(int v)=0;
    virtual void insertVertex()=0;
    virtual void insertEdge(int v, int u, int w)=0;
    virtual void removeEdge(int v, int u)=0;
    virtual void printGraph()=0;
    virtual int dijkstra(int start, int end)=0;
    virtual std::vector<int> dijkstra_all(int start)=0;
    virtual int getV()=0;
    virtual ~Base(){};
};

#endif
