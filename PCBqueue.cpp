/*
Purpose: Define the class PCBqueue to be used in the PCBpriorityQueue class.
		 This class is a queue data structure using a doubly linked list in std library.
		 The content of this queue is made of ProcessControlBlock objects.
Creation Date: 9/8/2018
Created By: Shane Laskowski
Date Of Last Modifcation: 9/16/2018
Last Modification By: Michael Lingo
*/


#include "PCBqueue.hpp"

//puts the PCB object at the rear of the Queue
void PCBqueue::enQueue(ProcessControlBlock* PCBtoBeAdded)
{
	queueList.push_back(PCBtoBeAdded); // adds the PCB object to the rear
}

//removes the PCB object that is at the front of the Queue and returns it
ProcessControlBlock* PCBqueue::deQueue()
{
	auto toRet = queueList.front();
	queueList.pop_front(); //pops the PCB object from the front and returns it
	return toRet;

}

ProcessControlBlock* PCBqueue::peek()
{
	return queueList.front();
}

//prints out the content of the PCB queue
void PCBqueue::printQueue() const
{
	if (queueList.size() != 0)
	{
		//std::cout << "Process Control Blocks of the Queue" << std::endl;

		//pointer p of PCB objects traverses through the List and the beginning until it reaches the end
		//each PCB object in the List is printed
		for (auto p = queueList.cbegin(); p != queueList.end(); p++)
		{
			std::cout << **p << std::endl; //the PCB object pointed to by p is printed
		}
	}
}

//prints the content of the 1st PCB object of the Queue
void PCBqueue::printLeadingPCB()
{
	if (queueList.size() != 0)
	{
		std::cout << "The Process Control Block at beginning of the Queue" << std::endl;
		auto p = queueList.cbegin(); //creates a PCB pointer and points it at the first PCB object in the list
		std::cout << *p << std::endl; //prints the PCB object
	}
	else std::cout << "The Queue is empty" << std::endl;
}

//returns true if the Queue is empty, else it returns false (not empty)
bool PCBqueue::isEmpty()
{
	/*if (queueList.size() == 0)
		return(true);
	else return(false);*/
	return queueList.empty();
}