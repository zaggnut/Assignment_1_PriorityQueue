/*
    PCB Table header file
    Created By: Michael Lingo
    Created On: 8/31/18
    Last Update: 9/01/18
    Last Update By: Michael Lingo

*/
#pragma once

#include "PCB.hpp"
#include <vector> //storing the table in a vector for now

class PCB_Table
{
  protected:
    std::vector<ProcessControlBlock> Processes;

  public:
    PCB_Table();
    bool addNewPCB(const ProcessControlBlock &process);
    ProcessControlBlock getPCB(unsigned processID);
};