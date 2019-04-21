#pragma once
#include<iostream>
#include <vector>

 struct CalendarNode
 {
   int day;
   std::string doctorName;
   bool firstApp;
   bool secondApp;
   std::string Patient1;
   std::string Patient2;
   CalendarNode* next;
   CalendarNode(std::string _doctorName, int _day)
   {
     doctorName = _doctorName;
     day = _day;
     firstApp = false;
     secondApp = false;
     Patient1 = "";
     Patient2 = "";
     next = NULL;
   }
 };

class Calendar
{
  private:
  int getHash(int _day);
  CalendarNode* searchTable(int _day,std::string word);

  /* instance variables */
  CalendarNode** hashCalendar;
  int size;
  public:
  Calendar();
  void addDoctorDay(int _day, std::string _doctorName);
  int checkDay(std::string _doctorName,int _day);
  std::vector<int> viewDoctorAvailability(std::string _doctorName);
  bool bookAppointment(std::string _doctorName, int day,std::string _patient);
  void cancelAppointment(std::string _doctorName, int _day, std::string _patient);
};
