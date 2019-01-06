#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    string key;
    vector <adjVertex> adjacent;
    bool visited= false;
    int distance;
    vertex *parent; //add this for BFpath
    bool solved = false; //add this for dijkstra's
};

class Graph{
private:
    //vertices
    vector <vertex> vertices;
    vertex* findVertex(string);
    bool pathComplete;
public:
    //methods
    Graph();
    ~Graph();
    void insertVertex(string);  //indetifier of the vertex
    void insertEdge(string, string, int);  //start, end, weight
    void printGraph();
    void BFTraversal(string);           //start node
    int BFDistanceBetween(string, string);
    void BFPath(string, string);
    void resetGraph();
    void dijkstra(string, string);
};

void Graph::resetGraph(){
    for(int i = 0; i < vertices.size(); i++){
        vertices[i].visited = false;
        vertices[i].parent = nullptr;
        vertices[i].distance = -1;
        vertices[i].solved = false;
    }
}
void Graph::insertVertex(string value){
    bool found = false;
    int i = 0;
    while (i < vertices.size() && !found){
        if(vertices[i].key == value){
            found = true;
        }
        i++;
    }
    if(!found){
        vertex v;
        v.key = value;
        vertices.push_back(v);
    }
    else{
        cout << "There is alread a vertex " << value << " in this graph" << endl;
    }
}

vertex* Graph::findVertex(string value){
    int i = 0;
    while (i < vertices.size()){
        if(vertices[i].key == value){
            return &vertices;
        }
        i++;
    }
    return nullptr;
}

void Graph::insertEdge(string v1, string v2, int weight){
    vertex *vStart = findVertex(v1);
    vertex *vEnd = findVertex(v2);
    if(vStart != nullptr && vEnd != nullptr){
        adjVertex v1v2Edge;
        v1v2Edge.weight = weight;
        v1v2Edge.v = vEnd;
        vStart -> adjacent.push_back(v1v2Edge);
    }
    else{
        if(vStart == nullptr){
            cout << "no vertex with name " << v1 << " in this graph";
        }
        if(vEnd == nullptr){
            cout << "no vertex with name " << v1 << " in this graph";
        }
    }
}

void Graph::BFTraversal(string vertName){
    queue<vertex*> vertexQ;
    vertex* currentVert = findVertex(vertName);
    if(currentVert != nullptr){
        currentVert -> visited = true;
        vertexQ.push(currentVert);
        while(vertexQ.size() != 0){
            vertex* curV = vertexQ.front(); //like peak
            vertexQ.pop(); //like dequeue
            for(int i = 0; i < curV -> adjacent.size(); i++){
                if(!curV -> adjacent[i].v -> visited){
                    curV -> adjacent[i].v -> visited = true;
                    cout << "just visited " << curV -> adjacent[i].v -> key << endl;
                    vertexQ.push(curV -> adjacent[i].v);
                }
            }
        }
    }
    else{
        cout << "vertex " << vertName << " not in graph" << endl;
    }
}

int Graph::BFDistanceBetween(string startVertKey, string endVertKey){
    vertex *startVert = findVertex(startVertKey);
    vertex *endVert = findVertex(endVertKey);
    if(startVert != nullptr && endVert != nullptr){
        startVert -> visited = true;
        startVert -> distance = 0;
        queue<vertex*> vertexQ;
        vertexQ.push(startVertKey);
        
        while(vertexQ.size() != 0){
            vertex* curV = vertexQ.front();
            vertexQ.pop();
            for(int i = 0; curV -> adjacent.size(); i++){
                if(!curV -> adjacent[i].v -> visited){
                    curV -> adjacent[i].v -> distance = curV -> distance + 1;
                    if(curV -> adjacent[i].v -> key == endVertKey){
                        return curV -> adjacent[i].v -> distance;
                    }
                    else{
                        curV -> adjacent.v -> visited = true;
                        vertexQ.push(curV -> adjacent[i].v);
                    }
                }
            }
        }
    }
    else{
        if(startVert == nullptr){
            cout << "That vertice does not exist" << endl;
        }
        if(endVert == nullptr){
            cout << "That vertice does not exist" << endl;
        }
        return -1;
    }
    //if we get here that means there is no connection
    cout << "no connection between " << startVertKey << " and " << endVertKey << endl;
}

void Graph::BFPath(string startVertKey, string endVertKey){
    vertex *startVert = findVertex(startVertKey);
    vertex *endVert = findVertex(endVertKey);
    if(startVert != nullptr && endVert != nullptr){
        startVert -> visited = true;
        startVert -> distance = 0;
        startVert -> parent = nullptr;
        queue<vertex*>  vertexQ;
        vertexQ.push(startVert);
        while(vertexQ.size() != 0 && !pathComplete){
            vertex *curV = vertexQ.front();
            vertexQ.pop();
        
            for(int i = 0; i < curV -> adjacent.size(); i++){
                if(!curV -> adjacent[i].v -> visited){
                    curV -> adjacent[i].v -> distance = curV -> distance + 1;
                    curV -> adjacent[i].v -> parent = curV;
                    if(curV -> adjacent[i].v -> key == endVertKey){
                        pathComplete = true;
                        break;
                    }
                    else{
                        curV -> adjacent[i].v -> visited = true;
                        vertexQ.push(curV -> adjacent[i].v);
                    }
                }
            }
        }
    }
}

//This implimentation assumes there is a path between startvertkey and endvertkey
void Graph::dijkstra(string startVertKey, string endVertKey){
    vertex* starVert = findVertex(startVertKey);
    vertex* endVert = findVertex(endVertKey);
    int curDist;
    int minDistance;
    vertex* solvedVertex;
    vertex* curV;
    vertex* curParent;
    if(startVert != nullptr && endVert != nullptr){
        startVert -> solved = true;
        startVert -> distance = 0;
        vector<vertex*> solvedVertices;
        solvedVertices.push_back(startVert);
        while(!endVert -> solved){ //keep going untill we have solved the end verticies
            minDistance = INT_MAX;
            //solvedVertex = nullptr;
            for(int i = 0; i < solvedVertices.size(); i++){ //going through the adjacency list
                curV = solvedVertices[i];
                for(int j = 0; j < curV -> adjacent.size(); j++){
                    if(!curV -> adjacent[j].v -> solved){      //if the vertex is not solved
                        curDist = curV -> distance + curV -> adjacentk[j].weight;   //adds up the weight from the prior vertices
                        if(curDist < minDistance){
                            solvedVertex = curV -> adjacent[j].v;
                            minDistance = curDist;
                            curParent = curV;
                        }
                    }
                }
            }
            solvedVertex -> distance = minDistance;
            solvedVertex -> parent = curParent;
            solvedVertex -> solved = true;
            solvedVertices.push_back(solvedVertex);
        }
        cout << "shortest path from " << startVertKey << " to " << endVertKey << " is " << endVert -> distance << endl; 
    }
    else{
        //handle error cases
    }
}

int main(){
//    vector<int> vectorOfInts;
//    vectorOfInts.push_back(5);
//    vectorOfInts.push_back(10);
//    vectorOfInts.push_back(15);
//
//    for(int i = 0; i < vectorOfInts.size(); i++){
//        cout << "item " << i << " is " << vectorOfInts[i] << endl;
//    }
    
    return 0;


Graph myGraph;
myGraph.insertVertex("South Boulder");
myGraph.insertVertex("Glacier Ice Cream");
myGraph.insertVertex("Golden");
myGraph.insertVertex("Superior");
myGraph.insertVertex("Superior Costco");
myGraph.insertVertex("Wildwood Guitars");
myGraph.insertVertex("Denver");
myGraph.insertVertex("Rep Fitness");
myGraph.insertVertex("IKEA");
                     
myGraph.insertEdge("South Boulder", "Glacier Ice Cream", 1);
myGraph.insertEdge("Glacier Ice Cream", "South Boulder", 1);
myGraph.insertEdge("South Boulder", "Superior", 5);
myGraph.insertEdge("South Boulder", "Golden", 15);
myGraph.insertEdge("Golden", "South Boulder", 15);
myGraph.insertEdge("Superior", "Superior Costco", 15);
myGraph.insertEdge("Superior Costco", "Superior", 1);
myGraph.insertEdge("Superior", "Wildwood Guitars", 1);
myGraph.insertEdge("Superior", "Denver", 10);
myGraph.insertEdge("Denver", "Superior", 10);
myGraph.insertEdge("Denver", "Golden", 15);
myGraph.insertEdge("Denver", "Rep Fitness", 3);
myGraph.insertEdge("Denver", "IKEA", 20);
    
    cout << "BFT starting at South Boulder" << endl;
    myGraph.BFTraversal("South Boulder");
}
