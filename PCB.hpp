/*
    PCB header file
    Created By: Michael Lingo
    Created On: 8/31/18
    Last Update: 9/02/18
    Last Update By: Michael Lingo

*/

#pragma once //include only once

#include <iostream>
#include <cstdint>

#define PCB_ID_TYPE uint_fast32_t

//each possible valid processs state type
enum class processState
{
    NEW,
    READY,
    RUNNING,
    WAITING,
    TERMINATED
};

//struct to hold each PCB
struct ProcessControlBlock
{
    processState state; //the current state of the process
    PCB_ID_TYPE ID;        //the ID of the process
    unsigned priority;  //the priority of the process
};

//converts a process state to it's string equivalent
std::ostream &operator<<(std::ostream &os, processState state)
{
    switch (state)
    {
    case processState::NEW:
        os << "NEW";
        break;
    case processState::READY:
        os << "READY";
        break;
    case processState::RUNNING:
        os << "RUNNING";
        break;
    case processState::WAITING:
        os << "WAITING";
        break;
    case processState::TERMINATED:
        os << "TERMINATED";
        break;
    default:
        os.setstate(std::ios_base::failbit); //invalid state type
    }
    return os;
}

//converts a PCB to a string
std::ostream &operator<<(std::ostream &os, const ProcessControlBlock &process)
{
    os << process.ID << '\t' << process.state << '\t' << process.priority;
    return os;
}