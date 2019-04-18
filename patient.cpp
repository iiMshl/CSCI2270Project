#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "patient.hpp"


using namespace std;

void PatientQueue::repairUpward(int nodeIndex)
{
  if(nodeIndex > 0)
  {
    if(queue[nodeIndex].esi > queue[(nodeIndex - 1)/2].esi )
    {
      patientNode tempnode = queue[(nodeIndex - 1)/2];
      queue[(nodeIndex - 1)/2] = queue[nodeIndex];
      queue[nodeIndex] = tempnode;

      repairUpward(((nodeIndex - 1)/2));

    }
    else if(queue[nodeIndex].esi == queue[(nodeIndex - 1)/2].esi)
    {
      if(queue[nodeIndex].age < queue[(nodeIndex - 1)/2].age )
      {
        patientNode tempnode = queue[(nodeIndex - 1)/2];
        queue[(nodeIndex - 1)/2] = queue[nodeIndex];
        queue[nodeIndex] = tempnode;
        repairUpward(((nodeIndex - 1)/2));

      }
    }
  }
  else if(nodeIndex == 0)
  {
    return;
  }
}

void swap(struct patientNode& i, struct patientNode& j)
{
  patientNode temp  = i;
  i = j;
  j = temp;
}

bool isGreater(struct patientNode p1, struct patientNode p2) // g1 is the parent ---- g2 is the child
{
  if(p1.esi < p2._esi)
  {
    return false; // dont change
  }
  else if(p1.esi == p2.esi)
  {
    if(p1.age < p2.age)
    {
      return false;
    }
    else
    {
      return true;
    }
  }
  else
  {
    return true;
  }
}
void PatientQueue::repairDownward(int nodeIndex)
{
  int indexParent= nodeIndex;
  int indexRight = nodeIndex*2 + 2;
  int indexLeft = nodeIndex*2 + 1;
  int min =  nodeIndex;
  if(nodeIndex < currentSize - 1 )
  {
    if(indexLeft < currentSize)
    {
      if(isGreater(queue[indexParent],queue[indexLeft]) == 1) // if indexParent is greater
      {
        min = indexLeft;
      }
    }
    if(indexRight < currentSize)
    {
      if(isGreater(queue[indexParent],queue[indexRight]) == 1) // if indexParent is greater
      {
        min = indexRight;
      }
    }
  }
  if(nodeIndex == min) //BASE CASE//
  {
    return;
  }
  else
  {
    swap(queue[indexParent],queue[min]);
    repairDownward(min);
  }
}

PatientQueue::PatientQueue()
{

    maxSize = 25;
    currentSize = 0;

    queuePointer = new patientNode[25];

}


// Purpose: deconstructor
PatientQueue::~PatientQueue()
{

    delete [] queuePointer;

    queuePointer = 0;
    maxSize = 0;
    currentSize = 0;

}

// Purpose: enqueue
void PatientQueue::enqueue (std::string _name, int _esi,int _age,std::string _doctor)
{

    if (isFull()) {
        cout << "The hospital rooms are full! We recommend going to another location." << endl;
        return;
    }
    patientNode patient = new patientNode( _name, _age, _esi,_doctor)
    queue[currentSize] = node;
    repairUpward(currentSize);
    currentSize++;
}

//Purpose: dequeue
void PatientQueue:dequeue()
{

    if (isEmpty()) {
        cout << "Heap empty, cannot dequeue" << endl;
        return;
    }

    queue[0] = queuePointer[currentSize-1];
    repairDownward(0);
    currentSize--;

}
//
// // return: patient node at the front of the priority queue
// patientNode PatientQueue::peek(){
//
//     if (isEmpty()) {
//         cout << "Heap empty, nothing to peek" << endl;
//     }
//
//     return queuePointer[0];
//
// }
//
// //return: true if queue is full, false otherwise
// bool PatientQueue::isFull(){
//
//     return (currentSize==maxSize);
//
// }
//
// // return: true if queue is empty, false otherwise
// bool PatientQueue::isEmpty(){
//
//     return (currentSize==0);
//
// }
//
//
//
// //Private functions:
//
// //Purpose: maintain heap properties by swapping node with parent if necessary
// void PatientQueue::repairUpward(int nodeIndex){
//
//     while ((hasParent(nodeIndex)) && (queuePointer[getParentIndex(nodeIndex)].esi > queuePointer[nodeIndex].esi))
//     {
//
//
//         /* SWAPPING */
//         int parentIndex = getParentIndex(nodeIndex);
//         patientNode temp = queuePointer[parentIndex];
//         queuePointer[parentIndex] = queuePointer[nodeIndex];
//         queuePointer[nodeIndex] = temp;
//         /*          */
//         nodeIndex = getParentIndex(nodeIndex);
//
//
//     }
//
// }
//
// // Purpose: maintain heap properties by swapping node with child if necessary
// void PatientQueue::repairDownward(int nodeIndex){
//
//     while (hasLeftChild(nodeIndex, currentSize)) {
//
//         int smallerChildIndex = getLeftChildIndex(nodeIndex);
//
//         if (hasRightChild(nodeIndex, currentSize) && queuePointer[getRightChildIndex(nodeIndex)].esi >/*MAXHEAP*/ queuePointer[getLeftChildIndex(nodeIndex)].esi) {
//
//             smallerChildIndex = getRightChildIndex(nodeIndex);
//
//         }
//
//         if (queuePointer[nodeIndex].esi >/*MAXHEAP*/ queuePointer[smallerChildIndex].esi) {
//             break;
//         } else {
//             /* SWAPPING */
//             patientNode temp = queuePointer[smallerChildIndex];
//             queuePointer[smallerChildIndex] = queuePointer[nodeIndex];
//             queuePointer[nodeIndex] = temp;
//             /*          */
//             nodeIndex = smallerChildIndex;
//         }
//
//     }
//
// }
