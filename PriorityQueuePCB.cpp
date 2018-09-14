
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

void PriorityQueuePCB::addPCB(PCB_ID_TYPE ID) //****need to make check if PriorityQueue (the vector) is big enough
{
	//check the PCB's priority level
	//insert the PCB into the apporpriate Queue Object within the PriorityQueue's queue vector (call the queue's add method)

	std::shared_ptr<ProcessControlBlock> PCBptrtoBeAdded = getPCB(ID);

	/* 
	each element of the vector PriorityQueue contains a queue.
	PCB's with priority 1 will be stored in the 1st index of the PriorityQueue vector (which is index 0)
	A PCB with priority 50 will be stored in the queue at index 49.
	*/
	PriorityQueue[PCBptrTobeAdded->priority - 1].enQueue(ID); //the PCB shared vector is stored within the queue using the queue's enQueue method
}

ProcessControlBlock PriorityQueuePCB::removePCB()
{
	//search linearly along the Priority queue's vector of queues.  the 1st queue that isn't empty pop off from that and return PCB
	//if doing pointers for optimization, return a shared pointer to the object

}

void PriorityQueuePCB::isEmpty()
{
//go through the entire priorityQueue vector and check each queue for any PCB objects (call the queuePCB method)

}

void PriorityQueuePCB::PrintPriorityQueue()
{
	//traverse the priority queue's vector and call the print method of each queue

}