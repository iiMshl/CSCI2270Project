

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "PriorityQueue.hpp"

using namespace std;



void menu(){
    cout << "============Main Menu============" << endl;
    cout << "1. Get patients information from file" << endl;
    cout << "2. Add a patient" << endl;
    cout << "3. Show next patients in the queue from all sections" << endl;
    cout << "4. Serve next patient" << endl;
    cout << "5. Serve Entire Section" << endl;
    cout << "6. Quit" << endl;
}


int main(int argc, char const *argv[]){
    
    string choice;
    
    while (choice != "6") {
        menu();
        getline(cin, choice);
        switch (stoi(choice)) {
            case 1:{
                
                
                
                break;
            }
            case 2:{
                
                
                
                break;
            }
            case 3:{
                
                
                
                break;
            }
            case 4:{
                
                
                
                break;
            }
            case 5:{
                
                
                
                break;
            }
            case 6:{
                
                cout << "Goodbye!" << endl;
                
                break;
            }
            default:
                cout << "invalid input" << endl << endl;
        }
    }
    
}
