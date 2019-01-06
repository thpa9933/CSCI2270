//Thomas Payne
//Assignment 5
#include "Queue.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

Queue::Queue(int qs) {
    queueSize = qs;
    arrayQueue = new string[queueSize];
    queueHead = 0;
    queueTail = 0;
    queueCount = 0;
}
Queue::~Queue() {
    delete [] arrayQueue;
    arrayQueue = nullptr;
}

bool Queue::queueIsFull()  {                            //approved in code runner
    int tempHead = queueHead;
    if(queueHead == 0){
        tempHead = queueSize;
    }
    if(tempHead - queueTail == 0){
        return true;
    }
    else{
        return false;
    }
}

bool Queue::queueIsEmpty(){                              //approved in code runner
    if(queueCount == 0){
        return true;
    }
    else{
        return false;
    }
}

void Queue::enqueue(string item){                         //approved in code runner
    if(!queueIsFull()){
        arrayQueue[queueTail] = item;
        queueCount++;
        if(queueTail == queueSize - 1){
            queueTail = 0;
        }
        else{
            queueTail++;
        }
        cout << "E: " << item << endl;
        cout << "H: " << queueHead << endl;
        cout << "T: " << queueTail << endl;
    }
    else{
        cout << "Queue full" << endl;
    }
}

void Queue::dequeue(){
    if(!queueIsEmpty()){
        string word = arrayQueue[queueHead];
        queueCount--;
        if(queueHead == queueSize - 1){                      //if head is at end of array
            queueHead = 0;
        }
        else{
            queueHead++;
        }
        cout << "H: " << queueHead << endl;
        cout << "T: " << queueTail << endl;
        cout << "word: " << word << endl;
    }
    else{
        cout << "Queue is empty" << endl;                    //approved in code runner
    }
}

void Queue::printQueue(){                                    //approved in code runner
    if(!queueIsEmpty()){
        if(queueHead < queueTail){
            for(int i = queueHead; i < queueTail; i++){      //say head is at 1 and tail is at 9, print 1-9
                cout << i << ": " << arrayQueue[i] << endl;
            }
        }
        else{
            for(int j = queueHead; j < queueSize; j++){       //say head is at 7 and tail is at 3
                cout << j << ": " << arrayQueue[j] << endl;   //print from 7 to end of queue
            }
            for(int k = 0; k < queueTail; k++){
                cout << k << ": " << arrayQueue[k] << endl;   //then print from 0 to tail
            }
        }
    }
    else{
        cout << "Empty" << endl;
    }
}

void Queue::enqueueSentence(string str){                     //approved in coderunner
    int count = 0;
    stringstream ss(str);
    string line;
    while(getline(ss, line, ' ')){
        if(!queueIsFull() && count < queueSize){
            enqueue(line);
            count++;
        }
        else{
            cout << "Queue is full" << endl;
        }
    }
}

