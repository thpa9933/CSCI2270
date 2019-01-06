#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "MovieTree.hpp"

using namespace std;

MovieTree::MovieTree(){
    root = nullptr;
}
MovieTree::~MovieTree(){
    DeleteAll(root);
}

void MovieTree::DeleteAll(MovieNodeBST *node){
    if(!node)
    {
        return;
    }
    
    DeleteAll(node->leftChild);
    DeleteAll(node->rightChild);
    MovieNodeLL *temp = node->head;
    while(temp)
    {
        cout<<"Deleting: "<< temp->title<<endl;
        temp = temp->next;
    }
    delete node;
    node = nullptr;
}

void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity){
    char x = title[0];                                    //grab first letter of title
    
    if(root == nullptr){
        MovieNodeBST *newMovieNode = new MovieNodeBST(x);
        root = newMovieNode;
        MovieNodeLL *newList = new MovieNodeLL(ranking, title, releaseYear, quantity);
        newMovieNode -> head = newList;
    }
    else{
        MovieNodeBST *temp = root;
        MovieNodeBST *tempParent;
        MovieNodeBST *newMovieNode = new MovieNodeBST(x);
        while(temp != nullptr){
            if(newMovieNode -> letter == temp -> letter){
                MovieNodeLL *tempListNode = new MovieNodeLL(ranking, title, releaseYear, quantity);
                MovieNodeLL *tempList = temp -> head;
                if(tempListNode -> title < tempList -> title){                              //head case
                    tempListNode -> next = tempList;
                    temp -> head = tempListNode;
                    tempList = tempList -> next;
                }
                else{                                                                        //in between case
                    while(tempList -> next != nullptr){
                        if(tempList -> title < tempListNode -> title && tempList -> next -> title > tempListNode -> title){
                            tempListNode -> next = tempList -> next;
                            tempList -> next = tempListNode;
                            break;
                        }
                        tempList = tempList -> next;
                    }
                    if(tempList -> next == nullptr){                                       //tail case
                        tempList -> next = tempListNode;
                    }
                }
                break;
            }
            else if(newMovieNode -> letter < temp -> letter){
                tempParent = temp;
                temp = temp -> leftChild;
            }
            else{
                tempParent = temp;
                temp = temp -> rightChild;
            }
        }
        if(temp == nullptr){
            newMovieNode -> parent = tempParent;
            if(newMovieNode -> letter < tempParent -> letter){
                tempParent -> leftChild = newMovieNode;
            }
            else{
                tempParent -> rightChild = newMovieNode;
            }
            MovieNodeLL *newList = new MovieNodeLL(ranking, title, releaseYear, quantity);
            newMovieNode -> head = newList;
        }
    }
}

void MovieTree::printMovieInventory(){
    printMovieInventory(root);
}

void MovieTree::printMovieInventory(MovieNodeBST *node){
    if(node){
        if(node -> leftChild != nullptr){
            printMovieInventory(node -> leftChild);
        }
        
        MovieNodeLL *temp = node -> head;
        while(temp != nullptr){
            cout << "Movie: "<<temp -> title << " " << temp -> quantity << endl;
            temp = temp -> next;
        }
        if(node -> rightChild != nullptr){
            printMovieInventory(node -> rightChild);
        }
    }
}

MovieNodeBST* MovieTree::searchBST(MovieNodeBST *node, string title){
    char x = title[0];
    
    if(node == nullptr){
        //cout<<"node is null"<<endl;
        return node;
    }
    else if(node -> letter == x){
        //cout << "in here" << endl;
        return node;
    }
    else if(x < node -> letter){
        //cout << "left" << endl;
        return searchBST(node -> leftChild, title);
    }
    else{
        //cout << "right" << endl;
        return searchBST(node -> rightChild, title);
    }
    return node;
}

MovieNodeLL* MovieTree::searchLL(MovieNodeLL* head, string title){
    MovieNodeLL *temp = head;
    //cout<<"came here"<<endl;
    while(temp != nullptr){
        //cout<<"did this"<<temp->title<<endl;
        if(temp -> title == title){
            //cout<<"in here"<<endl;
            return temp;
        }
        temp = temp -> next;
        //cout<<"done"<<endl;
    }
    //cout<<"completed"<<endl;
    return temp;
}

void MovieTree::findMovie(string title){
    MovieNodeBST *foundNode = searchBST(root, title);
    //cout<<foundNode->letter<<endl;
    if(foundNode == nullptr){
        cout << "Movie not found." << endl;
        return;
    }
    else{
        MovieNodeLL *temp = searchLL(foundNode -> head, title);
        if(temp)
        {
            cout << "Movie Info:" << endl;
            cout << "===========" << endl;
            cout << "Ranking:" << temp -> ranking << endl;
            cout << "Title:" << temp -> title << endl;
            cout << "Year:" << temp -> year << endl;
            cout << "Quantity:" << temp -> quantity << endl;
        }
        else{
            cout << "Movie not found." << endl;
        }
    }
}

MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST *node){
    if(node != nullptr){
        while(node -> leftChild != nullptr){
            node = node -> leftChild;
        }
        return node;
    }
    else{
        return NULL;
    }
}

void MovieTree::deleteMovieNode(string title){
    bool lastNode = false;
    MovieNodeBST *BSTNode = searchBST(root, title);                     //finds the bst node
    MovieNodeLL *LLNode = searchLL(BSTNode -> head, title);             //finds the movie
    if(LLNode){                                                         //if movie is found
        MovieNodeLL *temp = BSTNode -> head;
        while(temp != nullptr){
            MovieNodeLL *curr = temp -> next;
            if(temp -> title == LLNode -> title){                       //head condition
                BSTNode -> head = LLNode -> next;
                delete LLNode;
                MovieNodeLL *checkNode = BSTNode -> head;
                if(checkNode == nullptr){             //check to see if you need to reorganize BST
                    lastNode = true;
                }
                break;
            }
            else if(curr -> title == title){                            //middle case & end case
                temp -> next = curr -> next;
                delete curr;
                break;
            }
            temp = temp -> next;
        }
        if(lastNode == true){                                           //reorganize BST
            if(BSTNode != root){
                if(BSTNode -> rightChild != nullptr && BSTNode -> leftChild != nullptr){ //two children
                    MovieNodeBST *minNode = treeMinimum(BSTNode -> rightChild);
                    if(minNode == BSTNode -> rightChild){
                        BSTNode -> parent -> leftChild = minNode;
                        minNode -> parent = BSTNode -> parent;
                        minNode -> leftChild = BSTNode -> leftChild;
                        minNode -> leftChild -> parent = minNode;
                    }
                    else{
                        minNode -> parent -> leftChild = minNode -> rightChild;
                        minNode -> rightChild -> parent = minNode -> parent;
                        minNode -> parent = BSTNode -> parent;
                        BSTNode -> parent -> leftChild = minNode;
                        minNode -> leftChild = BSTNode -> leftChild;
                        minNode -> rightChild = BSTNode -> rightChild;
                        BSTNode -> rightChild -> parent = minNode;
                        BSTNode -> leftChild -> parent = minNode;
                    }
                }
                else if(BSTNode -> leftChild != nullptr || BSTNode -> rightChild != nullptr){
                    
                    if(BSTNode -> leftChild != nullptr){                        //left child
                        MovieNodeBST *tempX = BSTNode -> leftChild;
                        BSTNode -> parent -> leftChild = tempX;
                        tempX -> parent = BSTNode -> parent;
                    }
                    else{                                                       //right Child
                        MovieNodeBST *tempX = BSTNode -> rightChild;
                        BSTNode -> parent -> rightChild = tempX;
                        tempX -> parent = BSTNode -> parent;
                    }
                }
                else{                                                           //no Children
                    if(BSTNode->parent->leftChild == BSTNode){
                       BSTNode->parent->leftChild = nullptr;
                    }
                    else{
                        BSTNode->parent->rightChild = nullptr;
                    }

                }
                delete BSTNode;
            }
        }
    }
    else{
        cout << "Movie not found." << endl;
    }
    //printMovieInventory();
}


void MovieTree::rentMovie(string title){
    
    MovieNodeBST *node = searchBST(root,title);
    
    MovieNodeLL *movie = searchLL(node -> head, title);
    
    if(movie){
        
        (movie -> quantity)--;
        if(movie -> quantity >= 0){
            cout << "Movie has been rented." << endl;
            cout << "Movie Info:" << endl;
            cout << "===========" << endl;
            cout << "Ranking:" << movie -> ranking << endl;
            cout << "Title:" << movie -> title << endl;
            cout << "Year:" << movie -> year << endl;
            cout << "Quantity:" << movie -> quantity << endl;
            
        }
        
        if(movie -> quantity == 0){
            deleteMovieNode(title);
        }
    }
    else{
        cout << "Movie not found." << endl;
    }
}


void MovieTree::countMovieNodes(MovieNodeBST *node, int *c){
    if(root != NULL){
        if(node -> leftChild != nullptr){
            countMovieNodes(node -> leftChild, c);
        }
        
        MovieNodeLL *tempListNode = node -> head;
        
        while(tempListNode != nullptr){
            *c = *c + 1;
            tempListNode = tempListNode -> next;
        }
        
        if(node -> rightChild != nullptr){
            countMovieNodes(node -> rightChild, c);
        }
    }
}

int MovieTree::countMovieNodes(){
    int count = 0;
    MovieNodeBST  *temp = root;
    countMovieNodes(temp, &count);
    return count;
}


