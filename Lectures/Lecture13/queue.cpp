#include <iostream>
using namespace std;

const int max_size = 5;

class arrCircQueue{
public:
    arrCircQueue();
    ~arrCircQueue();
    bool enqueue(int);
    bool dequeue(int&);
    bool peak(int&);
private:
    bool isFull();
    bool isEmpty();
    int head = -1;
    int tail = -1;
    int arrQueue[max_size];
};

arrCircQueue::arrCircQueue(){
    //nothing
}

arrCircQueue::~arrCircQueue(){
    
}

bool arrCircQueue::isFull(){
    int tempHead = head;
    if(head == 0){
        tempHead = max_size;
    }
    if(tempHead - tail == 1){
        return true;
    }
    else{
        return false;
    }
}

bool arrCircQueue::isEmpty(){
    if(head == -1 && tail == -1){
        return true;
    }
    else{
        return false;
    }
}

bool arrCircQueue::enqueue(int itemToAdd){
    if(!isFull()){
        //add item
        int tempTail = tail + 1;
        if(tempTail == max_size){
            tempTail = 0;
        }
        tail = tempTail;
        arrQueue[tail] = itemToAdd;
        if(head == -1){
            head = 0;
        }
        cout << "item " << itemToAdd << " added to queue" << endl;
        return true;
    }
    else{
        cout << "queue full, item " << itemToAdd << " not added to queue" << endl;
        return false;
    }
}

bool arrCircQueue::dequeue(int& itemToGet){
    if(isEmpty()){
        cout << "queue empty, nothing to dequeue" << endl;
        return false;
    }
    else{
        //remove at head
        itemToGet = arrQueue[head];
        //check if list is empty
        if(head == tail){
            //nothing left in queue
            head = -1;
            tail = -1;
        }
        else{
            head += 1;
            if(head == max_size){
                head = 0;
            }
        }
        return true;
    }
}

int main(){
    arrCircQueue Object;
    Object.enqueue(10);
    Object.enqueue(22);
    int topOQueue;
    
    if(Object.dequeue(topOQueue)){
        cout << "dequeued " << topOQueue << endl;
    }
}
