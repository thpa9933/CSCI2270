//Thomas Payne
//Assignment 8

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
        while(getline(citySS, word, ',')){
            if(word == "cities"){
                continue;
            }
            //cout << word << endl;
            graph.addVertex(word);
            temp.push_back(word);                           //adds CITY NAMES to temp vector
        }
        
        string line, city, weight;
        int Weight;
        int i = 0;
        int j = 0;
        while(getline(file, line)){                         //creates a variable to denote which city is selected
            i = 0;
            stringstream SS(line);
            
            getline(SS, city, ',');
            //cout << city << endl;
            
            while(getline(SS, weight, ',')){
                Weight = stoi(weight);
                if(Weight > 0 && i > j){
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
    
    /////////////////////
    
    cout << "======Main Menu======" << endl;
    cout << "1. Print vertices" << endl;
    cout << "2. Vertex adjacent" << endl;
    cout << "3. Quit" << endl;
    
    int number;
    cin >> number;
    
    while(number != 0){
        if(number == 1){
            graph.displayEdges();
        }
        
        if(number == 2){
            string input1;
            string input2;
            cout << "Enter first city:" << endl;
            getline(cin.ignore(), input1);
            cout << "Enter second city:" << endl;
            getline(cin, input2);
            graph.isAdjacent(input1, input2);
            
            //cout << input1 << endl;
            //cout << input2 << endl;
            
        }
        
        if(number == 3){
            cout << "Goodbye!" << endl;
            break;
        }
        
        cout << "======Main Menu======" << endl;
        cout << "1. Print vertices" << endl;
        cout << "2. Vertex adjacent" << endl;
        cout << "3. Quit" << endl;
        
        cin >> number;
    }
    return 0;
}
