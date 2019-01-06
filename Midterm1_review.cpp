#include <iostream>
using namespace std;

//For main to accept command line Arguments: int main(ing argc, char *argv[])
//What variables store the number of arguments to a program: argc

//===========BIGO Notation=========================
//O(n): worst case scenerio
//O(1): executes a single time
//An array has 20 elements, what is worst case complexity?: O(20)
//deleting the tail of the list is O(1) for SLL and O(1) for DLL when there is a tail pointer
//=================================================

//===========Pointers and References===============
//Dereferencing a pointer: *
//string *x, y: x is a pointer to a string and y is a string
//get memory address: &a
//passing in a reference (&) allows you to modify the variable in the function
//=================================================

//===========Memory Allocation=====================
//statically declared variables are stored on the stack
//dynamically declared variables are stored on the heap
//when dynamically allocated memory is declared, and not deleted, you create a memory leak
//when dynamically allocated memory goes out of scope, you create a memory leak
//release memory with delete or delete []
//linked lists are generally considered dynamic memory allocation

//you can declare dynamically allocated variables in the following way:
//  int *p = new int(100); -----------------------> points to an int with the value 100
//  int *p; p = new int; *p = 100;
//  int *p = NULL; p = new int; *p = 100;
//  int *p = new int[100] ------------------------> allocated an array of 100 ints
//=================================================

//===========SLL Implimentation====================
//A linked list node can be implemented in C++ using a class & struct
//first node in a LL is head, last is tail
//when new element is added in the middle of a singly linked list, then no need to move element
//the head and tail are stored as Private
//the methods to initialize, delete, and traverse are Public

//Complexity of inserting a node in a linked list after the node prev with a function prototype:
//  insertNode(Node* head, Node* prev, Node* newNode)
//  where head is the head of the list and newNode is the node to be inserted?
//  O(1)
//=================================================

//============DLL Implementation===================
//  to delete a node from a DLL, update pionters to bypass the node, then  free the memory of old node
//while temp != null
//      if temp -> value == value
//          if temp -> previous == NULL -head
//          if temp -> next == NULL     -tail
//          else other stuff
//      else temp = temp -> next
//=================================================

//============STACKS===============================
//  LIFO
//  linked list in its implementation
//  Add to top = push()
//  Take off top = pop()
//=================================================

//=============QUEUES==============================
//  FIFO
//  element added to the tail = enqueued
//  element removed from the head = dequeued
//  when we dequeue an element in a circular queue, the position of the head changes
//  when inserting into an *empty* queue, both head and tail pointer position change
//  head is where the next element will be removed
//  tail is where the next element will be added
//  when an element is added, the tail position shifts one
//  when an element is removed, the head position shifts one

//=================================================

//=============EXTRA PRACTICE=======================================================

//int a = 100;
//int b = 200;
//int *p = &a;
//int *q = &b;
//p = q;
//>>>p now points to b

//====================

//10 -> 20 -> 30 -> 10 -> 10 -> 50 -> 10 -> NULL
//Node *walker = head;
//int count = 0;
//while(walker!= NULL && count < 3) {
//    if(walker->key == 10) {
//        count = count + 1;
//    }
//    walker = walker->next;
//}
//cout <<  walker->key  << endl;
//what is the output?
//>>>50

//====================

//adding newNode(15) in the after the temp node(7);
//5 <-> 10  <-> 7 <->12
//newNode -> next = temp -> next;
//newNode -> prev = temp;
//temp -> next -> prev = newnode;
//temp -> next = newNode;

//====================

//5 <-> 10  <-> 7 <->12
//adding newNode(15) at the tail node
//newNode -> next = tail -> next;
//tail -> next = newNode;
//newNode -> prev = tail;
//tail = newNode;

//====================

//5 <-> 10  <-> 7 <->12
//adding newNode(15) before the head
//newNode -> next = head;
//newNode -> prev = head -> prev;
//head -> prev = newNode;
//newNode = head;

//==================================================================================

//node * DeleteNode(node *head, int value)
//{
//    node *temp = new node;
//    node *current = new node;
//    temp = head;
//    while(temp != NULL)
//    {
//        if(temp -> value == value)
//        {
//            if(temp ->prev == NULL)                   //head case
//            {
//                current = temp->next;
//                temp->next->prev = NULL;
//                delete temp;
//                head = current;
//            }
//            else if(temp->next == NULL)               //tail case
//            {
//                current = temp->prev;
//                temp->prev->next =NULL;
//                delete temp;
//                temp = current;
//            }
//            else                                      //other case
//            {
//                current = temp->next;
//                temp->prev->next = temp->next;
//                temp->next->prev = temp->prev;
//                delete temp;
//                temp = current;
//            }
//        }
//        else
//        {
//            temp = temp -> next;
//        }
//    }
//    return head;
//}

//DEQUEUE
//node* Queue::dequeue()
//{
//    node *temp = new node;
//    if(head == NULL)
//    {
//        return NULL;
//    }
//    else if(head == tail)
//    {
//
//        temp = head;
//        delete head;
//        head = NULL;
//        tail = NULL;
//        return temp;
//    }
//    else
//    {
//        temp = head;
//        delete head;
//        head = temp->next;
//        return temp;
//    }
//}

//ENQUEUE
//void Queue::enqueue(node *newNode){
//    newNode -> next = NULL;
//    if(tail != NULL){
//        tail -> next = newNode;
//        tail = newNode;
//    }
//    else{
//        tail = newNode;
//        head = tail;
//    }
//}

//REMOVE ELEMENTS THAT MATCH THE TARGET
//int ShiftArray(Product arr[], int size, int target){
//    for(int i = 0; i < size; i++){
//        Product temp;
//        if(arr[i].price == target){
//            for(int j = i; j < size - 1; j++){
//                arr[j].price = arr[j + 1].price;
//                arr[j].pname = arr[j + 1].pname;
//            }
//            size = size - 1;
//        }
//    }
//    return size;
//}

//RETURN MOST COMMON PRODUCT NAME
//string commonRepeatingElement(Product arr[], int length){
//    int count[length];
//    string max_name = "";
//    int max = 0;
//    for(int j = 0; j < length; j++){
//        for(int k = 0; k < length; k++){
//            if(arr[j].pname == arr[k].pname){
//                count[j]++;
//                if(count[j] >= max){
//                    max = count[j];
//                    max_name = arr[j].pname;
//                }
//            }
//        }
//    }
//    return max_name;
//}

//COPY ARRAY EXCEPT GIVEN VALUE
//int *CopyArray(int array[], int length, int value){
//    int *newArray = new int(length);
//    int size = 0;
//    for(int k = 0; k < length; k++){
//        if(array[k] != value){
//            newArray[size] = array[k];
//            size++;
//        }
//    }
//    return newArray;
//}

//RETURN SECOND LARGEST THIS INCLUDES SORT FUNCTION TOO!
//int secondLargest(int arr[], int size){
//    int temp = 0;
//    for(int i = 0; i < size - 1; i++){
//        for(int k = 0; k < size - 1 - i; k++){
//            if(arr[k] < arr[k + 1]){
//                temp = arr[k];
//                arr[k] = arr[k + 1];
//                arr[k + 1] = temp;
//            }
//        }
//    }
//    return arr[1];
//}

//FIND MAX VALUE IN LINKED LIST
//void findMax(){
//    Node *temp = head;
//    int currMax = 0;
//    while(temp != NULL){
//        if(temp -> key > currMax){
//            currMax = temp -> key;
//        }
//        temp = temp -> next;
//    }
//    cout << currMax << endl;
//}

//ADDCITY WITH TAIL (DLL)
//void CommunicationNetwork::addCity(std::string newCityName, std::string previousCityName){
//    City *temp = new City(newCityName, nullptr, nullptr, "");
//
//    if(head == nullptr){                    //if nothing is in list
//        head = temp;
//        tail = temp;
//    }
//
//    else if(previousCityName == "First"){       //if you want to insert beginning of list
//        temp -> next = head;
//        head -> previous = temp;
//        head = temp;
//    }
//
//    else if(previousCityName == ""){            //if you want to insert end of list
//        tail -> next = temp;
//        temp -> previous = tail;
//        tail = temp;
//    }
//
//    else{                                       //insert middle of list
//        City *current = head;
//        while(current != nullptr && current -> cityName != previousCityName){
//            current = current -> next;          //find where you need to insert
//        }
//        if(current != nullptr){                 //insert
//            temp -> next = current -> next;
//            current -> next = temp;
//            temp -> previous = current;
//            temp -> next -> previous = temp;
//        }
//    }
//}

//ADD CITY no tail(SLL)
//city *addCity(city *head, city*previous, string cityname){
//    city * newCity = new city(cityname, nullptr, "");
//    if(previous == nullptr){                      //adds at head
//        newCity -> next = head;
//        head = newCity;
//
//    }
//    else if(previous -> next == nullptr){         //adds at end
//        previous -> next = newCity;
//        newCity -> next = nullptr;
//    }
//    else{                                        //All other cases
//        newCity -> next = previous -> next;
//        previous -> next = newCity;
//    }
//    return head;
//}
//==================================================================================

//=========function to sway two pointers===========
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//=================================================


int main(){
    int a = 1, b = 2;
    swap(&a, &b);
    cout << a << " : " << b << endl;
    
    return 0;
}

int *makeNewArray(int inputArray[], int arraySize, int compareNum){
    int *newArray = new int(arraySize);
    int size = 0;
    for(int i = 0; i < arraySize; i++){
        if(inputArray[i] > compareNum){
            newArray[size] = inputArray[i];
            size++;
        }
    }
    return newArray;
}
