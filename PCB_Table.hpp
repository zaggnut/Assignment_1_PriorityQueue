/*
    PCB Table header file, requires C++11
    Created By: Michael Lingo
    Created On: 8/31/18
    Last Update: 9/04/18
    Last Update By: Michael Lingo

*/
#ifndef PCB_TABLE_HPP //header guards
#define PCB_TABLE_HPP

#include "PCB.hpp"
#include <memory>
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
  ProcessControlBlock *block;
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
  //map to hold the data
  std::unordered_map<PCB_ID_TYPE, PCBKeyStruct> ProcessMap;

  //for random number generation
  std::default_random_engine rand;

   //vector to hold all they keys, faster access for rng
  std::vector<PCB_ID_TYPE> keyVector;

public:
  //default constructor
  PCB_Table();

  //returns the number of PCBs in the Table
  unsigned long size();

  //stores a process control block, throws exception if store unsuccessful
  void addNewPCB(ProcessControlBlock *process);

  //returns a refrence to a process control block, throws exception if not found
  ProcessControlBlock *getPCB(PCB_ID_TYPE processID);

  //removes a specific PCB from the table
  ProcessControlBlock *removePCB(PCB_ID_TYPE processID);

  //removes and returns a random PCB from the table, throws an exception if there aren't any to remove
  ProcessControlBlock *removeRandomPCB();
  
  //removes and returns a random PCB from the table, throws an exception if there aren't any to remove
  void clear();
};

#endif //PCB_Table_HPP included