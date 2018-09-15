/*
Purpose: Define the class PriorityQueuePCB for ProcessControlBlock objects.
Creation Date: 9/12/2018
Created By: Shane Laskowski
Date Of Last Modifcation: 9/13/2018
Last Modification By: Michael Lingo
*/

#ifndef PriorityQueuePCB_HPP
#define PriorityQueuePCB_HPP

#include <iostream>
#include <map>
#include <memory>
#include "PCBqueue.hpp"
#include "PCB.hpp"

class PriorityQueuePCB
{
  protected:
	//vector of PCB queue objects.  Each queue should represent a set of PCBs with same priority level.
	//This vector is declared, but has no PCB queue objects (its empty), should have a custom made construcutor to initialize it properly.
	std::map<unsigned, PCBqueue> PriorityQueue;
	//maybe this should be a std::map from <map>?
	//std::map<unsigned, PCBqueue> PriorityQueue

  public:

	void addPCB(std::shared_ptr<ProcessControlBlock> PCBtoBeAdded);
	std::shared_ptr<ProcessControlBlock> removePCB();
	bool isEmpty();
	void PrintPriorityQueue();
};

#endif //PriorityQueuePCB_HPP