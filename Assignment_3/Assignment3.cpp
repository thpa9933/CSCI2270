//Thomas Payne
//Assignment 3

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct city{
    std::string cityName;
    std::string message;
    city *next;
    
    city(){};                                                           //default constructor
    city(std::string initName, city *initNext, std::string initMessage)
    {
        cityName = initName;
        next = initNext;
        message = initMessage;
    }
};

city *buildNetwork(){
    string cityArray[] = {"Phoenix", "Denver", "Dallas", "St. Louis", "Chicago","Atlanta", "Washington, D.C.", "New York", "Boston"};
    
    city *head = new city;
    head -> next = nullptr;
    head -> cityName = "Los Angeles";
    head -> message = "";
    city *current = head;        //make your current city point to head to start at beginning of list

    for(int i = 0; i < 9; i++){                             //traverse through list
        city *temp = new city(cityArray[i], nullptr, "");   //add new nodes to list
        current -> next = temp;
        current = current -> next;
    }
    current = head;

//    cout << "===CURRENT PATH===" << endl;                   //print path
//    while(current != nullptr){
//        cout << current -> cityName << " -> ";
//        current = current -> next;
//    }
//    cout << " NULL" << endl;
//    cout << "==================" << endl;
    return head;
}

void printPath(city * head){
    city *current = head;
    cout << "===CURRENT PATH===" << endl;
    while(current != nullptr){                              //move through the list
        cout << current -> cityName << " -> ";              //print out CityName
        current = current -> next;
    }
    cout << " NULL" << endl;
    cout << "==================" << endl;
}

void transmitMsg(city*head){
    ifstream infile;
    infile.open("messageIn.txt");
    if(infile.is_open()){                                   //read in a file and parse by word
        string line;
        while(getline(infile, line)){
            string word;
            stringstream ss(line);
            while(getline(ss, word, ' ')){
                city *currentCity = head;
                while(currentCity != nullptr){              //move through the list
                    cout << currentCity -> cityName << " received " << word << endl;
                    currentCity -> message = "";            //reset the message to nothing
                    currentCity = currentCity -> next;
                }
            }
        }
    }
    else{
        cout << "file did not open properly" << endl;
    }
}

city *addCity(city *head, city*previous, string cityname){
    
//    cout << "previous :" << previous -> cityName << endl;
//    cout << "head: " << head -> cityName << endl;
    if(head == nullptr){                                                //if list is empty
//        cout << "if list is empty" << endl;
        city * newCity = new city(cityname, nullptr, "");
        head = newCity;
    }
    else if(previous == nullptr){                                       //end of list
//        cout << "end of list" << endl;
        city * newCity = new city(cityname, nullptr, "");
        newCity -> next = nullptr;
        previous -> next = newCity;                                     //reassign pointer to newCity
    }
    else if(previous -> cityName == head -> cityName){                //beginning of list
//        cout << "beginning of list" << endl;
        city * newCity = new city(cityname, nullptr, "");             //make new city
        newCity -> next = previous;                                   //reassign the pointer
        head = newCity;
        //reset head to previous
    }
    else{                                                               //in the middle
//        cout << "middle of list" << endl;
        city * newCity = new city(cityname, nullptr, "");
        newCity -> next = previous -> next;
        previous -> next = newCity;                                     //reassign pionter to new city
    }
    return head;
}


int main(){
    city *head = nullptr;

    cout << "======Main Menu======" << endl;
    cout << "1. Build Network" << endl;
    cout << "2. Print Network Path" << endl;
    cout << "3. Transmit Message Coast-To-Coast" << endl;
    cout << "4. Add City" << endl;
    cout << "5. Quit" << endl;

    int number;
    cin >> number;

    while(number != 0){
        
        if(number == 1){
            head = buildNetwork();
        }
        
        if(number == 2){
            printPath(head);
        }
        
        if(number == 3){
            transmitMsg(head);
        }
        
        if(number == 4){

            string input1;
            string input2;
            cout << "Enter a City name:" << endl;
            getline(cin.ignore(), input2);
            cout << "Enter a previous City name:" << endl;
            getline(cin, input1);
            city *currentCity = head;
            city *previous;

            while(currentCity != nullptr){                   //traverse through list
                if(currentCity -> cityName == input1){
//                    cout << "input 1: " << input1 << endl;
//                    cout << "currentcity cityname" << currentCity -> cityName << endl;
                    previous = currentCity;                 //find where currentCity is
                    break;
                }
                else{
                    currentCity = currentCity -> next;
                }
            }
            head = addCity(head, previous, input2);
        }

        if(number == 5){
            cout << "Goodbye!" << endl;
            break;
        }
        
        cout << "======Main Menu======" << endl;
        cout << "1. Build Network" << endl;
        cout << "2. Print Network Path" << endl;
        cout << "3. Transmit Message Coast-To-Coast" << endl;
        cout << "4. Add City" << endl;
        cout << "5. Quit" << endl;
        
        cin >> number;
    }
    
    return 0;
}
