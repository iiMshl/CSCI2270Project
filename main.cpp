#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<map>
#include<vector>
#include "hashCalendar.hpp"
#include "doctor.hpp"
// #include "patient.hpp"
void readDoctors(std::string filename,)
{
  std::ifstream fin(filename);
  if(fin.is_open())
  {
    // User usersIF[100]; // Address database (array of structures)
    // int size = 0;
    std::string line;
    while(getline(fin,line))
    {
      std::string _specialization, _days, _doctorName;// create temporary holders to later convert to floats and integers.
     int days;
      std::string d;
      std::vector<int> addDays;
    //   float gpa;
    //   float mingpa = atof(argv[3]);
      std::stringstream sin(line);
      //std::stringstream din(_days);
      getline(sin, _doctorName, ',');
      getline(sin, _specialization, ',');
      getline(sin, _days, ',');
      std::cout << _doctorName << " " << _specialization <<  std::endl;//" " << _days << std::endl;
      std::stringstream tin(_days);
      while(getline(tin,d,' '))
      {
        days = stoi(d);
        std::cout << days  << " - ";// add the days to vector
      }
    //   age = stoi(tempage);
    //   gpa = stof(tempgpa);
    //   if(mingpa <= gpa)
    //   {
    //     oFile << line << std::endl;
    //   }
    //   addUser(usersIF, name, gpa, age,size);

    //   size++;

    std::cout << std::endl;
    }
    // std::cout << calendar.size() << " size of table";
  }
    fin.close();
}


int main()
{
  Calendar m;
  doctorHash d;
  // std::vector<int> myVec;
  //std::map<int,std::string> ma;
  std::string word = "1234";
  std::vector<int> v;
  int sum = 0;
  for(int i = 0;i<word.length();i++)
  {
    sum = sum + word[i];
    v.push_back(sum);
    std::cout << sum <<  " main  "  << std::endl;
  }
  d.addDoctor("cardiologist","Erik",v,true,"Lupita",m);
  // std::vector<int> t;
  // // v = t;
  // for(int j = 0; j < v.size() ;j++)
  // {
  //   t.push_back(v[j]);
  //   std::cout << v[j]  << " " << t[j] <<std::endl;
  // }
  //
  // for(int i = 0; i < 5; i++)
  // {
  //   myVec.push_back(i);
  // }
  // ma.insert( std::pair<int,std::string>(6,"erik"));
  // ma.insert( std::pair<int,std::string>(6,"erik"));
  // std::cout << ma.size() << std::endl;
  // ma.insert( std::pair<int,std::string>(4,"alan"));
  // std::cout << ma.size() << std::endl;
  // std::ifstream fin("doctors.txt");
  // if(fin.is_open())
  // {
  //   // User usersIF[100]; // Address database (array of structures)
  //   // int size = 0;
  //   std::string line;
  //   while(getline(fin,line))
  //   // {
  //   //   std::string name, tempgpa, tempage; // create temporary holders to later convert to floats and integers.
  //   //   int age;
  //   //   float gpa;
  //   //   float mingpa = atof(argv[3]);
  //   //   std::stringstream sin(line);
  //   //   getline(sin, name, ',');
  //   //   getline(sin, tempgpa, ',');
  //   //   getline(sin, tempage, ' ');
  //   //   age = stoi(tempage);
  //   //   gpa = stof(tempgpa);
  //   //   if(mingpa <= gpa)
  //   //   {
  //   //     oFile << line << std::endl;
  //   //   }
  //   //   addUser(usersIF, name, gpa, age,size);
  //
  //   //   size++;
  //
  //   std::cout << line << std::endl;
  //   }
  // //}
  //   fin.close();
  // readDoctors("doctors.txt");
  return 0;
}
