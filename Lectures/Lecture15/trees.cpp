#include <iostream>
using namespace std;

struct Node{
    int id = -1;
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent = nullptr;
};

class BST{
private:
    Node *root = nullptr;
    Node *createNode(int, Node*, Node*, Node*);
    int getSize(Node*);
    bool addNodeRPriv(Node*, int);
    Node *search(Node*, int);
    bool deleteNode(Node*, int);
    int getMinInSubtree(Node*);
    int getMaxInSubtree(Node*);
public:
    BST();
    ~BST();
    bool addNode(int);
    bool addNodeR(int);
    int findSmallestNode();
    int findLargestNode();
    int getSizeOfTree();
    bool deleteItem(int);
};

BST::BST(){
    //nothing
}

BST::~BST(){
    //delete all nodes
}

Node* BST::createNode(int itemToAdd, Node *parentNode, Node *leftChild, Node *rightChild){
    Node *newNode = new Node;
    newNode -> id = itemToAdd;
    newNode -> parent = parentNode;
    newNode -> left = leftChild;
    newNode -> right = rightChild;
    
    return newNode;
}

int BST::findLargestNode(){
    if(root != nullptr){
        Node *temp = root;
        while(temp -> right != nullptr){
            temp = temp -> right;
        }
        return temp -> id;
    }
    else{
        return -1;
    }
}

int BST::getSizeOfTree(){
    return getSize(root);
}

int BST::getSize(Node *startNode){
    int size = 0;
    if(startNode != nullptr){
        size++;
        size += getSize(startNode -> left);
        size += getSize(startNode -> right);
    }
    return size;
}

bool BST::addNode(int itemToAdd){
    //start at the root
    Node *temp = root;
    Node *currParent = nullptr;
    
    while(temp != nullptr){
        currParent = temp;
        if(itemToAdd == temp -> id){
            cout << "item already in tree" << endl;
            return false;
        }
        else{
            if(itemToAdd < temp -> id){
                temp = temp -> left;
            }
            else{
                temp = temp -> right;
            }
        }
    }
    if(currParent == nullptr){
        root = createNode(itemToAdd, nullptr, nullptr, nullptr);
        cout << "item " << itemToAdd << " added as root" << endl;
    }
    else if(itemToAdd < currParent -> id){
        currParent -> left = createNode(itemToAdd, currParent, nullptr, nullptr);
        cout << "item " << itemToAdd << " added to left of " << currParent -> id << endl;
    }
    else{
        currParent -> right = createNode(itemToAdd, currParent, nullptr, nullptr);
        cout << "item " << itemToAdd << " added to right of " << currParent -> id << endl;
    }
    return true;
}

bool BST::addNodeR(int itemToAdd){
    if(root == nullptr){
        Node *newNode = createNode(itemToAdd, nullptr, nullptr, nullptr);
        root = newNode;
        cout << "item " << itemToAdd << " added as root" << endl;
        return true;
    }
    else{
        return addNodeRPriv(root, itemToAdd);
    }
}

bool BST::addNodeRPriv(Node *currNode, int itemToAdd){
    if(itemToAdd < currNode -> id){
        if(currNode -> left != nullptr){
            return addNodeRPriv(currNode -> left, itemToAdd);
        }
        else{
            currNode -> left = createNode(itemToAdd, currNode, nullptr, nullptr);
            cout << "item " << itemToAdd << " added to left of " << currNode -> id << endl;
            return true;
        }
    }
    else if(itemToAdd > currNode -> id){
        if(currNode -> right != nullptr){
            return addNodeRPriv(currNode -> right, itemToAdd);
        }
        else{
            currNode -> right = createNode(itemToAdd, currNode, nullptr, nullptr);
            cout << "item " << itemToAdd << " added to left of " << currNode -> id << endl;
            return true;
        }
    }
    else{
        cout << "item " << itemToAdd << " already in tree" << endl;
        return false;
    }
}

Node* BST::search(Node* startNode, int itemToFind){
    if(startNode != nullptr){
        if(itemToFind < startNode -> id && startNode -> left != nullptr){
            return search(startNode -> left, itemToFind);
        }
        else if(itemToFind > startNode -> id && startNode -> right != nullptr){
            return search(startNode -> right, itemToFind);
        }
        else if(itemToFind == startNode -> id){
            return startNode;
        }
        else{
            cout << "value " << itemToFind << "not found" << endl;
        }
    }
    return startNode;
}

int BST::getMinInSubtree(Node* startNode){
    if(startNode != nullptr){
        while(startNode -> left != nullptr){
            startNode = startNode -> left;
        }
        return startNode -> id;
    }
    else{
        return -999999999;
    }
}

int BST::getMaxInSubtree(Node* startNode){
    if(startNode != nullptr){
        while(startNode -> right != nullptr){
            startNode = startNode -> right;
        }
        return startNode -> id;
    }
    else{
        return -999999999;
    }
}

bool BST::deleteNode(Node *startNode, int itemToFind){
    Node *target = search(startNode, itemToFind);
    if(target != nullptr){                                     //first check to the right
        if(target -> right != nullptr){
            int minRight = getMinInSubtree(target -> right);
            Node *minRightNode = search(target -> right, minRight);
            
            if(minRightNode -> right != nullptr){
                minRightNode -> right -> parent = minRightNode -> parent;
                if(minRightNode -> parent -> id > minRightNode -> id){
                    minRightNode -> parent -> left = minRightNode -> right;
                }
                else{
                    minRightNode -> parent -> right = minRightNode -> right;
                }
            }
            else{
                if(minRightNode -> parent -> id > minRightNode -> id){
                    minRightNode -> parent -> left = nullptr;
                }
                else{
                    minRightNode -> parent -> right = nullptr;
                }
            }
            delete minRightNode; //not actualy deleting what were deleting, just swapping numbers
            target -> id = minRight;
            return true;
        }
    }
}


int main(){
    BST niceTree;
    
    //non-recursive add
//    niceTree.addNode(17);
//    niceTree.addNode(42);
//    niceTree.addNode(12);
//    niceTree.addNode(40);
//    niceTree.addNode(40);
    
    //recursive add
    niceTree.addNodeR(17);
    niceTree.addNodeR(42);
    niceTree.addNodeR(12);
    niceTree.addNodeR(40);
    niceTree.addNodeR(40);
}
