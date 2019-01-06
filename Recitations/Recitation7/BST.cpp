#include <iostream>
#include "BST.h"
using namespace std;
/**
Create a node with key as data
**/
node* BST:: createNode(int data)
{
    node* nn = new node;
    nn->key = data;
    nn->left = nullptr;
    nn->right = nullptr;
    nn->parent = nullptr;
    return nn;
}

BST::BST()
{

}
/**
parameterized constructor. It will create the root and put the data in the root.
**/
BST::BST(int data)
{
    root = createNode(data);
}
/**
Destructor
**/
 BST::~BST(){
   //  destroyNode(root);
 }
/**
This function will destroy the subtree rooted at curNode.
Think about in what order should you destroy.
**/
 void BST:: destroyNode(node *curNode){
     if(root)
     {
         destroyNode(root->left);
         destroyNode(root->right);
         delete root;
         root = nullptr;
     }
 }

/** This function will search the data in a tree rooted at root
    We will call this function from searchKey.
    NOTE: As root is a private member of BST class, main function can not access root.
    So we need this helper function.
**/
 bool BST::searchKeyHelper(node* root, int data){
     if(root == NULL){
         return false;
     }
     else if(root -> key == data){
         return true;
     }
     else if(data < root -> key){
         //search left side of tree
         return searchKeyHelper(root -> left, data);
     }
     else if(data > root -> key){
         //search right side of tree
         return searchKeyHelper(root -> right, data);
     }
     else{
         return false;
     }
 }
/**
This function will search the data in the tree
**/
bool BST::searchKey(int data){
    return searchKeyHelper(root, data);
}

/**
This function will add the data in the tree rooted at curNode.
We will call this function from insertNode.
NOTE: root is a private member of BST. As root is a private member of BST class, main function can not access root.
      So we need this helper function. Implement your code for inserting a node in this function.
**/
 node* BST:: insertNodeHelper(node* curNode, int data){
     //TODO: Implement the code for insert a node at the tree rooted at curNode.
     node *newNode = createNode(data);
     if(curNode == NULL){
         curNode -> key = data;
         root = curNode;
     }
     else if(data < curNode -> key){
         curNode -> left = newNode;
         newNode -> parent = curNode;
     }
     else if(data > curNode -> key){
         curNode -> right = newNode;
         newNode -> parent = curNode;
     }
    return curNode;
 }

/**
This function will insert the data in the tree. As this function can not access the root
it will call the insertNodeHelper function.
**/
void BST:: insertNode(int data){
    if(root == NULL) // if the BST is empty create the root
        root = createNode(data);
    else // insert the data in the tree rooted at root
        insertNodeHelper(root, data);
}

/** This function will traverse the tree in-order and print out the node elements.
printTree() function will call this function.
NOTE: As root is a private member of BST class, main function can not access root. So printTree will
call this helper function.
**/
 void BST:: printTreeHelper(node* curNode){
     if(curNode)
     {
            printTreeHelper( curNode->left);
            cout << " "<< curNode->key;
            printTreeHelper( curNode->right);
     }
 }

 void BST:: printTree(){
     printTreeHelper(root);
 }

int main(){
    BST Object(10);
    Object.insertNode(10);
    Object.insertNode(12);
    Object.insertNode(8);
    Object.insertNode(18);
    cout << Object.searchKey(8);
    Object.printTree();
    
    return 0;
}
