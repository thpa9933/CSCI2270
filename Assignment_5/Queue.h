//Assignment_5
//Thomas Payne

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class Queue{
public:
    Queue(int);
    ~Queue();
    //circular queue methods
    void enqueue(string);
    void dequeue();
    void printQueue();
    void enqueueSentence(string);
    bool queueIsFull(); //check when full
    bool queueIsEmpty(); //check when empty
    
protected:
private:
    int queueSize;
    int queueHead;
    int queueTail;
    int queueCount;
    string *arrayQueue;
};

#endif // QUEUE_H

