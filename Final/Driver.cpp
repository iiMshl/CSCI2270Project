
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Driver.hpp"
#include "PriorityQueue.hpp"
#include "hashCalendar.hpp"

using namespace std;


bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),
            s.end(), [](char c) { return !std::isdigit(c); }) == s.end();
}


bool is_validDay(vector<int> v,string s){
    
    
    if (is_number(s)) {
        int x = stoi(s);
        
        if(std::find(v.begin(), v.end(), x) != v.end()) {
            
            return true;
        } else {
            
            return false;
        }
        
        
    } else {
        return false;
    }
    
}


int split(string str, char c, string array[], int size)
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


Driver::Driver(){
    
    
    
}
Driver::~Driver(){
    
    
    
}

void Driver::assignPatient(string name,int esi,int cat,int age){
    
    if (doctors[cat-1].patients.isFull()) {
        cout << "Dr. " << doctors[cat-1].name << " Has No Room For More Patients" << endl;
        cout << "Please Reassign To A Different Doctors" << endl;
    } else {
        doctors[cat-1].patients.enqueue(name, esi);
    }
    
}

void Driver::removePatient(int cat){
    
    if (doctors[cat-1].patients.isEmpty()) {
        cout << "Dr. " << doctors[cat-1].name << " Has No Patients" << endl;
    } else {
        cout << "Dr. " << doctors[cat-1].name << " Is Now Serving: " << doctors[cat-1].patients.peek().name << endl;
        
        
        //!!!!!USE CALENDAR HERE:
        if (doctors[cat-1].followup) {
            
            cout << "Dr. " << doctors[cat-1].name << " is recommending a followup appointment with Dr. " << doctors[cat-1].fDoctor << endl;
            
            string choice;
            vector<int> v = calendar.viewDoctorAvailability(doctors[cat-1].fDoctor);
            
            cout << endl << "Choose An Available Day to Book" << endl;
            getline(cin,choice);
            
            
            while ( !is_validDay(v,choice) ) {
                
                cout << "Please Enter A Valid Day: " << endl;
                getline(cin,choice);
            }
            
            
            calendar.bookAppointment(doctors[cat-1].fDoctor, stoi(choice), doctors[cat-1].patients.peek().name);
        } else {
            cout << "No Followup Is Needed" << endl;
        }
        
        doctors[cat-1].patients.dequeue();
        
        if (doctors[cat-1].patients.isEmpty()) {
            cout << "Dr. " << doctors[cat-1].name << " Has No More Patients" << endl;
        } else {
            cout << endl << "Next in line: " << doctors[cat-1].patients.peek().name <<endl;
        }
    }
    
}

void Driver::showNextPatient(){
    
    cout << "===========SERVING NEXT===========" << endl;
    for (int i=0; i<doctors.size(); i++) {
        
        if (doctors[i].patients.isEmpty()) {
            cout << "Dr. " << doctors[i].name << " Has No Patients" << endl;
        } else {
            cout << "Dr. " << doctors[i].name << " -> " << doctors[i].patients.peek().name << endl;
        }
        
    }
    cout << "==================================" << endl;
    
}

void Driver::setDoctors(string file){
    ifstream f(file);
    string line;
    string arr[5];
    string days[20];
    int daysCount = 0;
    bool followup = true;
    vector<int> availability;
    
    while (getline(f,line)) {
        
        split(line, ',', arr, 5);
        daysCount = split(arr[2], ' ', days, 20);
        
        if (arr[3] == "f") {
            followup = false;
        }
        
        for (int i = 0; i<daysCount; i++) {
            availability.push_back(stoi(days[i]));
            calendar.addDoctorDay(availability[i], arr[0]);
        }
        
        doctorsVect dc = doctorsVect(arr[0], availability, arr[1], followup, arr[4]);
        doctors.push_back(dc);
        availability.clear();
    }
    
    
}


void Driver::clearSection(int cat){
    
    
    if (doctors[cat-1].patients.isEmpty()) {
        cout << "Dr. " << doctors[cat-1].name << " Has No Patients" << endl;
    } else {
        
        while (!doctors[cat-1].patients.isEmpty()) {
            cout << "Clearing Patient: " << doctors[cat-1].patients.peek().name << endl;
            doctors[cat-1].patients.dequeue();
        }
        cout << "Cleared All Patients For Dr. " << doctors[cat-1].name << endl;
        
    }
    
}
