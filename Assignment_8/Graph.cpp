//Thomas Payne
//Assignment 9

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Graph.h"
using namespace std;

//Graph::Graph(){
//    //constructor
//}
//Graph::~Graph(){
//    //destructor
//}

void Graph::addVertex(string name){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == name){
            found = true;
            cout << vertices[i].name << " already in the graph." << endl;
        }
    }
    if(found == false){
        vertex v;
        v.name = name;
        vertices.push_back(v);
        //cout << "Vertex (vector) Added" << endl;
    }
}

void Graph::addEdge(string v1, string v2, int weight){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i < j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av); //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::displayEdges(){
    for(int i = 0; i < vertices.size(); i++){           //loop through all vertices and adjacent vertices
        cout << vertices[i].name << "-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout << vertices[i].adj[j].v -> name << "***";
        }
        cout << endl;
    }
}

int Graph::isAdjacent(string v1, string v2){
    for(int i = 0; i < vertices.size(); i++){
        if(v1 == vertices[i].name){
            for(int j = 0; j < vertices[i].adj.size(); j++){
                if(v2 == vertices[i].adj[j].v -> name){
                    //cout << "in here" << endl;
                    return 1;
                }
            }
        }
    }
    return 0;
}


