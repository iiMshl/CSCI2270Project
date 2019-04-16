//
//  Driver.cpp
//  CSCI2270
//
//  Created by Meshal Almutairi on 4/15/19.
//  Copyright © 2019 Meshal Almutairi. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Driver.hpp"
#include "PriorityQueue.hpp"

using namespace std;


Driver::Driver(){
    
    
    
}
Driver::~Driver(){
    
    
    
}

void Driver::assignPatient(string name,int esi,int cat){
    
    doctors[cat-1].pq().enqueue(name, esi);
    
}

void Driver::setDoctors(){
    
    
    
}
