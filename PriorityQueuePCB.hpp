/*
Purpose: Define the class PriorityQueuePCB for ProcessControlBlock objects.
Creation Date: 9/12/2018
Created By: Shane Laskowski
Date Of Last Modifcation: 9/12/2018
Last Modification By:  Shane Laskowski
*/

#ifndef PriorityQueuePCB
#define PriorityQueuePCB

#include "PCBqueue.hpp"
#include "PCB.hpp"


class PriorityQueuePCB
{
protected:

	//vector of PCB queue objects.  Each queue should represent a set of PCBs with same priority level.
	//This vector is declared, but has no PCB queue objects (its empty), should have a custom made construcutor to initialize it properly.
	vector<PCBqueue> PriorityQueue; //perhaps use a tree and not a vector ?

public:

	~PriorityQueuePCB(); //a deconstructor that does... Nothing !
	PriorityQueuePCB(); //a constructor that does...... NOTHING !
	PriorityQueuePCB(int TotalPriorityLevels); // a constructor that takes an argument that will expand the memeory occupied by the empty PriorityQueue vector
											   // this helps keep the vector from constantly copying and placing its content in new memory spaces for each size change
	
	void addPCB(PCB_ID_TYPE ID); //adds a PCB shared ptr to the PriorityQueue (vector) based on the ID number of the specific PCB
	std::shared_ptr<ProcessControlBlock> removePCB();  //removes a PCB shared ptr from the priority queue and returns it
	bool isEmpty();
	void PrintPriorityQueue();
};

#endif //PriorityQueuePCB