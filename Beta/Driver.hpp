//
//  Driver.hpp
//  CSCI2270
//
//  Created by Meshal Almutairi on 4/15/19.
//  Copyright © 2019 Meshal Almutairi. All rights reserved.
//

#ifndef Driver_hpp
#define Driver_hpp

#include <string>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <vector>

#include "PriorityQueue.hpp"

using namespace std;



struct doctorNode {
    
    int cat;
    vector<int> availability;
    PriorityQueue pq();
    
    struct doctorNode* next; // pointer to the next node
    
};


class Driver{
    
public:
    
    Driver();
    ~Driver();
    
    
    void setDoctors();
    
    
    void assignPatient(string name,int esi,int cat);
    void removePatient(string name,int cat);
    
    
    
private:
    
    vector<doctorNode> doctors;
    vector<patientNode> patients;
    
};


#endif /* Driver_hpp */
