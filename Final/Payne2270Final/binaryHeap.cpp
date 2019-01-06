#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include "binaryHeap.hpp"
using namespace std;


//All of your indices start at 1 because mult and dividing by 0 gives you 0
PriorityQueue::PriorityQueue(){
    for (int i=1; i<maxIndex; i++){
        pQueue[i] = nullptr;
    }
}

PriorityQueue::~PriorityQueue(){
    for(int i=1; i<maxIndex; i++){
        delete pQueue[i];
    }
}

long PriorityQueue::fib(int n){
    if(n < 2) {
        return n;
    }
    return(fib(n-1) + fib(n-2));
}

bool PriorityQueue::enqueue(string thingName, int primP, int secP){
                                                    //to dynamically resize, check if queue is full
    if(lastIndex < maxIndex){                       //if this if statement is true, array is NOT full
        priorityItem* itemToAdd = new priorityItem;
        itemToAdd->itemName = thingName;
        itemToAdd->primaryPriority = primP;
        itemToAdd->secondaryPriority = secP;
        lastIndex++;                                //put the new thing at the last index
        pQueue[lastIndex] = itemToAdd;
        int currentIndex = lastIndex;
        bool itemSwapped = true;
        while(currentIndex > 1 && itemSwapped){     //compare thing at current index to parent.. must be > 1 for the first enqueue
            if(pQueue[currentIndex] -> primaryPriority < pQueue[currentIndex/2] -> primaryPriority){
            //if our current index index is less than the parent ^^, you need to swap
            priorityItem *temp = pQueue[currentIndex/2];        //Swap
            pQueue[currentIndex/2] = pQueue[currentIndex];
            pQueue[currentIndex] = temp;
            currentIndex = currentIndex/2; //reevaluates higher nodes in the loop. It passes in the new current index to loop
            //^^^looping now with new parent(after swap, essentiall they itemtoadd), working up the tree to fix any violations
            }//If this if statemnt is exicuted, it jumps to the top of the loop to resolve the other violations
            else if(pQueue[currentIndex] -> primaryPriority == pQueue[currentIndex/2] -> primaryPriority){
                if(pQueue[currentIndex] -> secondaryPriority < pQueue[currentIndex/2] -> secondaryPriority){
                    priorityItem *temp = pQueue[currentIndex/2];        //Swap
                    pQueue[currentIndex/2] = pQueue[currentIndex];
                    pQueue[currentIndex] = temp;
                    currentIndex = currentIndex/2;
                }
                else{
                    itemSwapped = false;    //this is essentially a break statement, when it hits here it breaks the while loop, returns true
                }
            }
            else{
                itemSwapped = false; //binary heap is partially ordered //breaks while loop, returns true
            }
        }
        return true;    //current index is 1, does not go into the upper while loop,
    }//if for say last index was 1 and current index was 2, it would seg fault at the if statement in the while loop because it would try to acess a parent that didnt exist because the first index does not have a parent.
    else{                                                      //queue is full
        cout << "Queue is full" << endl;
        return false;
    }
}

string PriorityQueue::peek(){ //checks fist index, returns name, else empty
    if(lastIndex != 0){
        return pQueue[1] -> itemName;
    }
    else{
        cout << "Priority Queue is empty" << endl;
        return "N/A";
    }
}

priorityItem* PriorityQueue::dequeue(){
    priorityItem *returnItem = pQueue[1];
    if(lastIndex > 0){           //Check if empty
        delete pQueue[1];        //ALWAYS deleting the top / 'root' of the heap
        if(lastIndex == 1){      //check if priority is empty
            lastIndex = 0;
            pQueue[1] = nullptr; //done
        }
        else{
            pQueue[1] = pQueue[lastIndex];      //set item 1 to thing at end
            pQueue[lastIndex] = nullptr;        //set last thing = nullptr
            //decrement last Index
            lastIndex--;
            //reheap down
            int currentIndex = 1;                           //CI is essentially your parent
            int leftChild, rightChild, smallerChild;
            bool itemSwapped = true;
            while(currentIndex < maxIndex && itemSwapped){  //this loops resolves violations
                leftChild = currentIndex*2;
                rightChild = currentIndex*2 + 1;
                if(leftChild > lastIndex){          //check if you're out of scope
                    itemSwapped = false;            //no children, so stop
                }
                else{
                    if(rightChild > lastIndex){     //case that there is one child (RC doesnt exist)
                        smallerChild = leftChild;
                    }
                    else{                           //need to compare the children
                        smallerChild = (pQueue[leftChild] -> primaryPriority < pQueue[rightChild] -> primaryPriority) ? leftChild : (pQueue[leftChild] -> primaryPriority == pQueue[rightChild] -> primaryPriority &&
                             pQueue[leftChild] -> secondaryPriority < pQueue[rightChild] -> secondaryPriority) ? leftChild : rightChild;
                        //1st check: if LC !< RC, check if LC & RC are the same Primary Priority
                        //2nd check: if they are of both PP, also check if LC SP < RC SP, if so SC == LC
                    }
                    if(pQueue[currentIndex] -> primaryPriority > pQueue[smallerChild] -> primaryPriority){
                        //swap
                        priorityItem* temp = pQueue[currentIndex];
                        pQueue[currentIndex] = pQueue[smallerChild];
                        pQueue[smallerChild] = temp;
                        //move current index to index of larger child
                        //reheaping down
                        currentIndex = smallerChild; //allows us to loop with new CI to resolve further errors
                    }  //if this is executed jump to top of while loop
                    else if(pQueue[currentIndex] -> primaryPriority == pQueue[smallerChild] -> primaryPriority){
                        if(pQueue[currentIndex] -> secondaryPriority > pQueue[smallerChild] -> secondaryPriority){
                            priorityItem* temp = pQueue[currentIndex];
                            pQueue[currentIndex] = pQueue[smallerChild];
                            pQueue[smallerChild] = temp;
                            currentIndex = smallerChild;
                        }
                        else{
                            itemSwapped = false;
                        }
                    }
                    else{
                        itemSwapped = false;
                    }
                }
            }
        }
        return returnItem;
    }
    else{
        cout << "PriorityQueue is empty, nothing to dequeue" << endl;
        return NULL;
    }
}


void PriorityQueue::printPQ(){
    if(lastIndex == 0){
        cout << "Nothing in queue" << endl;
    }
    else{
        for(int i = 1; i <= maxIndex; i++){
            priorityItem* item = dequeue();
            cout << item -> itemName << " : " << item -> primaryPriority << " : " << item -> secondaryPriority << endl;
            cout << i << endl;
        }
    }
}
    

