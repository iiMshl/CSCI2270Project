

#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <string>
#include <cstring>
#include <stdio.h>


struct patientNode {
    std::string name;
    int esi;
};


class PriorityQueue
{
public:
    
    //Purpose: constructor
    PriorityQueue(int queueSize);
    PriorityQueue();
    
    // Purpose: deconstructor
    ~PriorityQueue();
    
    // Purpose: enqueue
    void enqueue (std::string name, int esi);
    
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
    
    patientNode* queuePointer; //pointer to the array used to implement priority queue
    int currentSize; //number of group currently in the priority queue
    int maxSize; //maximum capacity of priority queue
    
    
    //HELPER FUNCTIONS:
    int getLeftChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
    int getRightChildIndex(int parentIndex) { return 2 * parentIndex + 2; }
    int getParentIndex(int childIndex) { return (childIndex - 1) / 2; }
    
    bool hasLeftChild(int index, int size) { return getLeftChildIndex(index) < size; }
    bool hasRightChild(int index, int size) { return getRightChildIndex(index) < size; }
    bool hasParent(int index) { return getParentIndex(index) >= 0; }
};

#endif /* PriorityQueue_hpp */

