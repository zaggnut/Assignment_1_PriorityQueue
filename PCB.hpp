/*
    PCB header file, requires C++11
    Created By: Michael Lingo
    Created On: 8/31/18
    Last Update: 9/04/18
    Last Update By: Michael Lingo

*/

#ifndef PCB_HPP //header guards to include only once
#define PCB_HPP

#include <iostream>
#include <cstdint>
#include <memory>

typedef uint_fast32_t PCB_ID_TYPE;

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
    PCB_ID_TYPE ID;     //the ID of the process
    unsigned priority;  //the priority of the process
};

std::shared_ptr<ProcessControlBlock> createPCB(processState state, PCB_ID_TYPE ID, unsigned priority);

//converts a process state to it's string equivalent
std::ostream &operator<<(std::ostream &os, const processState state);

//converts a PCB to a string
std::ostream &operator<<(std::ostream &os, ProcessControlBlock &process);

#endif //PCB_HPP included