/*
    PCB header file, requires C++14
    Created By: Michael Lingo
    Created On: 8/31/18
    Last Update: 9/15/18
    Last Update By: Michael Lingo

*/

#ifndef __GNUG__
#error "requires g++"
#endif

#ifndef PCB_HPP //header guards to include only once
#define PCB_HPP

#include <iostream>
#include <cstdint>
#include <memory>
#include <ext/bitmap_allocator.h> //uses a custom allocator in the gcc for better allocation efficiency
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
class ProcessControlBlock
{
  protected:
    static __gnu_cxx::bitmap_allocator<ProcessControlBlock> allocator;

  public:
    //the current state of the process
    processState state;

    //the ID of the process
    const PCB_ID_TYPE ID;

    //the priority of the process
    unsigned priority;

    //constructor allows for runtime initialization of a constant value
    ProcessControlBlock(processState state_, PCB_ID_TYPE ID_, unsigned priority_) : ID(ID_)
    {
        state = state_;
        priority = priority_;
    }

    static void *operator new(std::size_t size)
    {
        return allocator._M_allocate_single_object();
    }
    static void operator delete(void *block)
    {
        allocator._M_deallocate_single_object((ProcessControlBlock *)block);
    }
};

std::shared_ptr<ProcessControlBlock> createPCB(processState state, PCB_ID_TYPE ID, unsigned priority);

//converts a process state to it's string equivalent
std::ostream &operator<<(std::ostream &os, const processState state);

//converts a PCB to a string
std::ostream &operator<<(std::ostream &os, const ProcessControlBlock &process);

#endif //PCB_HPP included