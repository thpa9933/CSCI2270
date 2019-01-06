#include <iostream>
using namespace std;

struct LLNode{
    LLNode* next;
    string itemName;
    int primaryPriority;
    int secondaryPriority;
    
    LLNode(string IN, int PP, int SP){
        itemName = IN;
        primaryPriority = PP;
        secondaryPriority = SP;
        next = nullptr;
    };
};


class LinkedListQueue{
public:
    LinkedListQueue();
    ~LinkedListQueue();
    void enqueue(string,int,int);
    void dequeue();
    string peek();
    void printLL();
    
private:
    LLNode* head = nullptr;
//    int lastIndex = 0;
//    int maxIndex = 880;
//    LLNode* pQueue[880];
};
