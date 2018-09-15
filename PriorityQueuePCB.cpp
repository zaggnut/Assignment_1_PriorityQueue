
#include "PriorityQueuePCB.hpp"


void PriorityQueuePCB::addPCB(std::shared_ptr<ProcessControlBlock> PCBtoBeAdded)
{
	PCBtoBeAdded->state = processState::READY;
	PriorityQueue[PCBtoBeAdded->priority].enQueue(PCBtoBeAdded);
	//check the PCB's priority level
	//insert the PCB into the apporpriate Queue Object within the PriorityQueue's queue vector (call the queue's add method)

}

std::shared_ptr<ProcessControlBlock> PriorityQueuePCB::removePCB()
{
	auto toDequeue = PriorityQueue.begin();
	auto toReturn = toDequeue->second.deQueue();
	if(toDequeue->second.isEmpty())
	{
		PriorityQueue.erase(toDequeue);
	}
	return toReturn;

	//search linearly along the Priority queue's vector of queues.  the 1st queue that isn't empty pop off from that and return PCB
	//if doing pointers for optimization, return a shared pointer to the object

}

bool PriorityQueuePCB::isEmpty()
{
	return PriorityQueue.empty();
//go through the entire priorityQueue vector and check each queue for any PCB objects (call the queuePCB method)

}

void PriorityQueuePCB::PrintPriorityQueue()
{
	if(isEmpty())
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
	for(auto it = PriorityQueue.begin(); it != PriorityQueue.end(); it++)
	{
		//std::cout << "Priority: " << it->first << std::endl;
		it->second.printQueue();
	}
	//traverse the priority queue's vector and call the print method of each queue

}