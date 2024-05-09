#include<iostream>
#include<fstream>
#include<ctime>
#include <cstdlib>
#include <stdio.h>
#include <chrono>
#include <vector>
#include "graph_list.h"
#include "graph_matrix.h"
using namespace std;

int main(){
    srand(time(NULL));
      int size_graph=10;//10,50,100,500,1000
      float prct=0.25;//0.25,0.5,0.75,1.0;
      vector<pair<int,int>> data;
      int q=100;
      fstream file;
    vector<GraphList>tab;
    vector<GraphMatrix>tab2;
    int all_edges = (size_graph*(size_graph-1))/2;
    int edges=all_edges*prct;
    for(int i=0;i<q;i++){
            tab.push_back(GraphList(size_graph));
            tab2.push_back(GraphMatrix(size_graph));
    }
    cout<<"stworzono grafy"<<endl;

      file.open("graph_edges_10.txt",ios::in);
      for (int i = 0;!file.eof(); i++) {
          string t1,t2;
          int s, e;
          getline(file,t1,' ');
          getline(file,t2);
          s = stoi(t1);
          e = stoi(t2);
          data.push_back(make_pair(s,e));
      }
        file.close();
    cout<<"wczytano z pliku"<<endl;
      for(int i=0;i<q;i++) {
          vector<pair<int, int>> temp=data;
            for (int j = 0; edges > j; j++) {
                int r = rand() % temp.size();
                tab[i].insertEdge(temp[r].first, temp[r].second, (rand() % 100)+1);
                tab2[i].insertEdge(temp[r].first, temp[r].second, (rand() % 100)+1);
                temp.erase(temp.begin() + r);
            }
      }
      cout<<"dodano krawedzie"<<endl;
cout<<size_graph<<" wierzcholkow"<<endl<<"wypelnienie " <<prct*100<<"%"<<endl;

//list
    int temp;
      auto begin = std::chrono::high_resolution_clock::now();
      for(int i=0;q>i;i++){
          temp=tab[i].dijkstra(0,(rand()%(size_graph-1))+1);
      }
      auto end = std::chrono::high_resolution_clock::now();
      auto time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
       cout<<"lista czas "<<time.count()/q<<" ns"<<endl;

     //matrix
      begin = std::chrono::high_resolution_clock::now();
        for(int i=0;q>i;i++){
        temp=tab2[i].dijkstra(0,(rand()%(size_graph-1))+1);
        }
      end = std::chrono::high_resolution_clock::now();
      time = std::chrono::duration_cast<std::chrono::nanoseconds >(end - begin);
      cout<<"macierz czas: "<<time.count()/q<<" ns"<<endl;




    return 0;
}