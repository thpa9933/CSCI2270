
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Graph.h"
using namespace std;

int main(int argc, char *argv[]){
    /////reading in file////
    vector<string> temp;
    Graph graph;
    ifstream file;
    file.open(argv[1]);
    if(file.is_open()){
        string lineOne, word;
        getline(file, lineOne);                             //skips the first line
        stringstream citySS(lineOne);
        while(getline(citySS, word, ' ')){
            if(word == "dest/source"){
                continue;
            }
            //cout << word << endl;
            graph.addVertex(word);
            temp.push_back(word);
        }
        
        string line, city, weight;
        int Weight;
        int i = 0;
        int j = 0;
        while(getline(file, line)){
            i = 0;
            stringstream SS(line);
            
            getline(SS, city, ' ');                 //skips the first word (city) in the list of adjanencys
            //cout << city << endl;
            
            while(getline(SS, weight, ' ')){
                Weight = stoi(weight);
                if(Weight > 0){
                    graph.addEdge(city, temp[i], Weight);
                    //graph.displayEdges();
                }
                i++;
            }
            j++;
        }
        //graph.displayEdges();
    }
    else{
        cout << "file was not read in properly" << endl;
    }
    graph.displayEdges();
}

