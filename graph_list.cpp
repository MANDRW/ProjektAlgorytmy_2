#include "graph_list.h"
#include<iostream>

GraphList::GraphList(int V){
    this->V = V;
    list.resize(V);
}

void GraphList::incidentEdges(int v){
    for(int i = 0; i < list[v].size(); i++){
        std::cout << "Krawedzie incydentne wierzcholka" <<v<< list[v][i].v << " waga: " << list[v][i].w << std::endl;
    }
}

bool GraphList::areAdjacent(int v, int u){
    for(int i = 0; i < list[u].size(); i++){
        if(list[u][i].v == v){
            return 1;
        }
    }
    return 0;
}

void GraphList::insertVertex(int o){
    list.push_back(std::vector<edge>());
    V++;
}

void GraphList::insertEdge(int v, int u, int w){
    edge e;
    e.v = v;
    e.w = w;
    list[v].push_back(e);
    list[u].push_back(e);
}

void GraphList::removeEdge(int v, int u){
    for(int i = 0; i < list[u].size(); i++){
        if(list[u][i].v == v){
            list[u].erase(list[u].begin() + i);
            break;
        }
    }
    for(int i = 0; i < list[v].size(); i++){
        if(list[v][i].v == u){
            list[v].erase(list[v].begin() + i);
            return;
        }
    }
}

void GraphList::removeVertex(int u){
    list.erase(list.begin() + u);
    V--;
    for(int i = 0; i < V; i++){
        for(int j = 0; j < list[i].size(); j++){
            if(list[i][j].v == u){
                list[i].erase(list[i].begin() + j);
            }
        }
    }
}

void GraphList::printGraph(){
    for(int i = 0; i < V; i++){
        std::cout << "Vertex " << i << ": ";
        for(int j = 0; j < list[i].size(); j++){
            std::cout << list[i][j].v << " " << list[i][j].w << " ";
        }
        std::cout << std::endl;
    }
}