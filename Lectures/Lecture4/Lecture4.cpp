#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

//Pointer is a special kind of character that holds a place of memory rather than int, double, float ect.
//& is reference and modifies a variable 

void passByVal(int a);
void passByRef(int &a);

int main(){
    int jenny = 5;
    int *jennyPtr;          //pointint to data type int (the star de-references the value to find stored value)
    jennyPtr = &jenny;      //& gives you the following address of the integer
    
    int billy = 2;
    int jimmy = 3;
    
    cout << "what's Jenny? " << jenny << endl;
    cout << "what's reference to jenny (&): " << &jenny << endl;
    cout << "what's jennyPtr? " << jennyPtr << endl;
    cout << "what's stored at jennyPtr? " << *jennyPtr << endl; //* allows you to find memory location at the pointer!
    
    //so what's the difference between references and pointers?
    //POINTERS CAN BE REASSIGNED, REFERENCES CAN NOT
    
    cout << "billy: " << billy << endl;
    cout << "jimmy: " << jimmy << endl;
    
    // can i move the jenny reference to the jimmy reference?
    //&jenny = &billy; nope! (cant reassign references)
    
    //can i set the jenny pointer to billy's references? Yes!
    jennyPtr = &billy;
    //now, what's in the jennyPtr when we dereference it?
    cout << "jennyPtr is now " << jennyPtr << endl;
    cout << "dereferencing jennyPtr: " << *jennyPtr << endl;
    
    passByVal(jimmy);
    passByRef(billy);
    cout << "jimmy is: " << jimmy << endl;
    cout << "billy is: " << billy << endl;
    cout << "jennyPtr is now " << jennyPtr << endl;
    cout << "dereferencing jennyPtr: " << *jennyPtr << endl;

    passByVal(jenny);
    cout << "what's jenny after pass by val? " << jenny << endl;
    passByRef(jenny);
    cout << "what's jenny after pass by ref? " << jenny << endl;
}

void passByVal(int a){
    a++;
}

void passByRef(int &a){
    a++;                //this will increase a, & is a pointer and modifies the value of the varible
}


//What is the correct value to return to the operating system upon the successful completion of a program?
// 0







