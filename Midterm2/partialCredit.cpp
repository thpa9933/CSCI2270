bool Graph::ifPathExistsLessThanDist(string vertex1, string vertex2, int dist) {
    vertex *start;
    for (int i = 0; i < (int)vertices.size(); i++) {
        vertices[i].visited = false;
        if (vertices[i].name == vertex1) {
            start = &vertices[i];
        }
    }
    
    queue<vertex*> Q;
    Q.push(start);
    start->visited = true;
    vector <vertex*> Vec;
    while (!Q.empty()) {
        vertex *node = Q.front();
        Q.pop();
        for(unsigned int i = 0; i < node -> adj.size(); i++){
            if(!node -> adj[i].v -> visited){
                node -> adj[i].v -> visited = true;
                Q.push(node -> adj[i].v);
                Vec.push_back(node -> adj[i].v);
                if(node -> adj[i].v -> name == vertex2){
                    break;
                }
            }
        }
    }
    int size = Vec.size();
    if(size < dist){
        return true;
    }
    else{
        return false;
    }
}



bool Graph::ifPathExistsLessThanDist(string vertex1, string vertex2, int dist) {
    vertex *start;
    for (int i = 0; i < (int)vertices.size(); i++) {
        vertices[i].visited = false;
        if (vertices[i].name == vertex1) {
            start = &vertices[i];
        }
    }
    
    queue<vertex*> Q;
    Q.push(start);
    start->visited = true;
    vector <vertex*> Vec;
    int count = 0;
    while (!Q.empty()) {
        vertex *node = Q.front();
        Q.pop();
        count = 0;
        for(unsigned int i = 0; i < node -> adj.size(); i++){
            if(!node -> adj[i].v -> visited){
                node -> adj[i].v -> visited = true;
                Q.push(node -> adj[i].v);
                Vec.push_back(node -> adj[i].v);
                
                if(node -> adj[i].v -> name == vertex2){
                    break;
                }
            }
            count++;
        }
    }
    if(count < dist){
        return true;
    }
    else{
        return false;
    }
}
