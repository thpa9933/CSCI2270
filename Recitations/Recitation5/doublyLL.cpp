#include <iostream>
#include "doublyLL.h"
using namespace std;

doublyLL::doublyLL() {

}

doublyLL::doublyLL(int nodeID) {
	//create head node
	head = createNode(nodeID, nullptr, nullptr);
	tail = head;
}

doublyLL::~doublyLL() {

}


Node* doublyLL::createNode(int nodeID, Node* nodePrev, Node* nodeNext) {
	Node* newNode = new Node;
	newNode->id = nodeID;
	newNode->next = nodeNext;
	newNode->prev = nodePrev;
	return newNode;
}

bool doublyLL::insertNodeAtEnd(int nodeID) {
	if (head == nullptr) {
		//nothing in the list
		head = createNode(nodeID, nullptr, nullptr);
		tail = head;
	}
	else {
		Node* newNode = createNode(nodeID, tail, nullptr);
		tail->next = newNode;
		tail = newNode;
	}
	return true;
}

void doublyLL::printList(){
    Node *current = head;
    while(current != nullptr){
        cout << "node ID: " << current -> id << endl;
        current = current -> next;
    }
}

void doublyLL::deleteNode(int ID){
    Node *temp = head;
    while(temp != nullptr){
        if(temp -> id == ID){
            temp -> next -> prev = temp -> prev;
            temp -> prev -> next = temp -> next;
            cout << "deleting node: " << temp -> id << endl;
            delete temp;
        }
        temp = temp -> next;
    }
}








