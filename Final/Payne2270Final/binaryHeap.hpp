#include <iostream>
using namespace std;

// this implementation is a max heap
// this implementation only check primary priority
struct priorityItem{
    string itemName;
    int primaryPriority;
    int secondaryPriority;
};

class PriorityQueue{
public:
    PriorityQueue();
    ~PriorityQueue();
    bool enqueue(string,int,int);
    priorityItem* dequeue();
    string peek();
    void printPQ();
    long fib(int n);
    
private:
    int lastIndex = 0;
    int maxIndex = 880;
    priorityItem* pQueue[880];
};
