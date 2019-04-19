
#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Driver.hpp"
#include "PriorityQueue.hpp"
#include "hashCalendar.hpp"

using namespace std;



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
    
    doctors[cat-1].patients().enqueue(name, esi);
    
}

void Driver::removePatient(int cat){
    
    cout << "Serving Patient: " << doctors[cat-1].patients().peek().name << " | Doctor: " << doctors[cat-1].name << endl;
    doctors[cat-1].patients().dequeue();
    
    
    //!!!!!USE CALENDAR HERE:
    
    
}

void Driver::showNextPatient(){
    
    for (int i=0; i<doctors.size(); i++) {
        cout << "Doctor: " << doctors[i].name << " | Serving next: " << doctors[i].patients().peek().name << endl;
    }
    
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
    }
    
    
}
