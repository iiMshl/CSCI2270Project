

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "PriorityQueue.hpp"

using namespace std;





int getESI(){
    
    string choice;
    bool invalid = true;
    
    while (invalid) {
        invalid = false;
        
        cout << "does it require immediate life-saving intervention? \n(1.) Yes (2.) No" << endl;
        getline(cin,choice);
        
        //Q1 Answer
        if (choice=="1") {
            return 1;
            
        } else if (choice=="2"){
            
            cout << "Is it a high risk situation, or a severe pain/distress? \n(1.) Yes (2.) No" << endl;
            getline(cin,choice);
            
            //Q2 Answer
            if (choice=="1") {
                return 2;
            } else if (choice=="2"){
                
                cout << "how many different resources are needed for it? \n(1.) None (2.) One (3.) Many" << endl;
                getline(cin,choice);
                
                //Q3 Answer
                if (choice=="1") {
                    return 5;
                } else if (choice=="2"){
                    return 4;
                } else if (choice=="3"){
                    
                    cout << "are vitals in danger zone? \n(1.) Yes (2.) No" << endl;
                    getline(cin,choice);
                    
                    //Q4 Answer
                    if (choice=="1") {
                        return 2;
                    } else if (choice=="2"){
                        return 3;
                    } else { cout<<"Invalid input"<<endl; invalid=true;continue;}
                    
                } else { cout<<"Invalid input"<<endl; invalid=true;continue;}

            } else { cout<<"Invalid input"<<endl; invalid=true;continue;}

        } else { cout<<"Invalid input"<<endl; invalid=true;continue;}

    }
    
    return 5;
}


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
