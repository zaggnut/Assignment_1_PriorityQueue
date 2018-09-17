/*
Purpose: Define the class PriorityQueuePCB for ProcessControlBlock objects.
Creation Date: 9/12/2018
Created By: Shane Laskowski
Date Of Last Modifcation: 9/16/2018
Last Modification By: Michael Lingo
*/

#ifndef PriorityQueuePCB_HPP
#define PriorityQueuePCB_HPP

#include "PCB.hpp"
#include <iostream>
#include <map>
#include <memory>
#include <ext/bitmap_allocator.h> //uses a custom allocator in the gcc for better allocation efficiency
#include "PCBqueue.hpp"


class PriorityQueuePCB
{
  protected:
	std::map<unsigned, PCBqueue, std::less<unsigned>,
			 __gnu_cxx::bitmap_allocator<std::pair<unsigned, PCBqueue>>>
		PriorityQueue;
	std::map<unsigned, PCBqueue,std::less<unsigned>,
			 __gnu_cxx::bitmap_allocator<std::pair<unsigned, PCBqueue>>
			 >::iterator highest;

  public:
	PriorityQueuePCB();
	void addPCB(ProcessControlBlock* PCBtoBeAdded);
	ProcessControlBlock* removePCB();
	bool isEmpty();
	void PrintPriorityQueue();
};

#endif //PriorityQueuePCB_HPP