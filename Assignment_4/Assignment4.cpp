#include "CommunicationNetwork.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]){
    CommunicationNetwork Object;
    
    cout << "======Main Menu======" << endl;
    cout << "1. Build Network" << endl;
    cout << "2. Print Network Path" << endl;
    cout << "3. Transmit Message Coast-To-Coast" << endl;
    cout << "4. Add City" << endl;
    cout << "5. Delete City" << endl;
    cout << "6. Clear Network" << endl;
    cout << "7. Quit" << endl;
    
    int number;
    cin >> number;
    
    while(number != 0){
        if(number == 1){
            Object.buildNetwork();
            
        }
        
        if(number == 2){
            Object.printNetwork();
        }

        if(number == 3){
            Object.transmitMsg(argv[1]);
        }

        if(number == 4){
            string input1;
            string input2;
            cout << "Enter a City name:" << endl;
            getline(cin.ignore(), input2);
            cout << "Enter a previous City name:" << endl;
            getline(cin, input1);
            Object.addCity(input2, input1);
        }
        
        if(number == 5){
            string input1;
            cout << "Enter a City name:" << endl;
            getline(cin.ignore(), input1);
            Object.deleteCity(input1);
        }
        
        if(number == 6){
            Object.deleteNetwork();
        }
        
        if(number == 7){
            cout << "Goodbye!" << endl;
            break;
        }

        cout << "======Main Menu======" << endl;
        cout << "1. Build Network" << endl;
        cout << "2. Print Network Path" << endl;
        cout << "3. Transmit Message Coast-To-Coast" << endl;
        cout << "4. Add City" << endl;
        cout << "5. Delete City" << endl;
        cout << "6. Clear Network" << endl;
        cout << "7. Quit" << endl;
        
        cin >> number;
    }
    
    return 0;
}
