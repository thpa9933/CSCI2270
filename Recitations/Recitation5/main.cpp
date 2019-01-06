#include <iostream>
#include "doublyLL.h"
using namespace std;

int main(){
    doublyLL Object;
    int array[] = {0, 0, 0, 4, 0, 4, 0, 4, 0, 4, 0, 4, 0, 4, 0, 4, 0, 4, 0, 0};
    for(int i = 0; i < 20; i++){
        Object.insertNodeAtEnd(array[i]);
    }
    Object.printList();
    Object.deleteNode(4);
    Object.printList();
}
