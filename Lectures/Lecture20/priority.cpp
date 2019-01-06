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
    bool dequeue();
    string peek();
    void printPQ();
    
private:
    int lastIndex = 0;
    int maxIndex = 10;
    priorityItem = pQueue[10];
};

PriorityQueue::PriorityQueue(){
    for (int i=0; i<maxIndex; i++){
        pQueue[i] = nullptr;
    }
}


PriorityQueue::~PriorityQueue(){
    for(int i=1; i<maxIndex; i++){
        delete pQueue[i];
    }
}

bool PriorityQueue::enqueue(string thingName, int primP, int secP)
{
    //if you want to dynamically resize the heap
    //check if queue is full
    if(lastIndex < maxIndex)
    {
        priorityItem* itemToAdd = new priorityItem;
        itemToAdd->itemName = thingName;
        itemToAdd->primaryPriority = primP;
        itemToAdd->secondaryPriority = secP;
        lastIndex++;
        //put the new thing at the last index
        pQueue[lastIndex] = itemToAdd;
        //reheap up
        int currentIndex = lastIndex;
        bool itemSwapped = true;
        while(currentIndex > 1 && itemSwapped)
        {
            //compare thing at current index to parent
            if(pQueue[currentIndex]->primaryPriority > pQueue[currentIndex/2]->primaryPriority)
            {
                //will need to swap
                priorityItem* temp = pQueue[currentIndex/2];
                pQueue[currentIndex/2] = pQueue[currentIndex];
                pQueue[currentIndex] = temp;
                currentIndex = currentIndex/2;
            }
            else
            {
                itemSwapped = false; //binary heap is partially ordered
            }
        }
        return true;
    }
    else
    {
        //queue is full
        cout << "Queue is full" << endl;
        return false;
    }
}

string PriorityQueue::peek()
{
    //checks top
    //check if empty
    if(lastIndex != 0)
    {
        return pQueue[1]->itemName;
    }
    else
    {
        cout << "Priority Queue is empty" << endl;
        return "N/A";
    }
}

bool PriorityQueue::dequeue()
{
    //check if empty
    if(lastIndex>0)
    {
        delete pQueue[1];
        //check if priority queueue is now empty
        if(lastIndex == 1)
        {
            lastIndex = 0;
            pQueue[1] = nullptr;
            //done
        }
        else
        {
            //set item 1 to thing at end
            pQueue[1] = pQueue[lastIndex];
            //set last thing = nullptr
            pQueue[lastIndex] = nullptr;
            //decrement last Index
            lastIndex--;
            //reheap down
            int currentIndex = 1;
            int leftChild, rightChild, largerChild;
            bool itemSwapped = true;
            while(currentIndex<maxIndex && itemSwapped)
            {
                leftChild = currentIndex*2;
                rightChild = currentIndex*2 + 1;
                //check if you're out of bounds
                if(leftChild > lastIndex)
                {
                    //no children, so stop
                    itemSwapped = false;
                }
                else
                {
                    if(rightChild > lastIndex)
                    {
                        largerChild = leftChild
                    }
                    else
                    {
                        //need to compare the children
                        largerChild = (pQueue[leftChild]->primaryPriority > pQueue[rightChild]->primaryPriority) ? leftChild : rightChild
                        //question mark checks if its true it returns left child, else it returns right child
                    }
                }
                if(pQueue[currentIndex]->primaryPriority < pQueue[largerChild]->primaryPriority)
                {
                    //swap
                    priorityItem* temp = pQueue[largerChild];
                    pQueue[largerChild] = pQueue[currentIndex];
                    pQueue[currentIndex] = temp;
                    //move current index to index of larger child
                    //reheaping down
                    currentIndex = largerChild;
                }
                else
                {
                    itemSwapped = false;
                }
            }
        }
        return true;
    }
    else
    {
        cout << "PriorityQueue is empty, nothing to dequeue" << endl;
        return false;
    }
}

int main()
{
    return 0;
}






