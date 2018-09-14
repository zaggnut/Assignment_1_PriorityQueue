/*
Purpose: Define the class PCBqueue to be used in the PCBpriorityQueue class.
		 This class is a queue data structure using a doubly linked list in std library.
		 The content of this queue is made of ProcessControlBlock objects.
Creation Date: 9/8/2018
Created By: Shane Laskowski
Date Of Last Modifcation: 9/13/2018
Last Modification By: Michael Lingo
*/

#include "PCBqueue.hpp"
#include <iostream>
//<memory> should already be included with PCBqueue.hpp

//the PCB with identity key map value of ID will have a shared pointer to the PCB stored into the queueList of shared_ptrs.
//the shared pointer to the PCB will be stored in the back of the queue
void PCBqueue::enQueue(PCB_ID_TYPE ID)
{
	queueList.push_back(PCB_Table::getPCB(ID)); //************Not sure if this works. getPCB returns an ADDRESS of a shared_ptr
}

//removes the leading PCB shared_ptr of the queue and returns it. :::Note::: std::list pop_front() does not return anything 
std::shared_ptr<ProcessControlBlock> PCBqueue::deQueue()
{
	//return(queueList.pop_front()); pop_front does not return anything, this does not work

	std::shared_ptr<ProcessControlBlock> PCBptrToBeRemoved = queuelist.front();
	queueList.pop_front();

	return(PCBptrToBeRemoved);
}

//prints out the content of the PCB queue
void PCBqueue::printQueue()
{
	if (queueList.size() != 0)
	{
		for (std::shared_ptr<ProcessControlBlock> p = queueList.cbegin(); p != queueList.end(); p++) //try using auto instead of std::shared_ptr<ProcessControlBlock>
		{
			std::cout << "Info of a PCB in the queue" << std::endl;
			std::cout << p->ID << std::endl;
			std::cout << p->priority << std::endl;
			std::cout << p->state<< std::endl;
			std::cout << std::endl;
		}
	}
}

//prints the content of the 1st PCB object of the Queue
void PCBqueue::printLeadingPCB()
{
	if (queueList.size() != 0)
	{
		std::cout << "The Process Control Block at beginning of the Queue" << std::endl;
		std::shared_ptr<ProcessControlBlock> p = queueList.cbegin(); //creates a PCB pointer and points it at the first PCB object in the list
		std::cout << p->ID << std::endl;
		std::cout << p->priority << std::endl;
		std::cout << p->state << std::endl;

	}
	else std::cout << "The Queue is empty" << std::endl;
}

//returns true if the Queue is empty, else it returns false (not empty)
bool PCBqueue::isEmpty()
{
	return queueList.empty();
}