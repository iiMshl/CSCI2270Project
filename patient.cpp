#include<iostream>
#pragma once

class Patient
{
    private:
      std::string name;
      int age;
      std::string injury;
      int ESI;
    public:
      Patient(std::string _name, int _age, std::string _injury, int _ESI);
};
