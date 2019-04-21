

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Driver.hpp"

using namespace std;

int splitt(string str, char c, string array[], int size)
{
    if (str.length() == 0) {
        return 0;
    }
    string word = "";
    int count = 0;
    str = str + c;
    for (int i = 0; (unsigned)i < str.length(); i++)
    {
        if (str[i] == c)
        {
            if (word.length() == 0)
                continue;
            array[count++] = word;
            word = "";
        } else {
            word = word + str[i];
        }
    }
    return count ;
}

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
    
    cout << "1. Cardiologist" << endl;
    cout << "2. Orthopedic Surgeon" << endl;
    cout << "3. Dermatologist" << endl;
    cout << "4. Neurologist" << endl;
    cout << "5. Physiatrist" << endl;
    cout << "6. Pulmonologist" << endl;
    cout << "7. Chiropractor" << endl;
    cout << "8. Gastroenterologist" << endl;
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
                
                
                string file;
                
                cout << "Enter File Name: " << endl;
                getline(cin,file);
                
                ifstream f(file);
                string line;
                string arr[4];
                int count = 0;
                
                if (f.is_open()) {
                    cout << "Adding Patients.." << endl;
                    while(getline(f,line)){
                        
                        splitt(line, ',', arr, 4);
                        
                        dr.assignPatient(arr[0], stoi(arr[1]), stoi(arr[3]), stoi(arr[2]));
                        count ++;
                    }
                    cout << "Added " << count << " Patient" << endl;
                } else
                    cout << "Failed to open file (" << file << ")" << endl;
                
                
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
                
                cout << "Choose a Doctor to See: " << endl;
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
                
                cout << "Choose A Doctor No. (1-9) Enter 0 To Show Doctors" << endl;
                getline(cin,entry);
                
                while (entry < "1") {
                    if (entry == "0") {
                        showCats();
                    }
                    cout << "Choose A Doctor No. (1-9) Enter 0 To Show Doctors" << endl;
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
