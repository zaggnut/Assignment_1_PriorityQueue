/*
Purpose: Implement the class PriorityQueuePCB for ProcessControlBlock objects.
Creation Date: 9/12/2018
Created By: Shane Laskowski
Date Of Last Modifcation: 9/16/2018
Last Modification By: Michael Lingo
*/


#include "PriorityQueuePCB.hpp"


void PriorityQueuePCB::addPCB(ProcessControlBlock* PCBtoBeAdded)
{
	PCBtoBeAdded->state = processState::READY;
	PriorityQueue[PCBtoBeAdded->priority].enQueue(PCBtoBeAdded);
	//check the PCB's priority level
	//insert into correct place
}

ProcessControlBlock* PriorityQueuePCB::removePCB()
{

	auto toDequeue = PriorityQueue.begin();
	auto toReturn = toDequeue->second.deQueue();
	if (toDequeue->second.isEmpty())
	{
		PriorityQueue.erase(toDequeue);
	}
	return toReturn;

	//begin iterator always points to the highest priority
}

bool PriorityQueuePCB::isEmpty()
{
	return PriorityQueue.empty();
	//true if the map object is empty
}

void PriorityQueuePCB::PrintPriorityQueue()
{
	if (isEmpty())
	{
		std::cout << "The priority queue is empty" << std::endl;
		return;
	}
	std::cout << std::right; //align right
	std::cout.width(5);
	std::cout << "ID";
	std::cout.width(10);
	std::cout << "State";
	std::cout.width(15);
	std::cout << "Priority" << std::endl;
	//std::cout << "\tID\tState\tPriority" << std::endl;
	for (auto it = PriorityQueue.begin(); it != PriorityQueue.end(); it++)
	{
		//std::cout << "Priority: " << it->first << std::endl;
		it->second.printQueue();
	}
	//traverse the priority queue's map and call the print method of each queue
}