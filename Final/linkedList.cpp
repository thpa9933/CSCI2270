#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "linkedList.hpp"
using namespace std;

LinkedListQueue::LinkedListQueue(){
    //
}

LinkedListQueue::~LinkedListQueue(){
    //
}

void LinkedListQueue::enqueue(string itemName, int primaryPriority, int secondaryPriority){
    LLNode* newNode = new LLNode(itemName, primaryPriority, secondaryPriority);
    //cout << newNode -> itemName << endl;
    bool inserted = false;
    if(head == nullptr){                        //first thing in LL!
        head = newNode;
    }
    else{
        LLNode* temp = head;
        if(newNode -> primaryPriority < head -> primaryPriority){    //special first case
            newNode -> next = head;
            head = newNode;
            inserted = true;
        }
        else if(newNode -> primaryPriority == head -> primaryPriority){     //checks if equal to head
            if(newNode -> secondaryPriority < head -> secondaryPriority){
                newNode -> next = head;
                head = newNode;
                inserted = true;
            }
            else{                       //may just break out of case rather insert right after head?
                newNode -> next = head -> next;
                head -> next = newNode;
                inserted = true;
            }
        }
        else{
            while(temp -> next != nullptr){         //traverses to find where to insert next
                if(newNode -> primaryPriority < temp -> next -> primaryPriority){  //check first priority
                    newNode -> next = temp -> next;
                    temp -> next = newNode;
                    inserted = true;
                    break;
                }
                if(newNode -> primaryPriority == temp -> next -> primaryPriority){ //check second priority
                    if(newNode -> secondaryPriority < temp -> next -> secondaryPriority){
                        newNode -> next = temp -> next;
                        temp -> next = newNode;
                        inserted = true;
                        break;
                    }
                }
                temp = temp -> next;
                if(temp -> next == nullptr){            //tail case
                    temp -> next = newNode;
                    break;
                }
            }
        }
        if(inserted == false){
            newNode = temp -> next;
        }
    }
}

void LinkedListQueue::printLL(){
    if(head == nullptr){
        cout << "Nothing to dequeue in Linked List" << endl;
    }
    LLNode *temp = head;
    while(temp != nullptr){
        cout << temp -> itemName << " : " << temp -> primaryPriority << " : " << temp -> secondaryPriority << endl;
        temp = temp -> next;
    }
}

void LinkedListQueue::dequeue(){
    if(head == nullptr){
        cout << "Nothing to dequeue in Linked List" << endl;
    }
    LLNode *temp = head;
    head = head -> next;
    delete temp;
}
