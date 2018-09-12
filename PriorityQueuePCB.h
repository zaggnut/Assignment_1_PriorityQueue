/*
Purpose: Define the class PriorityQueuePCB for ProcessControlBlock objects.
Creation Date: 9/12/2018
Created By: Shane Laskowski
Date Of Last Modifcation: 9/12/2018
Last Modification By:  Shane Laskowski
*/

#ifndef PriorityQueuePCB
#define PriorityQueuePCB

#include <vector>
#include <iostream>
using namespace std;

#include "PCBqueue.hpp"
#include "PCB.hpp"

class PriorityQueuePCB
{
protected:

	//vector of PCB queue objects.  Each queue should represent a set of PCBs with same priority level.
	//This vector is declared, but has no PCB queue objects (its empty), should have a custom made construcutor to initialize it properly.
	vector<PCBqueue> PriorityQueue; 

public:

	~PriorityQueuePCB();
	PriorityQueuePCB();
	PriorityQueuePCB(int TotalPriorityLevels);

	void addPCB(ProcessControlBlock PCBtoBeAdded);
	ProcessControlBlock removePCB();
	bool isEmpty();
	void PrintPriorityQueue();

};

#endif //PriorityQueuePCB