//Thomas Payne
//Assignment 9

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include "Graph.hpp"
using namespace std;

Graph::Graph(){
    //constructor
}
Graph::~Graph(){
    //destructor
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
        v.districtID = -1;
        vertices.push_back(v);
    }
}

void Graph::displayEdges(){
    for(int i = 0; i < vertices.size(); i++){           //loop through all vertices and adjacent vertices
        cout << vertices[i].districtID << ":" << vertices[i].name << "-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout << vertices[i].adj[j].v -> name;
            if (j != vertices[i].adj.size()-1){
                cout<<"***";
            }
        }
        cout << endl;
    }
}

vertex * Graph::findVertex(string value) {
    int i=0;
    while (i < vertices.size()) {
        if (vertices[i].name == value) {
            return &vertices[i];
        }
        i++;
    }
    return nullptr;
}

/*
 Call this from within assignDistricts to label the districts.
 This method should implement a depth first search from the
 startingCity and assign all cities encountered the distID value.
 */
void Graph::DFSLabel(std::string startingCity, int distID){
    vertex *startVert = findVertex(startingCity);
    if(startVert != nullptr){
        startVert -> visited = true;
        startVert -> districtID = distID;
        stack <vertex*> vStack;
        vStack.push(startVert);
        while(vStack.size() != 0){
            vertex *curV = vStack.top();
            vStack.pop();
            for(int i = 0; i < curV -> adj.size(); i++){
                if(!curV -> adj[i].v -> visited){
                    curV -> adj[i].v -> districtID = distID;
                    curV -> adj[i].v -> visited = true;
                    vStack.push(curV -> adj[i].v);
                }
            }
        }
    }
}

void Graph::assignDistricts(){
    int count = 1;
    int counter = 1;
    for(int i = 0; i < vertices.size(); i++){
        vertices[i].visited = false;
    }
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].visited == true){
            counter = vertices[i].districtID;
            DFSLabel(vertices[i].name, counter);
        }
        else{
            DFSLabel(vertices[i].name, count);
            count++;
        }
    }
}

void Graph::shortestPath(string startingCity, string endingCity){
    vertex *startVert = findVertex(startingCity);
    vertex *endVert = findVertex(endingCity);
    for(int i = 0; i < vertices.size(); i++){
        vertices[i].visited = false;
        vertices[i].unweightedDistance = std::numeric_limits<int>::max();
    }
    if(startVert == nullptr || endVert == nullptr){
        cout << "One or more cities doesn't exist" << endl;
    }
    else if(startVert -> districtID == endVert -> districtID){
        startVert -> visited = true;
        startVert ->  unweightedDistance = 0;
        startVert -> parent = nullptr;
        queue<vertex*>  vertexQ;
        vertexQ.push(startVert);
        
        while(vertexQ.size() != 0){
            vertex *curV = vertexQ.front();
            vertexQ.pop();
            for(int i = 0; i < curV -> adj.size(); i++){
                if(!curV -> adj[i].v -> visited){
                    curV -> adj[i].v -> visited = true;
                    vertexQ.push(curV -> adj[i].v);
                    if(curV -> adj[i].v -> unweightedDistance > curV -> unweightedDistance + 1){ // if the adjacent is greater than the vertex node + 1
                        curV -> adj[i].v -> parent = curV;
                        curV -> adj[i].v -> unweightedDistance = curV -> unweightedDistance + 1;
                    }
                    if(curV -> name == endVert -> name){
                        break;
                    }
                }
            }
        }
        vertex *temp = endVert;
        vector <string> Vec;
        cout << endVert -> unweightedDistance << ", " << startingCity;
        while(temp -> name != startingCity){
            Vec.push_back(temp -> name);
            temp = temp -> parent;
        }
        for(int i = Vec.size() - 1; i >= 0; i--){
            cout << ", " << Vec[i];
        }
        cout << endl;
    }
    else if(startVert -> districtID != endVert -> districtID){
        cout << "No safe path between cities" << endl;
    }
}

void Graph::shortestWeightedPath(string startingCity, string endingCity){
    vertex* startVert = findVertex(startingCity);
    vertex* endVert = findVertex(endingCity);
    int curDist;
    int minDistance;
    vertex* solvedVertex;
    vertex* curV;
    vertex* curParent;
    for(int i = 0; i < vertices.size(); i++){
        vertices[i].visited = false;
        vertices[i].weightedDistance = std::numeric_limits<int>::max();
    }
    if(startVert == nullptr || endVert == nullptr){
        cout << "One or more cities doesn't exist" << endl;
    }
    if(startVert -> districtID > 0){
        if(startVert -> districtID == endVert -> districtID){
            startVert -> visited = true;
            startVert -> weightedDistance = 0;
            vector<vertex*> solvedVertices;
            solvedVertices.push_back(startVert);
            while(!endVert -> visited){ //keep going untill we have solved the end verticies
                minDistance = INT_MAX;  //solvedVertex = nullptr;
                for(int i = 0; i < solvedVertices.size(); i++){ //going through the adjacency list
                    curV = solvedVertices[i];
                    for(int j = 0; j < curV -> adj.size(); j++){
                        if(!curV -> adj[j].v -> visited){      //if the vertex is not solved
                            curDist = curV -> weightedDistance + curV -> adj[j].weight;
                            if(curDist < minDistance){
                                solvedVertex = curV -> adj[j].v;
                                minDistance = curDist;
                                curParent = curV;
                            }
                        }
                    }
                }
                solvedVertex -> weightedDistance = minDistance;
                solvedVertex -> parent = curParent;
                solvedVertex -> visited = true;
                solvedVertices.push_back(solvedVertex);
            }
            vertex *temp = endVert;
            vector <string> Vec;
            cout << endVert -> weightedDistance << ", " << startingCity;
            while(temp -> name != startingCity){
                Vec.push_back(temp -> name);
                temp = temp -> parent;
            }
            for(int i = Vec.size() - 1; i >= 0; i--){
                cout << ", " << Vec[i];
            }
            cout << endl;
        }
        else if(startVert -> districtID != endVert -> districtID){
            cout << "No safe path between cities" << endl;
        }
    }
    else{
        cout << "Please identify the districts before checking distances" << endl;
    }
}
