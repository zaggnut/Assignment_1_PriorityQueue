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
	std::map<unsigned, PCBqueue> PriorityQueue;
  public:

	void addPCB(std::shared_ptr<ProcessControlBlock> PCBtoBeAdded);
	std::shared_ptr<ProcessControlBlock> removePCB();
	bool isEmpty();
	void PrintPriorityQueue();
};

#endif //PriorityQueuePCB_HPP