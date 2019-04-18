#include<iostream>
#include<string>
#include<sstream>
#include <fstream>
#include "hashCalendar.hpp"

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
      std::cout << "Doctor " << doctor->doctorName << " has 2 available appointments " << std::endl;
      return 3; // this means 2 are open
    }
    else if(doctor->firstApp == false && doctor->secondApp == true)
    {
      std::cout << "Doctor " << doctor->doctorName << " has a morning available appointment" << std::endl;
      return 1;
    }
    else if(doctor->firstApp == true && doctor->secondApp == false)
    {
      std::cout << "Doctor " << doctor->doctorName << " has an evening available appointment" << std::endl;
      return 2;
    }
    else if(doctor->firstApp == true && doctor->secondApp == true)
    {
      std::cout << "Doctor " << doctor->doctorName << " does not have any available appointments " << std::endl;
      return 0;
    }
  }
  // else
  // {
    std::cout << "Doctor " << doctor->doctorName << " does not have any available appointments" << std::endl;
    return 0;
  //  }
}
void Calendar::viewDoctorAvailavility(std::string _doctorName)
{
  for(int i = 0; i < size; i++)
  {
    CalendarNode* doctor = hashCalendar[i];

    while(doctor != NULL)
    {
        if(doctor->firstApp == false && doctor->secondApp == false)
        {
          std::cout << "Doctor " << doctor->doctorName << " has 2 available appointments on the " <<  doctor->day << std::endl;
          //return true;
        }
        else if(doctor->firstApp == false && doctor->secondApp == true)
        {
          std::cout << "Doctor " << doctor->doctorName << " has a morning available appointment on the " <<  doctor->day << std::endl;
          //return true;
        }
        else if(doctor->firstApp == true && doctor->secondApp == false)
        {
          std::cout << "Doctor " << doctor->doctorName << " has an evening available appointment on the " <<  doctor->day << std::endl;
          //return true;
        }
        else if(doctor->firstApp == true && doctor->secondApp == true)
        {
          std::cout << "Doctor " << doctor->doctorName << " does not have any available appointments on the " <<  doctor->day << std::endl;
          //return false;
        }
        doctor = doctor->next;
    }
  }
}
void Calendar::bookAppointment(std::string _doctorName, int day,std::string _patient)
{
  CalendarNode* tmp = searchTable(day,_doctorName);
  int app = checkDay(_doctorName,day);
  std::string choice;
  std::cout << "Doctor " << _doctorName << " has ";
  if(app == 3)
  {
    std::cout << "two available appointments." << std::endl;
    std::cout << "Enter 1 to schedule for morning" << std::endl;
    std::cout << "Enter 2 to schedule for afternoon" << std::endl;
    std::cout << "Enter Q to disreguard" << std::endl;
    getline(cin,choice);
    while(choice != "1" || choice != "2" || choice != Q)
    {
      std::cout << "Select one of the appointments or enter Q to cancel " << std::endl;
      getline(cin,choice);
    }
    if(choice == "1")
    {
      tmp->firstApp == true;
      tmp->Patient1 = _patient;
    }
    else if(choice == "2")
    {
      tmp->secondApp == true;
      tmp->Patient2 = _patient;
    }
    else
    {
      std::cout << "No scheduled appointments for patient " << _patient << std::endl;
    }
  }
  else if(app == 2)
  {
    std::cout << "There is only an afternoon appointment" << std::endl;
    std::cout << "Do you want to schedule this appointment?" << std::endl;
    std::cout << "Enter (1) to confirm" << std::endl;
    std::cout << "Enter (2) otherwise" << std:::endl;
    getline(cin,choice);
    while(choice != "1" || choice != "2")
    {
      std::cout << "Enter a valid answer" << std::endl;
      getline(cin,getline);
    }
  }
  else if(app == 1)
  {

  }
  else if(app == 0)
  {

  }
}
// void Calendar::cancelAppointment(std::string _doctorName, int _day, std::string _patient);
