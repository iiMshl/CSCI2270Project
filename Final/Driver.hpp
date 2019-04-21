
#ifndef Driver_hpp
#define Driver_hpp

#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "PriorityQueue.hpp"
#include "hashCalendar.hpp"

using namespace std;


struct doctorsVect {
    
    string name;
    
    vector<int> availability;
    string profession;
    bool followup;
    string fDoctor;
    
    PriorityQueue patients;
    //Calendar cal;
    
    
    
    doctorsVect(string _name,vector<int> _availability,string _profession,bool _followup,string _fDoctor){
        
        name = _name;
        availability = _availability;
        profession = _profession;
        followup = _followup;
        fDoctor = _fDoctor;
        
        
    }
    
};


class Driver{
    
public:
    
    Driver();
    ~Driver();
    
    
    void setDoctors(string);
    
    
    void assignPatient(string name,int esi,int cat,int age);
    void removePatient(int cat);
    void showNextPatient();
    
    
private:
    
    vector<doctorsVect> doctors;
    Calendar calendar;
    //vector<patientNode> patients;
    
};


#endif /* Driver_hpp */
