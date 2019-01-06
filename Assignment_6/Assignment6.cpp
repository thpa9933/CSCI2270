//Thomas Payne
//Assignment 6
#include "MovieTree.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]){
  
    MovieTree Object;

/////reading in file////
    ifstream file;
    file.open(argv[1]);
    if(file.is_open()){
        string line;
        while(getline(file, line)){
            string word;
            stringstream ss(line);
            string array[4];
            int i = 0;
            while(getline(ss, word, ',')){
                array[i++] = word;
            }
            Object.addMovieNode(stoi(array[0]), array[1], stoi(array[2]), stoi(array[3]));
        }
    }
    else{
        cout << "file was not read in properly" << endl;
    }
    
/////////////////////
    
    cout << "======Main Menu======" << endl;
    cout << "1. Find a movie" << endl;
    cout << "2. Rent a movie" << endl;
    cout << "3. Print the inventory" << endl;
    cout << "4. Delete a movie" << endl;
    cout << "5. Count the movies" << endl;
    cout << "6. Quit" << endl;
    
    int number;
    cin >> number;
    
    while(number != 0){
        if(number == 1){
            string input1;
            cout << "Enter a movie to find: " << endl;
            getline(cin.ignore(), input1);
            Object.findMovie(input1);
        }

        if(number == 2){
            string input1;
            cout << "Enter a movie to rent: " << endl;
            getline(cin.ignore(), input1);
            Object.rentMovie(input1);
        }

        if(number == 3){
            Object.printMovieInventory();
        }

        if(number == 4){
            string input1;
            cout << "Enter a movie to delete: " << endl;
            getline(cin.ignore(), input1);
            Object.deleteMovieNode(input1);
        }

        if(number == 5){
            int x = Object.countMovieNodes();
            cout << x << endl;
        }

        if(number == 6){
            cout << "Goodbye!" << endl;
            break;
        }
        
        cout << "======Main Menu======" << endl;
        cout << "1. Find a movie" << endl;
        cout << "2. Rent a movie" << endl;
        cout << "3. Print the inventory" << endl;
        cout << "4. Delete a movie" << endl;
        cout << "5. Count the movies" << endl;
        cout << "6. Quit" << endl;
        
        cin >> number;
    }
    return 0;
}
