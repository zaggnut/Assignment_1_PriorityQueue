/*
Purpose: Define the class PriorityQueuePCB for ProcessControlBlock objects.
Creation Date: 9/12/2018
Created By: Shane Laskowski
Date Of Last Modifcation: 9/12/2018
Last Modification By:  Shane Laskowski
*/

#ifndef PriorityQueuePCB
#define PriorityQueuePCB

#include <map>
#include "PCBqueue.hpp"
#include "PCB.hpp"


class PQisEmpty {};  //a dummy class to be thrown for exception handling purposes.


class PriorityQueuePCB
{
protected:

	
	std::map<int, PCBqueue> PriorityQueue; //the key of the map is for priority level, the mapped value is a PCBqueue object 
	int PCBptrCount; //used to count number of PCB items are stored in the priorityqueue.  usefull in its Size() and isEmpty() function

public:

	~PriorityQueuePCB();
	PriorityQueuePCB();
	
	void addPCB(PCB_ID_TYPE ID); //adds a PCB shared ptr to the PriorityQueue (vector) based on the ID number of the specific PCB
	std::shared_ptr<ProcessControlBlock> removePCB();  //removes a PCB shared ptr from the priority queue and returns it
	bool isEmpty();  //uses PCBptrCount to determine if priority queue is empty
	void PrintPriorityQueue();
	int Size(); //returns the amount of PCB items inside this priority queue. (returns PCBptrCount)
};

#endif //PriorityQueuePCB