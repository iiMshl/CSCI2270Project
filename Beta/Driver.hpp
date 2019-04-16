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


/* MIGHT DELETE */
struct patient {
    
    string name;
    int esi;
    int cat;
    
};

struct doctor {
    
    int cat;
    vector<int> availability;
    PriorityQueue pq();
    
    struct doctor* next; // pointer to the next node
    
};


class Driver{
    
public:
    
    Driver();
    ~Driver();
    
    void assignPatient(string name,int _esi,int _cat);
    void setDoctors();
    
    
    
private:
    
    vector<doctor> doctors;
    vector<patient> patients;
    
};


#endif /* Driver_hpp */
