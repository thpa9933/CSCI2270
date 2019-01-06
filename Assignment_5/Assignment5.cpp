//Thomas Payne
//Assignment 5
#include "Queue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]){
    Queue Object(10);
    
    cout << "======Main Menu======" << endl;
    cout << "1. Enqueue word" << endl;
    cout << "2. Dequeue word" << endl;
    cout << "3. Print queue" << endl;
    cout << "4. Enqueue sentence" << endl;
    cout << "5. Quit" << endl;
    
    int number;
    cin >> number;
    
    while(number != 0){
        if(number == 1){
            string input1;
            cout << "Enter a word to enqueue:" << endl;
            getline(cin.ignore(), input1);
            Object.enqueue(input1);
        }

        if(number == 2){
            Object.dequeue();
        }

        if(number == 3){
            Object.printQueue();
        }

        if(number == 4){
            string input1;
            cout << "sentence:" << endl;
            getline(cin.ignore(), input1);
            Object.enqueueSentence(input1);
        }
        
        if(number == 5){
            cout << "Goodbye!" << endl;
            break;
        }
        
        cout << "======Main Menu======" << endl;
        cout << "1. Enqueue word" << endl;
        cout << "2. Dequeue word" << endl;
        cout << "3. Print queue" << endl;
        cout << "4. Enqueue sentence" << endl;
        cout << "5. Quit" << endl;
        
        cin >> number;
    }
    
    return 0;
}
