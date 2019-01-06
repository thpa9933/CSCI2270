#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void passByPointer(int *ptr){
    // *ptr = *ptr + 1; underneath also works
    (*ptr)++;
    
}


int *multiplyArraySize(int p[], int length, int multiplier){
    int *newArray = new int[length*multiplier];
    for(int i = 0; i < length; i++){
        newArray[i] = p[i];
    }
    delete [] p; //[]   deletes entire array
    return newArray;
}


int main(){
//    int x = 10;
//    while (x-- >0){ //decrement x (greater than) 0
//        cout << "x: " << x << endl;
//    }
    
    int *intPtr = new int;              //in the heap (mangaged by programmer, dynamic, can delete)
    int normalInt;                      //in the stack (managed by OS, static, cannot delete)
    normalInt = 8;
    normalInt = 9;
    *intPtr = 0;
    
    passByPointer(intPtr);
    cout << "what is stored in intPtr? " << *intPtr << endl;
    cout << "what is intPtr memory address? " << intPtr << endl;
    
    int *myArray = new int[200]; //creates heap memory
    int staticArray[200];   //creates stack memory
    
    for(int i = 0; i < 200; i++){
        myArray[i] = i + 1;
    }
    cout << "reference of myArray: " << myArray << endl;
    cout << "reference of staticArray: " << staticArray << endl;

    
    int *aNewArray = multiplyArraySize(myArray, 200, 3); //array, size, multiplyer
    for(int i = 0; i < 600; i++){
        cout << "index " << i << ": " << aNewArray[i] << endl;
    }
}


