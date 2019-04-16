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

void Driver::assignPatient(string name,int _esi,int _cat){
    
    doctors[_cat-1].pq().enqueue(name, _esi);
    
}

void Driver::setDoctors(){
    
    
    
}
