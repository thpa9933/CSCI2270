#include <iostream>
using namespace std;

const int max_size = 5;

class arrStack{
public:
    arrStack();
    ~arrStack();
    bool isEmpty();
    bool isFull();
    int peak();
    int pop();
    bool push(int);
    
    
private:
    int stackOInts[max_size];
    int currentSize = 0;
};

arrStack::arrStack(){
    
}

arrStack::~arrStack(){
    
}

bool arrStack::isFull(){
    if(currentSize == max_size){
        return true;
    }
    else{
        return false;
    }
}

bool arrStack::isEmpty(){
    if(currentSize == 0){
        return true;
    }
    else{
        return false;
    }
}

bool arrStack::push(int itemToAdd){
    if(isFull()){
        return false;
    }
    else{
        stackOInts[currentSize] = itemToAdd;
        currentSize += 1;
        return true;
    }
}

int main(){
    arrStack matey;
    if(!matey.isEmpty()){
        cout << "stack is empty" << endl;
    }
    if(matey.push(19)){
        cout << "19 pushed to stack" << endl;
        
    }
    if(matey.push(4)){
        cout << "4 pushed to stack" << endl;
        
    }
    if(matey.push(19)){
        cout << "19 pushed to stack" << endl;
        
    }
    if(matey.push(19)){
        cout << "19 pushed to stack" << endl;
        
    }
    if(matey.push(19)){
        cout << "19 pushed to stack" << endl;
        
    }
    if(matey.push(9)){
        cout << "9 pushed to stack" << endl;
        
    }
    else{
        cout << "9 not pushd to stack" << endl;
    }
    return 0;
}
