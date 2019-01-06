#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct student{
    int studentId;
    string studentName;
    string studentMajor;
};

int main(){
    student studentArray[10];
    int numStudents = 0;
    ifstream infile;
    infile.open("students.txt");
    
    if(infile.fail()){
        cout << "issue opening file" << endl;
    }
    else{
        cout << "file opened properly" << endl;
        string currentLine;
        while(getline(infile, currentLine)){
            cout << "i just read: " << currentLine << endl;
        }
        infile.clear();
        infile.seekg(0, ios::beg);              //resets file as if we didnt read in any lines
        
        while(getline(infile, currentLine)){    //parse the file using string stream
            stringstream curStrStream(currentLine);
            string curId, curSName, curSmaj = "";
            getline(curStrStream, curId, ',');
            getline(curStrStream, curSName,',');
            getline(curStrStream, curSmaj);
            cout << "id: " << curId << endl;
            cout << "name: " << curSName << endl;
            cout << "major: " << curSmaj << endl;
            
            studentArray[numStudents].studentId = stoi(curId);
            studentArray[numStudents].studentName = curSName;
            studentArray[numStudents].studentMajor = curSmaj;
            
            numStudents++;

        }
    }
    infile.close();
    
    ofstream outFile;
    outFile.open("studentinfo.txt");
    
    for(int i = 0; i < numStudents; i++){
        outFile << studentArray[i].studentId << "\t" << studentArray[i].studentName << "\t" << studentArray[i].studentMajor << endl;
    }
}
