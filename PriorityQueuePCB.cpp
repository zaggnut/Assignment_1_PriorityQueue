
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

void PriorityQueuePCB::addPCB(PCB_ID_TYPE ID)
{
	//gets a shared_ptr to point to the PCB from the PCB table with the exact identity ID.
	std::shared_ptr<ProcessControlBlock> PCBptrtoBeAdded = *(getPCB(ID)); //getPCB(ID) returns an address of a shared pointer ==> used * operator

	/* 
	each element of the vector PriorityQueue contains a queue.
	PCB's with priority 1 will be stored in the 1st index of the PriorityQueue vector (which is index 0)
	A PCB with priority 50 will be stored in the queue at index 49.
	*/
	PriorityQueue[PCBptrTobeAdded->priority].enQueue(ID); //the PCB shared vector is stored within the queue using the queue's enQueue method
															//NOTE::: priority is of data type unsigned, the map key is of type int (implicit casting)
	PCBptrCount += 1;
}


std::shared_ptr<ProcessControlBlock> PriorityQueuePCB::removePCB() 
{

	for (auto q = PriorityQueue.begin(); q != PriorityQueue.end(); q++) //q should be pointer of PCBqueue  (I think)
	{
		if (!(q->isEmpty())) //if the pointed to queue is not empty //****************this i dont think works, pointer access to a function of an object.
		{
			PCBptrCount -= 1;
			return( q->dequeue() ) //the queue pointed by q returns a shared_ptr to the leading PCB item in the queue
		}
	}

	/*
	for (int i = 0; i < PriorityQueue.size(); i++) //need to use the std::map iterator
	{
		if (!PriorityQueue[i].isEmpty()) //calls PCBqueue::isEmpty(), not PriorityQueuePCB::isEmpty()
		{
			PCBptrCount -= 1;
			return (PriorityQueue[i].deQueue()); //removes the PCB item and returns it. then function terminates.
		}
	}
	*/
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