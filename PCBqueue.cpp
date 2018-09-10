/*
Purpose: Define the class PCBqueue to be used in the PCBpriorityQueue class.
		 This class is a queue data structure using a doubly linked list in std library.
		 The content of this queue is made of ProcessControlBlock objects.
Creation Date: 9/8/2018
Created By: Shane Laskowski
Date Of Last Modifcation: 9/8/2018
Last Modification By: Shane Laskowski
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//puts the PCB object at the rear of the Queue
void PCBqueue::enQueue(ProcessControlBlock PCBtoBeAdded)
{
	queueList.push_back(PCBtoBeAdded); // adds the PCB object to the rear
}

//removes the PCB object that is at the front of the Queue and returns it
ProcessControlBlock PCBqueue::deQueue()
{
	return (queueList.pop_front()); //pops the PCB object from the front and returns it
}

//prints out the content of the PCB queue
void PCBqueue::printQueue()
{
	cout << "Process Control Blocks of the Queue" << endl;

	//pointer p of PCB objects traverses through the List and the beginning until it reaches the end
	//each PCB object in the List is printed
	for (list<ProcessControlBlock>::iterator p = queueList.begin(); p != queueList.end(); p++)
	{
		cout << *p << endl; //the PCB object pointed to by p is printed
	}
}

//prints the content of the 1st PCB object of the Queue
//****NEED TO HANDLE EMPTY QUEUE (check if pointer p is at the end of the list with .end() list function)
void PCBqueue::printLeadingPCB()
{
	cout << "The Process Control Block at beginning of the Queue" << endl;

	list<ProcessControlBlock>::iterator p = queueList.begin(); //creates a PCB pointer and points it at the first PCB object in the list
	cout << *p << endl; //prints the PCB object
}

//returns true if the Queue is empty, else it returns false (not empty)
bool PCBqueue::isEmpty()
{
	if (queueList.size() == 0)
		return(true);
	else return(false);
}
