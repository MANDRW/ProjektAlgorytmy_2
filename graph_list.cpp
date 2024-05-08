#include "graph_list.h"
#include<iostream>
#include <queue>
#include <vector>

using namespace std;

GraphList::GraphList(int V){
    this->V = V;
    list.resize(V);
}

void GraphList::incidentEdges(int v){
    for(int i = 0; i < list[v].size(); i++){
        cout << "Krawedzie incydentne wierzcholka" <<v<< list[v][i].v << " waga: " << list[v][i].w << std::endl;
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

void GraphList::insertVertex(){
    list.push_back(std::vector<edge>());
    V++;
}

void GraphList::insertEdge(int v, int u, int w){
    edge e1,e2;
    e1.v = v;
    e2.v = u;
    e1.w=e2.w=w;
    list[v].push_back(e2);
    list[u].push_back(e1);
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
        cout << "Wierzcholek " << i << ": ";
        for(int j = 0; j < list[i].size(); j++){
            cout <<"krawedz: "<< list[i][j].v << " waga: " << list[i][j].w << " ";
        }
        cout<<endl;
    }
}

int GraphList::dijkstra(int start, int end){
    vector<int> route(V, INT_MAX);
    route[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    queue.push(make_pair(0, start));
    while(queue.empty()!=1){
        int u = queue.top().second;
        queue.pop();
        if(u == end) return route[u];

        for (int i = 0; i < list[u].size(); i++) {
            int v = list[u][i].v;
            unsigned w = list[u][i].w;
            if (route[v] > route[u] + w) {
                route[v] = route[u] + w;
                queue.push(make_pair(route[v], v));
            }
        }
    }
    return -1;
}