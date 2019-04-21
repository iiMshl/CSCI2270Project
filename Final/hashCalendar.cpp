#include<iostream>
#include<string>
#include<sstream>
#include <fstream>
#include <vector>

#include "hashCalendar.hpp"

using namespace std;


Calendar::Calendar()
{
  size = 10;
  hashCalendar = new CalendarNode* [size];
  for (int i = 0; i < size; i++) hashCalendar[i] = NULL;
}
int Calendar::getHash(int _day)
{
  return _day % 10;
}
CalendarNode* Calendar::searchTable(int _day,std::string doctor)
{
  int index = getHash(_day);
  CalendarNode* tmp = hashCalendar[index];
  while(tmp != NULL)
  {
    if(tmp->doctorName == doctor)
    {
      return tmp;
    }
    else
    {
      tmp = tmp->next;
    }
  }
  return NULL;
}

void Calendar::addDoctorDay(int _day, std::string _doctorName)
{
  int index = getHash(_day);
  CalendarNode* doctorNode = new CalendarNode(_doctorName,_day);// create the new doctor here
  if(hashCalendar[index] == NULL) /* EMPTY */
  {
    hashCalendar[index]= doctorNode;
  }
  else
  {
      CalendarNode* current = hashCalendar[index];
      CalendarNode* prev = NULL;
      while(current != NULL)
      {
          prev = current;
          current = current->next;
      }
        prev->next = doctorNode;
        //numCollisions++;
  }
}
int Calendar::checkDay(std::string _doctorName,int _day)
{
  CalendarNode* doctor = searchTable(_day,_doctorName);
  if(doctor != NULL)
  {
    if(doctor->firstApp == false && doctor->secondApp == false)
    {
      //std::cout << "Doctor " << doctor->doctorName << " has 2 available appointments " << std::endl;
      return 3; // this means 2 are open
    }
    else if(doctor->firstApp == false && doctor->secondApp == true)
    {
      //std::cout << "Doctor " << doctor->doctorName << " has a morning available appointment" << std::endl;
      return 1;
    }
    else if(doctor->firstApp == true && doctor->secondApp == false)
    {
      //std::cout << "Doctor " << doctor->doctorName << " has an evening available appointment" << std::endl;
      return 2;
    }
    else if(doctor->firstApp == true && doctor->secondApp == true)
    {
      //std::cout << "Doctor " << doctor->doctorName << " does not have any available appointments " << std::endl;
      return 0;
    }
  }
  // else
  // {
    std::cout << "Doctor " << doctor->doctorName << " does not have any available appointments" << std::endl;
    return 0;
  //  }
}
vector<int> Calendar::viewDoctorAvailability(std::string _doctorName)
{
    
    vector<int> vec;

    for (int i = 0; i < size; i++) {
        
        CalendarNode* node = hashCalendar[i];
        
        while (node!=NULL) {
            if (node->doctorName == _doctorName) {
                
                if (node->firstApp == false || node->secondApp == false) {
                    vec.push_back(node->day);
                }
            }
            node = node->next;
        }
        
    }
    
    if (vec.empty()) {
        cout << "Dr. " << _doctorName << " Has No Available Appointments" << endl;
    } else {
        cout << "Dr. " << _doctorName << " Is Available On The Following Days: " << endl;
        
        for (int i=0; i<vec.size(); i++) {
            cout << vec[i];
            if (i+1<vec.size())
                cout << ", ";
        }
        
    }
    
    return vec;
    
    
}
bool Calendar::bookAppointment(std::string _doctorName, int day,std::string _patient)
{
    
  CalendarNode* tmp = searchTable(day,_doctorName);
  int app = checkDay(_doctorName,day);
  string choice;
  //cout << "Doctor " << _doctorName << " Has ";
    
    
    if(app == 0) {
    cout << "Dr. " << _doctorName << " Has No Available Appointments For This Day" << std::endl;
    return false;
    } else {
        
        if (app==3) {
            
            cout << "Dr. " << _doctorName << " Has Two Available Appointments On This Day." << std::endl;
            cout << "(1.) Morning (2.) Evening" << endl;
            cout << "Please Enter Your Choice: " << endl;
            getline(std::cin,choice);
            
            while (choice < "1" && choice > "2") {
                cout << "Please Enter A Valid Answer" << endl;
                cout << "Dr. " << _doctorName << " Has Two Available Appointments On This Day." << std::endl;
                cout << "(1.) Morning (2.) Evening" << endl;
                cout << "Please Enter Your Choice: " << endl;
                getline(std::cin,choice);
            }
            
            if(stoi(choice) == 1)
            {
                cout << "Appointment Booked: " << endl;
                cout << "Patient: " << _patient << " || Dr: " << _doctorName << " || Date: " << day << " (Morning)" << endl;
                tmp->firstApp = true;
                tmp->Patient1 = _patient;
                return true;
            }
            else if(stoi(choice) == 2)
            {
                cout << "Appointment Booked: " << endl;
                cout << "Patient: " << _patient << " || Dr: " << _doctorName << " || Date: " << day << " (Evening)" << endl;
                tmp->secondApp = true;
                tmp->Patient2 = _patient;
                return true;
            }
            else
            {
                cout << "No scheduled appointments for patient " << _patient << std::endl;
                return false;
            }
            
            
            
        } else if (app==2){
            
            cout << "Dr. " << _doctorName << " Is Available In The Evening" << endl;
            cout << "Appointment Booked: " << endl;
            cout << "Patient: " << _patient << " || Dr: " << _doctorName << " || Date: " << day << " (Evening)" << endl;
            tmp->secondApp = true;
            tmp->Patient2 = _patient;
            
            return true;
            
        } else if (app==1){
            
            cout << "Dr. " << _doctorName << " Is Available In The Morning" << endl;
            cout << "Appointment Booked: " << endl;
            cout << "Patient: " << _patient << " || Dr: " << _doctorName << " || Date: " << day << " (Morning)" << endl;
            tmp->firstApp = true;
            tmp->Patient1 = _patient;
            
            return true;
        }
        
        
    }
    
    
  return false;
}
// void Calendar::cancelAppointment(std::string _doctorName, int _day, std::string _patient)
