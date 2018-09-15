
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
	PCBptrCount = 0;
}

//this construcutor is used to reserve the size of the vector data member of the class.
//this helps prevent the vector from being reallocated in memory everytime a Queue object is added in it
PriorityQueuePCB::PriorityQueuePCB(int TotalPriorityLevels)
{
	PCBptrCount = 0;
	PriorityQueue.reserve(TotalPriorityLevels); //the vector PriorityQueue now has reserved space for TotalPriorityLevels amount of Queue objects
}


void PriorityQueuePCB::addPCB(PCB_ID_TYPE ID) //****need to make check if PriorityQueue (the vector) is big enough
{
	//gets a shared_ptr to point to the PCB from the PCB table with the exact identity ID.
	std::shared_ptr<ProcessControlBlock> PCBptrtoBeAdded = getPCB(ID); //try using Auto to substitute the delcaration type

	/* 
	each element of the vector PriorityQueue contains a queue.
	PCB's with priority 1 will be stored in the 1st index of the PriorityQueue vector (which is index 0)
	A PCB with priority 50 will be stored in the queue at index 49.
	*/
	PriorityQueue[PCBptrTobeAdded->priority - 1].enQueue(ID); //the PCB shared vector is stored within the queue using the queue's enQueue method

	PCBptrCount += 1;
}

//searches linearly along the Priority queue's vector of queues.  
//the 1st queue that isn't empty pop off from that and return PCB shared_ptr
std::shared_ptr<ProcessControlBlock> PriorityQueuePCB::removePCB() 
{
	for (int i = 0; i < PriorityQueue.size(); i++)
	{
		if (!PriorityQueue[i].isEmpty()) //calls PCBqueue::isEmpty(), not PriorityQueuePCB::isEmpty()
		{
			PCBptrCount -= 1;
			return (PriorityQueue[i].deQueue()); //removes the PCB item and returns it. then function terminates.
		}
	}

	//******this seems like a bad way of handling the case of an empty PriorityQueue 
	throw PQisEmpty();  //this function requires shared_ptr return, but if there is no PCB item to return, then this dummy class is thrown for handling
	//do i need scope resolution operator ? PriorityQueuePCB::PQisEmpty()
}

void PriorityQueuePCB::isEmpty()
{
	if (PCBptrCount == 0)
		return true;
	else if (PCBptrCount > 0)
		return false;
	//else throw exception
	
	//go through the entire priorityQueue vector and check each queue for any PCB objects (call the queuePCB method)
	/*
	for (int i = 0; i < PriorityQueue.size(); i++)
	{
		//if any queue has an item ==>return false
		if (!PriorityQueue[i].isEmpty()) //calls PCBqueue::isEmpty()
		{
			return (false); //a PCBqueue had an item ==> return false
		}
	}

	return (true); //all the queues are empty ==> return true
	*/
}

void PriorityQueuePCB::PrintPriorityQueue()
{
	//traverse the priority queue's vector and call the print method of each queue
	for (int i = 0; i < PriorityQueue.size(); i++)
	{
		PriorityQueue[i].printQueue(); //prints the content of a PCBqueue (PCB objects)
	}
}

int PriorityQueuePCB::Size()
{
	return PCBptrCount;
}