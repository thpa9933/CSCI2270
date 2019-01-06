//Thomas Payne
//Assignment 2
//Zietz
#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <stdlib.h>
using namespace std;

struct wordItem{
    string word;
    int count;
};


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

//open the file and get each line
//string stream to parse individual word
//add word to ignoreWord array
void getStopWords(char *ignoreWordFileName, string ignoreWords[]){
    int count = 0;
    ifstream inFile;
    inFile.open(ignoreWordFileName);
    if(inFile.is_open()){
        string line;
        while(getline(inFile, line)){
            string word;
            stringstream ss(line);
            while(getline(ss, word, ' ')){
                ignoreWords[count] = word;
                count++;
            }
        }
    }
    else{
        cout << "File did not open properly" << endl;
    }
}

//look through the ignoreWords array to determine if there is a match
//return true if there is
bool isStopWord(string word, string ignoreWords[]){
    for(int i = 0; i < 50; i++){
        if(ignoreWords[i] == word){
            return true;
        }
    }
    return false;
}

//tally up the counts of each word in the array
int getTotalNumberNonStopWords(wordItem list[], int length){
    int counts = 0;
    for(int i = 0; i < length; i++){
        counts = counts + list[i].count;
    }
    return counts;
}

//sort the array in decending order
//bubble sort method
//check to see if the ord in front is greater than the word behind
//if so switch them
void arraySort(wordItem list[], int length){
    bool sorted = false;
    while(!sorted){
        sorted = true;
        wordItem temp;
        for(int i = 0; i < length; i++){
            if(list[i].count < list[i + 1].count){
                temp = list[i];
                list[i] = list[i + 1];
                list[i+1] = temp;
                sorted = false;
            }
        }
    }
}

//search through sorted words
//return top words and values
void printTopN(wordItem wordItemList[], int topN){
    for(int i = 0; i < topN; i++){
        cout << wordItemList[i].count << " - " << wordItemList[i].word << endl;
    }
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
            string word;
            stringstream ss(line);
            while(ss >> word){
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
        arraySort(array, counter);
        
        //RETURN STATEMENTS
        
        printTopN(array, atoi(argv[1]));
        cout << "#" << endl;
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

