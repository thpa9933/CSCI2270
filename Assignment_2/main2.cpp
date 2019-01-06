//Thomas Payne
//Assignment 2
//Zietz
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <stdlib.h>
#include "Assignment2.cpp"
using namespace std;



void resizeArray(wordItem* &oldArray, int* capacity){        //you are recieving the ADDRESS of the array
    int newCapacity = (*capacity * 2);                      //then dereference it (*) to change the values
    wordItem *newArray = NULL;
    newArray = new wordItem[newCapacity];
    for(int i = 0; i < *capacity; i++){
        newArray[i] = oldArray[i];
    }
    oldArray = NULL;
    delete[] oldArray;                                      //no memory leak
    oldArray = newArray;
    *capacity = newCapacity;
}

int main(int argc, char *argv[]){

    
    string ignoreWords[50];                          //pass this array in to multiple functions
    getStopWords(argv[3], ignoreWords);              //argv[3] is the ignoreWords file
    
    int timesDoubled = 0;
    int capacity = 100;
    int counter = 0;
    
    wordItem *array = new wordItem[capacity];        //declare instance of struct

    ifstream infile;
    infile.open(argv[2]);                            //argv[2] is the HungerGames file
    if(infile.is_open()){
        string line;
        while(getline(infile, line)){                //read in line, pull out individual words
            int check = 0;
            string word;
            stringstream ss(line);
            while(getline(ss, word, ' ')){
                if(isStopWord(word, ignoreWords) == true){              //check to see if word is stop word
                    //break;                                            //BAAD! This breaks you out of the line
                }
                
                else{
                    bool inArray = false;
                    for(int i = 0; i < capacity; i++){                 //loop through wordItem array
                        if(word == array[i].word){                     //return true if word is in array
                            inArray = true;
                            array[i].count++;                          //increase count if the word is found
                        }
                    }
                    if(inArray == false){
                        if(counter == capacity){                      //check if you need to resize
                            resizeArray(array, &capacity);
                            timesDoubled++;
                        }
                        array[counter].word = word;                   //add the word and initialize count to 1
                        array[counter].count = 1;
                        counter++;
                    }
                }
            }
        }
        getTotalNumberNonStopWords(array, counter);
        arraySort(array, counter);
        
        //RETURN STATEMENTS
        
        printTopN(array, atoi(argv[1]));
        cout << "Array doubled: " << timesDoubled << endl;
        cout << "#" << endl;
        cout << "Unique non-common words: " << counter << endl;
        cout << "#" << endl;
        cout << "Total non-common words: " << getTotalNumberNonStopWords(array, counter) << endl;

    }
    else{
        cout << "File did not open" << endl;
    }
}
