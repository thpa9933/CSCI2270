
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]){
    
    struct carData{
        string make;
        string model;
        string year;
    };
    
    carData car[10];
    
    ifstream infile;
    infile.open(argv[1]);
    
    ofstream outfile;
    outfile.open(argv[3]);
    
    int count = 0;
    
    if(infile.is_open()){
        cout << "file is open" << endl;
        string line = "";
        while(getline(infile, line)){
            stringstream ss(line);
            string make, model, year;
            getline(ss, make, ' ');
            getline(ss, model, ' ');
            getline(ss, year, ' ');
    
            car[count].make = make;
            car[count].model = model;
            car[count].year = year;

            outfile << car[count].make << "\t" << car[count].model << "\t" << car[count].year << endl;
            count++;
        }
    }
    else{
        cout << "file did not open properly" << endl;
    }
}
