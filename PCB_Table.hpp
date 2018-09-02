/*
    PCB Table header file
    Created By: Michael Lingo
    Created On: 8/31/18
    Last Update: 9/02/18
    Last Update By: Michael Lingo

*/
#pragma once

#include "PCB.hpp"
#include <map> //storing the table in a map
#include <utility> //for std::pair
#include <stdexcept>

//stores refrences to process control blocks

class InsertFailedException : public std::exception
{
  public:
    const char* what() const throw()
    {
      return "failed to insert, process with that ID already exits?";
    }
};

class PCB_Table
{
  protected:
    std::map<PCB_ID_TYPE,ProcessControlBlock&> ProcessMap;

  public:
    void addNewPCB(ProcessControlBlock &process); //stores a refrence to a process control block, throws exception if store unsuccessful
    ProcessControlBlock& getPCB(PCB_ID_TYPE processID); //returns a refrence to a process control block, throws exception if not found
};