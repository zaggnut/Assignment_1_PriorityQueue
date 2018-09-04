/*
    PCB header file, requires C++11
    Created By: Michael Lingo
    Created On: 9/04/18
    Last Update: 9/04/18
    Last Update By: Michael Lingo

*/

#include "PCB.hpp"
#include <memory>

//PCB factory
std::shared_ptr<ProcessControlBlock> createPCB(processState state, PCB_ID_TYPE ID, unsigned priority)
{
    std::shared_ptr<ProcessControlBlock> block(new ProcessControlBlock{state, ID, priority});
    return block;
}

//to string for process states
std::ostream &operator<<(std::ostream &os, const processState state)
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
std::ostream &operator<<(std::ostream &os, ProcessControlBlock &process)
{
    os << std::right; //align right
    os.width(6);
    os << process.ID;
    os.width(12);
    os << process.state;
    os.width(6);
    os << process.priority;
    return os;
}