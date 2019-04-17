/*Bugs:
   - All bugs have to do with the availability array. Finding an alternative could resolve this.
*/

#include "DoctorHash.hpp"
#include <iostream>

using namespace std;

Doctor* doctorHash::createNode(string name, string profession, int[] available, int availableLength, Doctor* next){
  Doctor* newDoc = new Doctor;
  newDoc -> name = name;
  newDoc -> profession = profession;
  newDoc -> available = available[availableLength];   //Will have to change this if we decide to go with a list of structs instead.
                                                      //Also thinking about changing this to a vector since I'm not sure how to implement the array size.
  newDoc -> availableLength = availableLength;
  newDoc -> next = next;

  return newDoc;
}

doctorHash::doctorHash(int size){
  this -> tableSize= size;
  table = new Doctor*[tableSize];

  for(int i = 0; i < size; i++){
    table[i] = nullptr;
  }
}

bool doctorHash::addDoctor(string profession, string name, int[] available, int availableLength){
  bool success;

  if(!searchDoctor(name, profession)){
    int index = hashFunction();
    Doctor* root = table[index];
    if(root == NULL){
      table[index] = createNode(name, profession, available, availableLength, NULL);
    }
    else{
      table[index] = createNode(name, profession, available, availableLength, root);
    }

    success = true;
  }
  else{
    cout<<"Duplicate entry: " << name << " already exists in the database." << endl;
    success = false;
  }

  return success;
}

unsigned int doctorHash::hashFunction(){
  //Not sure how we're planning on organizing the doctors. By profession? By name?
}

void doctorHash::printTable(){
  for (int i = 0; i < tableSize; i++) {
    cout << i <<"|| ";

    Doctor* Doc = table[i];

    while(Doc != NULL){
      cout << Doc -> name << " - " << Doc -> profession << " - Available at: ";
      for(int j = 0; j < availableLength; j++){   //Could replace with that traverse function the professors have used. Need to look up how to implement.
        cout << available[j] << " ";
      }
      cout << endl;

      Doc = Doc -> next;
    }
  }
}

Doctor* doctorHash::searchDoctor(string name, string profession){
  //Compute the index by using the hash function
  int index = hashFunction();   //May need to add other parameters to this functions and others that use the hash function depending on what we end up
                                //organizing by
  Doctor* Doc = table[index];

  while(Doc != NULL){
    if((Doc -> profession == profession) && (Doc -> name == name)){
      return Doc;
    }
    else{
      Doc = Doc -> next;
    }
  }
  return NULL;
}
