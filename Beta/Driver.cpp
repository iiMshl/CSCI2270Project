
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
