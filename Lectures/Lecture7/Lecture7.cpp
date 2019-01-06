#include <iostream>
using namespace std;

//linked lists
        // [head] --> [ID] --> [ID] --> NULL
        //lists are a bunch of "nodes" strung together
        //last in the list is NULL
        //each node has an ID
        //starts at the "head" of the list
        //to insert a new node, you must go to the end of the list and step through the list untill
        //you find what points to NULL, at that point you set your new node you want to insert as the
        //next item in the list, pointing to null

struct Node{
    int id = -1;
    Node *next = NULL;
};

Node* createNode(int nodeID, Node * nextNode){
    Node * newNode = new Node;
    newNode -> id = nodeID;
    newNode -> next = nextNode;
    return newNode;
}

//insert Node -- inserts at the end of the list
Node* insertNode(Node* head, int newNodeID){
    if(head == NULL){
        Node * newNode = createNode(newNodeID, NULL);
        head = newNode;
    }
    else{
        Node * currentNode = head;
        //traverse to the end of the list
        while(currentNode -> next != NULL){
            currentNode = currentNode -> next;
        }
        Node* newNode = createNode(newNodeID, NULL);
        currentNode -> next = newNode;
    }
    return head;
}

void printList(Node* head){
    if(head == NULL){
        cout << "empty list" << endl;
    }
    else{
        Node* currentNode = head;
        while(currentNode != NULL){
            cout << "Node ID: " << currentNode -> id << endl;
            currentNode = currentNode -> next;
        }
    }
}

Node * deleteNode(Node * head, int nodeID){
    //find the node
    bool nodeFound = false;
    //first check if head is null
    if(head == NULL){
        cout << "empty list, nothing to delete" << endl;
        return NULL;
    }
    else{
        //first check the head
        if(head->id == nodeID){
            //need to delete the head, what becomes the new head?
                //whatever is next
            Node* nextNode = head -> next;
            delete head;
            head = nextNode;
            nodeFound = true;
            cout << "node " << nodeID << " deleted" << endl;
        }
        else if(head -> next != NULL && head -> next -> id == nodeID){
            //delete the second node
            Node * newNextNode = head -> next -> next;
            delete head -> next;
            head -> next = newNextNode;
            nodeFound = true;
            cout << "Node " << nodeID << " deleted" << endl;
        }
        else{
            Node* currentNode = head -> next;
            while(currentNode -> next != NULL && !nodeFound){
                if(currentNode -> next -> id == nodeID){
                    Node * newNextNode = currentNode -> next -> next;
                    delete currentNode -> next;
                    currentNode -> next = newNextNode;
                    nodeFound = true;
                    cout << "Node " << nodeID << " delete" << endl;
                }
                else{
                    currentNode = currentNode -> next;
                }
            }
            if(!nodeFound){
                cout << "node " << nodeID << " not found, nothing deleted" << endl;
            }
        }
        return head;
    }
}


int main(){
    Node *head = NULL;
    head = insertNode(head, 30);
    head = insertNode(head, 10);
    head = insertNode(head, 30);
    printList(head);
    
    head = deleteNode(head, 30);
    printList(head);
    head = deleteNode(head, 20);
    printList(head);
}


