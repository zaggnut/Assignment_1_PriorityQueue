/*
Purpose: Define the class PCBqueue to be used in the PCBpriorityQueue class. 
		 This class is a queue data structure using a doubly linked list in std library.
		 The content of this queue is made of ProcessControlBlock objects.
Creation Date: 9/8/2018
Created By: Shane Laskowski
Date Of Last Modifcation: 9/13/2018
Last Modification By: Michael Lingo
*/
#ifndef PCBqueue_HPP
#define PCBqueue_HPP

#include <list>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ext/bitmap_allocator.h>
#include <memory>


#include "PCB.hpp"

class PCBqueue
{
  protected:
	std::list<std::shared_ptr<ProcessControlBlock>, __gnu_cxx::bitmap_allocator<std::shared_ptr<ProcessControlBlock>>> queueList; //doubly linked list in std library, used to hold PCB objects in an ordered fashion
  public:
	void enQueue(std::shared_ptr<ProcessControlBlock> PCBtoBeAdded); //adds the PCB object to rear of the queue
	std::shared_ptr<ProcessControlBlock> peek();							//look at the front without removing
	std::shared_ptr<ProcessControlBlock> deQueue();					//removes the PCB object from the front of the queue
	void printQueue() const;								//prints out all PCB objects of the queue
	void printLeadingPCB();							//prints out the PCB object in the front of the queue
	bool isEmpty();									//returns true if the queue is empty, else returns false
};

#endif //PCBqueue.hpp