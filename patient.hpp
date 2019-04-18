
#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <string>
#include <cstring>
#include <stdio.h>


struct patientNode {

    std::string name;
    int age; // We will prioritize the patients that are older. Assume there are no kids in this Emergency room.
    int esi;
    std::string doctor;

    patientNode(std::string _name,int _age, int _esi,std::string _doctor)
    {
      name = _name;
      age = _age;
      esi = _esi;
      doctor = _doctor;
    }
};


class PatientQueue
{
public:

    //Purpose: constructor
    //PatientQueue(int queueSize);
    PatientQueue();

    // Purpose: deconstructor
    ~PatientQueue();

    // Purpose: enqueue
    void enqueue (std::string _name, int _esi, int _age);

    //Purpose: dequeue
    void dequeue();

    // return: patient node at the front of the priority queue
    patientNode peek();

    //return: true if queue is full, false otherwise
    bool isFull();

    // return: true if queue is empty, false otherwise
    bool isEmpty();

private:


    //Purpose: maintain heap properties by swapping node with parent if necessary
    void repairUpward(int nodeIndex);

    // Purpose: maintain heap properties by swapping node with child if necessary
    void repairDownward(int nodeIndex);

    patientNode* queue; //pointer to the array used to implement priority queue
    int currentSize; //number of group currently in the priority queue
    int maxSize; //maximum capacity of priority queue


    //HELPER FUNCTIONS:
    // int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
    // int getRightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }
    // int getParentIndex(int childIndex) { return (childIndex - 1) / 2; }

    // bool hasLeftChild(int index, int size) { return getLeftChildIndex(index) < size; }
    // bool hasRightChild(int index, int size) { return getRightChildIndex(index) < size; }
    // bool hasParent(int index) { return getParentIndex(index) >= 0; }
};

#endif /* PriorityQueue_hpp */
