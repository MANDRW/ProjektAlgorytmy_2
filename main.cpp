#include<iostream>
#include "graph_list.h"
#include "graph_matrix.h"
using namespace std;

int main(){
    GraphList g1(5);
    g1.insertEdge(0,3,4);
    g1.insertEdge(1,4,5);
    g1.insertEdge(1,2,2);
    g1.insertEdge(2,3,14);
    g1.insertEdge(3,4,8);
    cout<<g1.dijkstra(1,0)<<endl;

    return 0;
}