//Thomas Payne
//Assignment 1
//Zietz
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct item{
	string type;
	bool wanted;
	int price;
};

item itemArray[100];


void findItems(string filename){
    
	ifstream file;
	file.open(filename);

	if(file.fail()){
		cout << "file failed" << endl;
	}
	else{
        item tempItem;
        string line = "";
        int count = 0;                                      //determines array size
        
        while(getline(file, line)){                         //parse the lines
            stringstream currLine(line);
            string itemType, itemWanted, itemPrice;
            getline(currLine, itemType , ',');
            getline(currLine, itemWanted, ',');
            getline(currLine, itemPrice, ',');
            
            itemWanted.erase(0,1);                                  //erase space in front
            if(itemWanted == "for sale"){                           //turn 'for sale' and 'wanted' into bool values
                tempItem.wanted = true;                             // for sale = 1 wanted = 0
            }
            else{
                tempItem.wanted = false;
            }

            tempItem.type = itemType;                               //fills tempItem struct with proper values
            tempItem.price = stoi(itemPrice);

            bool match = false;
            for(int i = 0; i < count; i++){ 					    //Loops through large array
                if((itemArray[i].type == tempItem.type)){
                    if((itemArray[i].wanted == true && tempItem.wanted == false)){
                        if((itemArray[i].price <= tempItem.price)){
                            match = true;
                            cout << itemArray[i].type << " " << itemArray[i].price << endl;
                            
                            for(int j = i; j < count - 1; j++){         //removes struct of item and condenses
                                itemArray[j].type = itemArray[j+1].type;
                                itemArray[j].wanted = itemArray[j+1].wanted;
                                itemArray[j].price = itemArray[j+1].price; //overwrite the index in front with the previous index
                            }
                            count = count - 1; // -1 because we removed an index
                            break;
                        }
                    }
                    else if((itemArray[i].wanted == false && tempItem.wanted == true)){
                        if((itemArray[i].price >= tempItem.price)){
                            match = true;
                            cout << itemArray[i].type << " " << tempItem.price << endl;
                            
                            for(int j = i; j < count - 1; j++){         //removes struct of item and condenses
                                itemArray[j].type = itemArray[j+1].type;
                                itemArray[j].wanted = itemArray[j+1].wanted;
                                itemArray[j].price = itemArray[j+1].price;
                            }
                            count = count - 1;
                            break;
                        }
                    }
                }
            }
            if(match == false){                                    //adds item to array if top code didn't execute
                itemArray[count].type = tempItem.type;
                itemArray[count].wanted = tempItem.wanted;
                itemArray[count].price = tempItem.price;
                count++;
            }
        }
        cout << "#" << endl;
        for(int i = 0; i < count; i++){                         //simply prints the remaining array
            if(itemArray[i].wanted == true){
                cout << itemArray[i].type << ", " << "for sale" << ", " << itemArray[i].price << endl;
            }
            else if(itemArray[i].wanted == false){
                cout << itemArray[i].type << ", " << "wanted" << ", " << itemArray[i].price << endl;
            }
        }
        cout << "#" << endl;
    }
}


