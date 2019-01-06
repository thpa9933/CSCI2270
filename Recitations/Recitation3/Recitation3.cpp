#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void resizeArray(int* oldArray, int* capacity){        //you are recieving the ADDRESS of the array
    int newCapacity = (*capacity * 2);                 //then dereferencint it (*) to change the values
    int *newArray = new int[newCapacity];
    for(int i = 0; i < newCapacity; i++){
        newArray[i] = oldArray[i];
    }
    delete oldArray;
    oldArray = newArray;
    *capacity = newCapacity;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        return 0;
    }
    ifstream infile;
    infile.open(argv[1]);
    if(infile.is_open()){
        string num;
        int capacity = 10;
        int *array = new int[capacity];
        int numOfElement = 0;
        
        while(getline(infile, num)){
            if(numOfElement == capacity){
                resizeArray(array, &capacity); //you need the & when you are passing in anything but an array
            }                                  //you are passing in the ADDRESS of the array
            array[numOfElement] = stoi(num);
            numOfElement++;
        }
        for(int k = 0; k < capacity; k++){
            cout << array[k] << endl;
        }
    }
    else{
        return 0;
    }
}
