//Thomas Payne
//Final Project
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <queue>
#include <fstream>
#include "binaryHeap.cpp"
#include "linkedList.cpp"
using namespace std;



int main(int argc, char *argv[]){

    ofstream outFile;
    outFile.open(argv[2]);

    string Data[880];
    ifstream file;
    file.open(argv[1]);
    int count = 0;
    if(file.fail()){
        cout << "File not opened properly" << endl;
    }
    else{
        string lineOne, line;
        getline(file, lineOne,'\r');         //skips first line
        while(getline(file, line,'\r')){
            Data[count] = line;
            count++;
        }
    }
    
    //////////////////
    
    PriorityQueue BinHeap;
    LinkedListQueue LL;
    
    
    cout << "======Main Menu======" << endl;
    cout << "1. Linked List Enqueue/Dequeue Average time, n items, x500" << endl;
    cout << "2. Binary Heap Enqueue/Dequeue Average time, n items, x500" << endl;
    cout << "3. Dequeue LL" << endl;
    cout << "4. Dequeue heap" << endl;
    cout << "5. Dequeue all LL" << endl;
    cout << "6. Dequeue all heap" << endl;
    cout << "7. PrintHeap" << endl;
    cout << "8. PrintLL" << endl;
    cout << "9. STL Enqueue/Dequeue Average time, n items, x500" << endl;
    cout << "10. Quit" << endl;
    
    int number;
    cin >> number;
    
    while(number != 0){
        if(number == 1){
            cout << "How many people would you like to enqueue?" << endl;
            int num;
            cin >> num;
            
            outFile << "\n" << "====== " <<  "LL " << num << " ======" << "\n";
            
            for(int k = 0; k < 500; k++){
                auto start = chrono::system_clock::now();
                string person, firstPri, secondPri, line, deleteLine;
                for(int i = 0; i < num; i++){
                    line = Data[i];
                    stringstream ss(line);
                    getline(ss, person, ',');
                    getline(ss, firstPri, ',');
                    getline(ss, secondPri, ',');
                    LL.enqueue(person, stoi(firstPri), stoi(secondPri));
                }
                for(int j = 0; j < num; j++){
                    LL.dequeue();
                }
                auto end = chrono::system_clock::now();
                auto timeElapsed = chrono::duration<float>(end - start);
                outFile << timeElapsed.count() << "\n";
            }
        }
    
        if(number == 2){
            cout << "How many people would you like to enqueue?" << endl;
            int num;
            cin >> num;
            
            outFile << "\n" << "====== " <<  "Heap " << num << " ======" << "\n";
            
            for(int k = 0; k < 500; k++){
                auto start = chrono::system_clock::now();
                string person, firstPri, secondPri, line, deleteLine;
                for(int i = 0; i < num; i++){
                    line = Data[i];
                    stringstream ss(line);
                    getline(ss, person, ',');
                    getline(ss, firstPri, ',');
                    getline(ss, secondPri, ',');
                    //cout << person << " : " << i << " : " << firstPri << " : " << secondPri << endl;
                    BinHeap.enqueue(person, stoi(firstPri), stoi(secondPri));
                }
                for(int j = 0; j < num; j++){
                    BinHeap.dequeue();
                }
                auto end = chrono::system_clock::now();
                auto timeElapsed = chrono::duration<float>(end - start);
                outFile << timeElapsed.count() << "\n";
            }
        }
    
        if(number == 3){
            LL.dequeue();
        }
        
        if(number == 4){
            BinHeap.dequeue();
        }
        
        if(number == 5){
            for(int i = 0; i < 880; i++){
                LL.dequeue();
            }
        }
        
        if(number == 6){
            for(int i = 0; i < 880; i++){
                bool something = BinHeap.dequeue();
                if(something == true){
                    cout << "item deq" << endl;
                }
                else{
                    cout << "item not deq" << endl;
                }
            }
        }
        if(number == 7){
            BinHeap.printPQ();
        }
        if(number == 8){
            LL.printLL();
        }
        
        /////////////////STL///////////////////////////////
        struct patient{
            string itemName;
            int primaryPriority;
            int secondaryPriority;
            patient(string pName = "", int pri = 0, int secPri = 0){
                itemName = pName;
                primaryPriority = pri;
                secondaryPriority = secPri;
            }
        };
        
        struct compare{
            bool operator()(const patient &a, const patient &b){
                if(a.primaryPriority > b.primaryPriority){
                    return a.primaryPriority > b.primaryPriority;
                }
                else if(a.primaryPriority == b.primaryPriority){
                    if(a.secondaryPriority < b.secondaryPriority){
                        return a.secondaryPriority > b.secondaryPriority;
                    }
                    else{
                        return b.secondaryPriority;
                    }
                }
                return a.primaryPriority > b.primaryPriority;
            }
        };
        
        if(number == 9){
            priority_queue<patient, vector<patient>, compare> pq;
            cout << "How many people would you like to enqueue?" << endl;
            int num;
            cin >> num;
            
            outFile << "\n" <<  "====== " <<  "STL " << num << " ======" << "\n";
            
            for(int k = 0; k < 500; k++){
                auto start = chrono::system_clock::now();
                string person, firstPri, secondPri, line, deleteLine;

                for(int i = 0; i < num; i++){
                    line = Data[i];
                    stringstream ss(line);
                    getline(ss, person, ',');
                    getline(ss, firstPri, ',');
                    getline(ss, secondPri, ',');
                    patient p(person, stoi(firstPri), stoi(secondPri));
                    pq.push(p);
                }
                for(int j = 0; j < num; j++){
                    patient temp = pq.top();
                    pq.pop();
                    //cout << j << ": " << temp.itemName << ", " << temp.primaryPriority << ", " << temp.secondaryPriority << endl;
                }
                auto end = chrono::system_clock::now();
                auto timeElapsed = chrono::duration<float>(end - start);
                outFile << timeElapsed.count() << "\n";
            }
        }
    
        ////////////////////////////////////////////////////
        
        if(number == 10){
            cout << "Goodbye!" << endl;
            break;
        }
        
        cout << "======Main Menu======" << endl;
        cout << "1. Linked List Enqueue/Dequeue Average time, n items, x500" << endl;
        cout << "2. Binary Heap Enqueue/Dequeue Average time, n items, x500" << endl;
        cout << "3. Dequeue LL" << endl;
        cout << "4. Dequeue heap" << endl;
        cout << "5. Dequeue all LL" << endl;
        cout << "6. Dequeue all heap" << endl;
        cout << "7. PrintHeap" << endl;
        cout << "8. PrintLL" << endl;
        cout << "9. STL Enqueue/Dequeue Average time, n items, x500" << endl;
        cout << "10. Quit" << endl;
        
        cin >> number;
    }
    return 0;
}
