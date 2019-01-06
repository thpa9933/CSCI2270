//GENERAL ALGO FOR STEPPING THROUGH GRAPH
void Graph::**yourGrahphFunction**(int startVertex) {
    vertex *start;
    for (int i = 0; i < (int)vertices.size(); i++) {
        vertices[i].visited = false;
        if (vertices[i].value == startVertex) {
            start = &vertices[i];
        }
    }
    
    queue<vertex*> Q;
    Q.push(start);
    start->visited = true;
    cout << start->value << endl;
    while (!Q.empty()) {
        vertex *node = Q.front();
        Q.pop();
        for(unsigned int i = 0; i < node -> adj.size(); i++){
            if(!node -> adj[i].v -> visited){
                node -> adj[i].v -> visited = true;
                Q.push(node -> adj[i].v);
                if(**The Condition Your Changing**){
                    cout << what is necessary << endl;
                }
            }
        }
    }
}
    
//WHEN YOU NEED TO MAKE VECTOR STORING ADJ LIST STUFF
void Graph::shortestPath(string source, string destination, string intermediate) {
    vertex *start;
    for (int i = 0; i < (int)vertices.size(); i++) {
        vertices[i].visited = false;
        if (vertices[i].name == source) {
            start = &vertices[i];
        }
    }
    queue<vertex*> Q;
    Q.push(start);
    start -> visited = true;
    start -> prev = NULL;
    vector <vertex*> Vec;
    vertex* endV;
    while (!Q.empty()) {
        vertex *node = Q.front();
        Q.pop();
        for(unsigned int i = 0; i < node -> adj.size(); i++){
            if(!node -> adj[i].v -> visited){
                node -> adj[i].v -> visited = true;
                node -> adj[i].v -> prev = node;
                Q.push(node -> adj[i].v);
                Vec.push_back(node->adj[i].v);
                if(node -> adj[i].v -> name == destination){
                    endV = node -> adj[i].v;
                    break;
                }
            }
        }
    }
    vertex *temp;
    temp = endV;
    bool found = false;
    while(temp){
        if(temp -> name == intermediate){
            cout << "Yes" << endl;
            found = true;
            break;
        }
        temp = temp -> prev;
    }
    if(found == false){
        cout << "No" << endl;
    }
}

//DFS SEARCH ALGO (ASG 9)
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
//________FIND VERTEX
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
