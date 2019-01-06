
//Thomas Payne
//Assignment 9

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Graph.hpp"
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
            temp.push_back(word);
        }
        
        string line, city, weight;
        int Weight;
        int i = 0;
        int j = 0;
        while(getline(file, line)){
            i = 0;
            stringstream SS(line);
            getline(SS, city, ',');
            
            while(getline(SS, weight, ',')){
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
    
    /////////////////////
    
    cout << "======Main Menu======" << endl;
    cout << "1. Print vertices" << endl;
    cout << "2. Find districts" << endl;
    cout << "3. Find shortest path" << endl;
    cout << "4. Find shortest weighted path" << endl;
    cout << "5. Quit" << endl;
    
    int number;
    cin >> number;
    
    while(number != 0){
        if(number == 1){
            graph.displayEdges();
        }
        
        if(number == 2){
            graph.assignDistricts();
        }
        
        if(number == 3){
            string input1;
            string input2;
            cout << "Enter a starting city:" << endl;
            getline(cin.ignore(), input1);
            cout << "Enter a ending city:" << endl;
            getline(cin, input2);
            graph.shortestPath(input1, input2);
        }
        
        if(number == 4){
            string input1;
            string input2;
            cout << "Enter a starting city:" << endl;
            getline(cin.ignore(), input1);
            cout << "Enter a ending city:" << endl;
            getline(cin, input2);
            graph.shortestWeightedPath(input1, input2);
        }
        
        if(number == 5){
            cout << "Goodbye!" << endl;
            break;
        }
        
        cout << "======Main Menu======" << endl;
        cout << "1. Print vertices" << endl;
        cout << "2. Find districts" << endl;
        cout << "3. Find shortest path" << endl;
        cout << "4. Find shortest weighted path" << endl;
        cout << "5. Quit" << endl;
        
        cin >> number;
    }
    return 0;
}
