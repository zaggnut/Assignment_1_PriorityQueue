/*
    PCB header file
    Created By: Michael Lingo
    Created On: 8/31/18
    Last Update: 9/01/18
    Last Update By: Michael Lingo

*/

#pragma once //include only once


#include <iostream>

//using an enum because its more efficient than using a string
enum class processState
{
    NEW,
    READY,
    RUNNING,
    WAITING,
    TERMINATED
};

struct ProcessControlBlock
{
    processState state; //the current state of the process
    unsigned ID;        //the ID of the process
    unsigned priority;  //the priority of the process
};

std::ostream& operator <<(std::ostream& os, processState state)
{
    switch (state)
    {
        case processState::NEW       : os << "NEW"; break;
        case processState::READY     : os << "READY"; break;
        case processState::RUNNING   : os << "RUNNING"; break;
        case processState::TERMINATED: os << "TERMINATED"; break;
        case processState::WAITING   : os << "WAITING"; break;
        default                      : os.setstate(std::ios_base::failbit);
    }
    return os;
}

std::ostream& operator <<(std::ostream& os, const ProcessControlBlock& process)
{
    os << process.ID << '\t' << process.state << '\t' << process.priority;
    return os;
}