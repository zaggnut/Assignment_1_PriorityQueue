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
#include <memory>

#include "PCB.hpp"

//make the list a list of shared pointers of PCB_table objects

class PCBqueue
{
  protected:
	std::list<std::shared_ptr<ProcessControlBlock> > queueList; //doubly linked list of std library, holds shared_ptrs to PCBs objects held in PCBtable
  public:

	//the PCB with identity key map value of ID will have a shared pointer to the PCB stored into the queueList of shared_ptrs
	void enQueue(PCB_ID_TYPE ID); 

	std::shared_ptr<ProcessControlBlock> deQueue();	//removes the leading shared_ptr of a PCB in the front of the queue and returns the shared_ptr
	void printQueue();	//prints out all PCB objects of the queue
	void printLeadingPCB();	//prints out the PCB object in the front of the queue
	bool isEmpty();	//returns true if the queue is empty, else returns false
};

#endif //PCBqueue.hpp