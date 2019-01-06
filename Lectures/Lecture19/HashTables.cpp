//Lecture after graphs
//Hash Tables
//4/9/2018

#include <iostream>
using namespace std;

struct movieNode{
    string title;
    int inventory;
    float rating;
    movieNode* next;
};

class MovieHashTable{
private:
    int hashTableSize = 10;
    movieNode* hashTable[10];
    movieNode* createMovie(string, float);
    int hashSum(string);
    int hashMult(string);
public:
    MovieHashTable();
    ~MovieHashTable();
    bool addMovie(string, float);
    int findMovie(string);
    void printMovieInventory();
};

MovieHashTable::MovieHashTable(){
    for(int i = 0; i < hashTableSize; i++){
        hashTable[i] = nullptr;
    }
}
MovieHashTable::~MovieHashTable(){
    //delete every list
}



int MovieHashTable::hashSum(string key){
	int sum = 0;
	for (int i = 0; i < key.size(); i++){
		sum += key[i];
		//cout << "sum: " << sum << endl;
	}
	return sum%hashTableSize;
}

int MovieHashTable::hashMult(string key){
	int m = hashTableSize;
	float A = 13./32.;

	int sum = 0;
	for (int i = 0; i < key.size(); ++i){
		sum += key[i];
	}
	float kA = sum*A;
	float kARem = kA = int(kA);

	return int(kARem*m);
}

movieNode* MovieHashTable::createMovie(string movieName, float movieRating){
    movieNode *newMovie = new movieNode;
    newMovie -> title = movieName;
    newMovie -> rating = movieRating;
    newMovie -> inventory = 1;
    newMovie -> next = nullptr;
    
    return newMovie;
}

bool MovieHashTable::addMovie(string movieName, float movieRating){
    movieNode *newMovie = createMovie(movieName, movieRating);
    //figure out where to put it
    int tableLocation = hashSum(movieName);
    if(hashTable[tableLocation] == nullptr){
        hashTable[tableLocation] = newMovie;
        return true;
    }
    else{
        movieNode *temp = hashTable[tableLocation];
        while(temp -> next != nullptr){
            temp = temp -> next;
        }
        temp -> next = newMovie;
        return true;
    }
}

void MovieHashTable::printMovieInventory(){
    //iterate through hashtable
        //iterate through each spot in the hashtable
    int listCount = 1;
    int totalMovie = 0;
    for(int i = 0; i < hashTableSize; i++){
        cout << "At index " << i << ": " << endl;
        if(hashTable[i] == nullptr){
            cout << "No movies at this index" << endl;
        }
        else{
            movieNode* temp = hashTable[i];
            while(temp != nullptr){
                cout << "Movie " << listCount++ << ": " << temp -> title << endl;
                totalMovie++;
                temp = temp -> next;
            }
            //reset list count
            listCount = 1;
        }
        cout << endl;
    }
    cout << "There are " << totalMovie << " movies in the hash table" << endl;
}

int main(){
    
    MovieHashTable myMovielist;
    myMovielist.addMovie("Total Recall", 5.0);
    myMovielist.addMovie("The Running Man", 5.0);
    myMovielist.addMovie("Predator", 5.0);
    myMovielist.addMovie("Commando", 4.2);
    myMovielist.addMovie("Kindergarden Cop", 4.1);
    myMovielist.addMovie("Twins", 4.2);
    myMovielist.addMovie("Terminator", 4.5);
    myMovielist.printMovieInventory();
    
//    string hashTable[10];
//    int hashTableSize = 10;
//
//    cout << "Hash value Meeseeks and Destroy: " << hashSum("Meeseeks and Destroy", hashTableSize) << endl;
//    hashTable[hashSum("Meeseeks and Destroy", hashTableSize)] = "Meeseeks and Destroy";
//
//    cout << "Hash sum of Go Dog, Go: " << hashSum("Go Dog, Go",10) << endl;
//    cout << "Hash sum of Go Cat Go.: " << hashSum("Go Cat Go.",10) << endl;

	//handling collisions
	//open addressing
	//one approach: linear probing

	//chaining

	return 0;
}
