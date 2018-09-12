

#include <iostream>
#include <vector>
using namespace std;


#include "PriorityQueuePCB.hpp"

//these should already be included within PriorityQueuePCB.hpp
#include "PCB.hpp"
#include "PCB_Table.hpp"


PriorityQueuePCB::~PriorityQueuePCB()
{
	//do something
}
PriorityQueuePCB::PriorityQueuePCB()
{
	//do something
}

//this construcutor is used to reserve the size of the vector data member of the class.
//this helps prevent the vector from being reallocated in memory everytime a Queue object is added in it
PriorityQueuePCB::PriorityQueuePCB(int TotalPriorityLevels)
{
	PriorityQueue.reserve(TotalPriorityLevels); //the vector PriorityQueue now has reserved space for TotalPriorityLevels amount of Queue objects
}



/*
~PriorityQueuePCB();
PriorityQueuePCB();
PriorityQueuePCB(int TotalPriorityLevels);

void addPCB(ProcessControlBlock PCBtoBeAdded);
ProcessControlBlock removePCB();
bool isEmpty();
void PrintPriorityQueue();
*/