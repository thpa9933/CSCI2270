#include "CommunicationNetwork.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
//CommunicationNetwork Object;

CommunicationNetwork::CommunicationNetwork(){
    //nothin
}
CommunicationNetwork::~CommunicationNetwork(){
   // Object.deleteNetwork();
    this -> deleteNetwork();
    this -> tail = nullptr;
    this -> head = nullptr;
}

void CommunicationNetwork::buildNetwork(){
    string cityArray[] = {"Phoenix", "Denver", "Dallas", "St. Louis", "Chicago","Atlanta", "Washington, D.C.", "New York", "Boston"};
    
    City *temp = new City;
    temp -> next = nullptr;
    temp -> previous = nullptr;
    temp -> cityName = "Los Angeles";
    temp -> message = "";
    head = temp;

    City *current = head;
    for(int i = 0; i < 9; i++){
        City *newCity = new City(cityArray[i], nullptr, nullptr, "");
        newCity -> previous = current;
        current -> next = newCity;
        current = current -> next;
    }

    current = head;
    cout << "===CURRENT PATH===" << endl;
    cout << "NULL" << " <- ";
    while(current -> next != nullptr){
        cout << current -> cityName << " <-> ";
        current = current -> next;
    }
    tail = current;
    cout << tail -> cityName << " ->";
    cout << " NULL" << endl;
    cout << "==================" << endl;

    //cout << "head cityname: " << head -> cityName << endl;
}

void CommunicationNetwork::printNetwork(){

    City *current = head;
    cout << "===CURRENT PATH===" << endl;
    cout << "NULL" << " <- ";
    while(current != nullptr){
        cout << current -> cityName << " <-> ";
        current = current -> next;
    }
    cout << " NULL" << endl;
    cout << "==================" << endl;
}

void CommunicationNetwork::transmitMsg(char * filename){
    ifstream infile;
    infile.open(filename);
    if(infile.is_open()){                                   //read in a file and parse by word
        string line;
        while(getline(infile, line)){
            string word;
            stringstream ss(line);
            while(getline(ss, word, ' ')){
                City *currentCity = head;
                //cout << "this is the head in transmitmsg: " << head -> cityName << endl;
                while(currentCity != nullptr){                    //move through the list
                    cout << currentCity -> cityName << " received " << word << endl;
                    currentCity -> message = "";                  //reset the message to nothing
                    currentCity = currentCity -> next;
                }
                
                currentCity = tail -> previous;
                while(currentCity != nullptr){
                    cout << currentCity -> cityName << " received " << word << endl;
                    currentCity -> message = "";
                    currentCity = currentCity -> previous;
                }
                currentCity = head;
            }
        }
    }
    else{
        cout << "file did not open properly" << endl;
    }
}

void CommunicationNetwork::addCity(string newCityName, string previousCityName){
//
//
////    if(head == nullptr){
////        cout << "if list is empty" << endl;
////        City * newCity = new City(newCityName, nullptr, nullptr, "");
////        head -> next = newCity;
////        newCity -> next = head -> next -> next;
////        newCity -> previous = head;
////    }
//    //TYPE "" FOR THIS CONDITION
//    if(previousCityName == ""){                                       //end of list
//        cout << "end of list" << endl;
//        City * newCity = new City(newCityName, nullptr, nullptr, "");
//        tail -> next = newCity;
//        newCity -> previous = tail;
//        tail = newCity;
//        tail -> next = nullptr;
//    }
//
//    //TYPE "First" FOR THIS CONDITION
//    if (previousCityName == "First"){                                 //beginning of list
//        cout << "beginning of list" << endl;                            //make new node to as beginning
//        City * newCity = new City(newCityName, nullptr, nullptr, "");   //make new city
//        newCity -> next = head;                                         //reassign the pointer
//        head = newCity;                                                 //reset head to previous
//    }
//
//    City *currentCity = head;
//    while(currentCity -> next != nullptr){
//        if(currentCity -> cityName == previousCityName){
//            City * newCity = new City(newCityName, nullptr, nullptr, "");
//            newCity -> next = currentCity -> next;
//            currentCity -> next = newCity;
//            newCity -> previous = currentCity;
//            break;
//        }
//        else{
//            currentCity = currentCity -> next;
//        }
//    }
    
    
    City *temp = new City(newCityName, nullptr, nullptr, "");
    
    if(head == nullptr){
        head = temp;
        tail = temp;
    }
    
    else if(previousCityName == "First"){
        temp -> next = head;
        head -> previous = temp;
        head = temp;
    }
    
    else if(previousCityName == ""){
        tail -> next = temp;
        temp -> previous = tail;
        tail = temp;
    }
    
    else{
        City *current = head;
        while(current != nullptr && current -> cityName != previousCityName){
            current = current -> next;
        }
        if(current != nullptr){
            temp -> next = current -> next;
            current -> next = temp;
            temp -> previous = current;
            temp -> next -> previous = temp;
        }
    }
}

void CommunicationNetwork::deleteCity(std::string removeCity){
   // cout << tail -> cityName << " : " << tail -> previous -> cityName << endl;
    bool cityFound = false;
    if(head -> cityName == removeCity){                                 //if the city is the head
        City *nextCity = head -> next;
        delete head;
        head = nextCity;
        cityFound = true;
    }
    else if(tail -> cityName == removeCity){
        City *newTempCity = tail -> previous;
        delete tail;
        tail = newTempCity;
        tail -> next = nullptr;
        cityFound = true;
    }
    else{
        City *currentCity = head -> next;
        while(currentCity -> next != nullptr && !cityFound){
            if(currentCity -> next -> cityName == removeCity){
                City *newNextCity = currentCity -> next -> next;       //make pointer 2 nodes ahead
                delete currentCity -> next;
                currentCity -> next = newNextCity;
                newNextCity -> previous = currentCity;
                cityFound = true;
            }
            else{
                currentCity = currentCity -> next;                     //keep traversing through list
            }
        }
        if(!cityFound){
            cout << " not found, nothing deleted" << endl;
        }
    }
}

void CommunicationNetwork::deleteNetwork(){
    City *current = head;

    while(current != nullptr){
        City *temp = new City;
        temp = current;
        cout << "deleting " << temp -> cityName << endl;
        delete temp;
        current = current -> next;
    }
    head = nullptr;
    tail = nullptr;
}

