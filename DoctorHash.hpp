#include <iostream>

using namespace std;

struct Doctor{
  string profession;
  string name;
  int[] available;
  int availableLength;

  struct Doctor* next;
};

class doctorHash{
  private:
    int tableSize;
    Doctor* *table;
    Doctor* createNode(string name, string profession, int[] available, int availableLength, Doctor* next);

  public:
    doctorHash(int size);
    bool addDoctor(string profession, string name, int[] availability, int availableLength);
    unsigned int hashFunction();
    void printTable();
    Doctor* searchDoctor(string name, string profession);
};
