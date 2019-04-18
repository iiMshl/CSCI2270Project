/*Bugs:
   - All bugs have to do with the availability array. Finding an alternative could resolve this.
*/

#include "doctor.hpp"
#include <iostream>

using namespace std;

doctorHash::doctorHash()
{
  table = new Doctor*[tableSize];

  for(int i = 0; i < tableSize; i++){
    table[i] = nullptr;
  }
}

Doctor* doctorHash::createNode(string _name, string _profession, std::vector<int> _available, bool _followup,string _fDoctor)
{
  Doctor* newDoctor = new Doctor;
  newDoctor->name = _name;
  newDoctor->profession = _profession;
  newDoctor->followup = _followup;
  newDoctor->fDoctor = _fDoctor;
    for(int i = 0; i < _available.size(); i++ )
    {
      (newDoctor -> available).push_back(_available[i]);
      cout <<(newDoctor -> available)[i] <<  " here" << endl;
    }
    newDoctor -> next = NULL;
  return newDoctor;
}

int doctorHash::hashFunction(string _profession)
{
  int sum = 0;
   for(int i = 0;i<_profession.length();i++)
   {
     sum = sum + _profession[i];
   }
   return sum % tableSize;
}
void doctorHash::addDoctor(string _profession, string _name,std::vector<int> _available,bool _followup, string _fDoctor,Calendar &c)
{
  int index = hashFunction(_profession);
  Doctor* doctorNode = createNode(_name,_profession,_available,_followup,_fDoctor);// create the new doctor here
  if(table[index] == NULL) /* EMPTY */
  {
    table[index]= doctorNode;
  }
  else
  {
      Doctor* current = table[index];
      Doctor* prev = NULL;
      while(current != NULL)
      {
          prev = current;
          current = current->next;
      }
        prev->next = doctorNode;
        //numCollisions++;
  }
  // for each day available create a hashCalendar node
  for(int j = 0; j < _available.size();j++)
  {
    c.addDoctorDay(_available[j],_name);
  }
}
// void printTable();
Doctor* doctorHash::searchDoctor(string name, string _profession)
{
  int index = hashFunction(_profession);
  Doctor* current = table[index];
  // Doctor* prev
  while(current != NULL)
  {
    if(current->profession == _profession)
    {
      return current;
    }
    else
    {
      current = current->next;
    }
  }
  return NULL;
}
