

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "PriorityQueue.hpp"
#include "Driver.hpp"
#include "hashCalendar.hpp"

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

void showCats(){
    
    cout << "1. Heart/Blood Vessels (Cardiologist)" << endl;
    cout << "2. " << endl;
    cout << "3. " << endl;
    cout << "4. " << endl;
    cout << "5. " << endl;
    cout << "6. " << endl;
    cout << "7. " << endl;
    cout << "8. " << endl;
    cout << "9. Other (General)" << endl;
    
}

void menu(){
    cout << "============Main Menu============" << endl;
    cout << "1. Get patients information from file" << endl;
    cout << "2. Add a patient" << endl;
    cout << "3. Show next patients in the queue from all sections" << endl;
    cout << "4. Serve next patient" << endl;
    cout << "5. Clear Entire Section" << endl;
    cout << "6. Quit" << endl;
}


int main(int argc, char const *argv[]){
    
    string choice;
    
    Driver dr;
    
    dr.setDoctors("doctors.txt");
    
    while (choice != "6") {
        menu();
        getline(cin, choice);
        switch (stoi(choice)) {
            case 1:{
                
                
                
                
                break;
            }
            case 2:{
                string name;
                int esi;
                string cat;
                string age;
                
                cout << "Enter Patient Name: " << endl;
                getline(cin,name);
                
                cout << "Enter Patient Age: " << endl;
                getline(cin,age);
                
                cout << "What Would your injury categorize as?" << endl;
                showCats();
                getline(cin,cat);
                
                esi = getESI();
                
                dr.assignPatient(name, esi, stoi(cat),stoi(age));
                
                
                break;
            }
            case 3:{
                
                dr.showNextPatient();
                
                break;
            }
            case 4:{
                
                string entry;
                
                cout << "Choose A Category (1-9) Enter 0 To Show Categories" << endl;
                getline(cin,entry);
                
                while (entry < "1") {
                    if (entry == "0") {
                        showCats();
                    }
                    cout << "Choose A Category (1-9) Enter 0 To Show Categories" << endl;
                    getline(cin,entry);
                }
                
                dr.removePatient(stoi(entry));
                
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
