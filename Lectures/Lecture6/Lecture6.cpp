#include <iostream>
#include <fstream>
using namespace std;

void leaky(double* dblPtr){
    double* leakyCopy = dblPtr;
    *dblPtr = (*dblPtr) * (*dblPtr);
}
//leakyCopy leaks memory

int main(){
    int *anIntPointer = NULL;
    anIntPointer = new int; //allocates memory
    *anIntPointer = 500;

    int *intPtr = new int;
    *intPtr = 17;
    cout << "intPtrReference: " << intPtr << endl;
    cout << *intPtr++ << endl;
    cout << "intPtrReference: " << intPtr << endl;
    
    cout << "what's in intPtr? " << *intPtr;
    
}
