#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
using namespace std;

struct wordItem{
    string word;
    int count;
};

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
    int count = 0;
    for(int i = 0; i < length; i++){
        count = count + list[i].count;
    }
    return count;
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


