#include <iostream>
using namespace std;

struct Node{
    int ID;
    Node *next = nullptr;
};

int main(){
    int nodeArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Node *head = new Node;
    head -> next = nullptr;
    head -> ID = 1;
    Node *current = head;

    for(int i = 1; i < 10; i++){
        Node *temp = new Node;
        temp -> ID = nodeArray[i];
        current -> next = temp;
        current = current -> next;
    }
    current = head;
    
    while(current != nullptr){
        cout << current -> ID << endl;
        current = current -> next;
    }
    current = head;
    
    while(current != nullptr)
    {
        if((current -> ID)%2 == 0){
            Node *newNode = new Node;
            newNode -> ID = 111;
            newNode -> next = current -> next;
            current -> next = newNode;
        }
        current = current -> next;
    }
    
    current = head;
    
    while(current != nullptr){
        cout << current -> ID << endl;
        current = current -> next;
    }

    return 0;
}
