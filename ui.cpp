#include "ui.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdio>
#include<fstream>
#include <string>
#include<vector>
#include"graph_list.h"
#include"graph_matrix.h"
using namespace std;

void ui() {
    while (true) {
        int number, mode;//mode==type of stucture, number==operation
        Base*tab;
        cout << "Wybierz graf: " << endl;
        cout << "[1] Graf na liscie sasiedztwa" << endl;
        cout << "[2] Graf na macierzy sasiedztwa" << endl;
        cout << "[0] Zakoncz" << endl << endl;
        cout << "Wybor: ";
        cin >> mode;
        cout << endl;
        bool start = true;//for closing ui
        switch (mode) {//making structure
            case 1: {
                GraphList *t= new GraphList(5);
                tab=t;
                break;
            }
            case 2: {
                GraphMatrix *t = new GraphMatrix(5);
                tab=t;
                break;
            }
            default: {
                cout << "Program zakonczony";
                return;
            }
        }

        while (start == 1) {
            switch (mode) {
                case 1: {
                    cout << "Graf na liscie sasiedztwa:" << endl;
                    break;

                }
                case 2: {
                    cout << "Graf na macierzy sasiedztwa:" << endl;
                    break;
                }
                default: {
                    cout << "Zly tryb";
                    start = 0;
                    break;
                }
            }
            cout << "[1] Zbuduj z pliku" << endl;
            cout << "[2] Dodaj wierzcholek" << endl;
            cout << "[3] Dodaj krawedz" << endl;
            cout << "[4] Najkrotsza droga miedzy 2 wybranymi wierzcholkami (Dijkstra)" << endl;
            cout << "[5] Najkrotsza droga od wybranego wierzcholka do wszystkich (Dijkstra)" << endl;
            cout << "[6] Wyswietl graf" << endl;
            cout << "[0] Wroc do menu" << endl << endl;
            cout << "Wybor: ";
            cin >> number;
            cout << endl;
            switch (number) {
                case 0: {
                    start = false;
                    delete tab;
                    break;
                }
                case 1: {
                    string name = "";
                    cout << "Podaj nazwe pliku: ";
                    cin >> name;
                    cout << endl;
                    if (tab->getV() != 0) {
                        switch (mode) {
                            case 1: {
                                delete tab;
                                GraphList *temp = new GraphList(5);
                                tab = temp;
                                break;

                            }
                            case 2: {
                                delete tab;
                                GraphMatrix *temp = new GraphMatrix(5);
                                tab = temp;
                                break;
                            }
                        }
                    }
                    fstream file;
                    vector<pair<int,int>> data;
                    vector<int> weight;
                    file.open(name, ios::in);//uploading data
                    for (int i = 0; !file.eof(); i++) {
                        string t1,t2,t3;
                        getline(file,t1,' ');
                        getline(file,t2,' ');
                        getline(file,t3);
                        int s = stoi(t1);
                        int d = stoi(t2);
                        int w = stoi(t3);
                        data.push_back(make_pair(s,d));
                        weight.push_back(w);
                    }
                    file.close();
                    for (int i = 0; tab->getV()> i; i++) {
                        tab->insertEdge(data[i].first, data[i].second, weight[i]);
                    }
                    cout << endl << "Wczytano" << endl << endl;
                    break;
                }
                case 2: {
                    tab->insertVertex();
                    cout << endl << "Dodano " <<tab->getV()<<" wierzcholek"<<endl << endl;
                    break;
                }
                case 3: {
                    int a, b,w;
                    cout << "Podaj wierzcholek poczatkowy krawedzi: ";
                    cin>>a;
                    cout <<endl<<"Podaj wierzcholek koncowy krawedzi ";
                    cin>>b;
                    cout<<endl<<"Podaj wage krawedzi: ";
                    cin>>w;
                    tab->insertEdge(a,b,w);
                    cout << endl << "Dodano krawedz" << endl << endl;
                    break;
                }
                case 4: {
                    int start, end;
                    cout << "Podaj wierzcholek startowy: ";
                    cin >> start;
                    cout <<endl<< "Podaj wierzcholek koncowy: ";
                    cin >> end;
                    cout << endl << "Najkrotsza droga miedzy wierzcholkami: " << tab->dijkstra(start, end) << endl << endl;
                    break;
                }
                case 5: {
                    vector<int> route;
                    int start, end;
                    cout << "Podaj wierzcholek startowy: ";
                    cin >> start;
                    route=tab->dijkstra_all(start);
                    cout << endl << "Krawedzie od wierzcholka " <<start<<":"<< endl;
                    for(int i=0;i<route.size();i++){
                        cout<<"do wierzcholka "<<i<<" o wadze "<<route[i]<<endl;
                    }
                    break;
                }
                case 6:{
                    tab->printGraph();
                    break;
                }
                default: {
                    start = false;
                    break;
                }
            }
        }
    }
}
