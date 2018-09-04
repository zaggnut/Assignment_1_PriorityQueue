/*
    PCB Table header file
    Created By: Michael Lingo
    Created On: 8/31/18
    Last Update: 9/03/18
    Last Update By: Michael Lingo

*/
#pragma once //include only once

#include "PCB.hpp"
#include <unordered_map> //storing the table in an unordered map
#include <vector>        //storing all the keys in a vector improves getting a random process
#include <utility>       //for std::pair
#include <stdexcept>
#include <random>
#include <chrono>

//stores refrences to process control blocks

struct PCBKeyStruct //a helper struct to allow removing the key from the key vector easier
{
  unsigned long processVectorIndex;
  ProcessControlBlock &block;
};

class InsertFailedException : public std::exception
{
public:
  const char *what() const throw()
  {
    return "failed to insert, process with that ID already exits?";
  }
};

class ProcessNotFoundException : public std::exception
{
public:
  const char *what() const throw()
  {
    return "A process control block with that ID was not found";
  }
};

class PCB_Table
{
protected:
  std::unordered_map<PCB_ID_TYPE, PCBKeyStruct> ProcessMap;
  std::default_random_engine rand;
  std::vector<PCB_ID_TYPE> keyVector;

public:
  PCB_Table();
  void addNewPCB(ProcessControlBlock &process);          //stores a refrence to a process control block, throws exception if store unsuccessful
  ProcessControlBlock &getPCB(PCB_ID_TYPE processID);    //returns a refrence to a process control block, throws exception if not found
  ProcessControlBlock &removePCB(PCB_ID_TYPE processID); //removes a specific PCB from the table
  ProcessControlBlock &removeRandomPCB();                //removes and returns a random PCB from the table, throws an exception if there aren't any to return
  void clear();                                          //empties the table
};