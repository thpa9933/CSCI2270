//
//  Assignment4.h
//  Assignment4-2
//
//  Created by Sunil on 2/15/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef COMMUNICATIONNETWORK_H
#define COMMUNICATIONNETWORK_H

#include <iostream>

struct City{
    std::string cityName;
    std::string message;
    City *next;
    City *previous;
    
    City(){}; // default constructor
    
    City(std::string initName, City *initNext, City *initPrevious, std::string initMessage)
    {
        cityName = initName;
        next = initNext;
        previous = initPrevious;
        message = initMessage;
    }
};

class CommunicationNetwork
{
public:
    CommunicationNetwork();
    ~CommunicationNetwork();
    void buildNetwork();                    //check
    void addCity(std::string, std::string);
    void transmitMsg(char *);               //check
    void printNetwork();                    //check
    void deleteCity(std::string);
    void deleteNetwork();
protected:
private:
    City *head;
    City *tail;
};

#endif // COMMUNICATIONNETWORK_H
