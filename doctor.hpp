#pragma once
#include <iostream>
#include <vector>
#include "hashCalendar.hpp"

using namespace std;

struct Doctor{
  string profession;
  string name;
  vector<int> available; // available dates vary per doctor
  bool followup;
  string fDoctor;
  struct Doctor* next;
};

class doctorHash{
  private:
    int tableSize = 10;
    Doctor** table; // Hash table array
    Doctor* createNode(string _name, string _profession, std::vector<int> _available,bool _followup,string _fDoctor);

  public:
      //Doctor* createNode(string _name, string _profession, std::vector<int> _available);
    doctorHash();
    void addDoctor(string _profession, string _name,std::vector<int> _available,bool _followup,string _fDoctor, Calendar &c);
    int hashFunction(string _profession);
    void printTable();
    Doctor* searchDoctor(string _name, string _profession);
};
